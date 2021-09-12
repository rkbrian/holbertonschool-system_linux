BITS 64
	global asm_strncasecmp		; export for external files
	SECTION .text			; this section stores code
asm_strncasecmp:	; setup & variables init
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-8], rdi	; copy given str1 ptr dest to local rbp
	mov	QWORD [rbp-16], rsi	; copy given str2 ptr dest to local rbp
	mov	DWORD [rbp-20], edx	; copy given range integer
.s1null:		; if str1 is null
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	test	al, al			; find out if str1 is null
	jne	.s2null			; if not null byte, check str2 null string
	mov	rax, QWORD [rbp-16]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	al, 64			; compare char diff for case
	jle	.ret_02			; if not upper case, return 0 - str2
	mov	rax, QWORD [rbp-16]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	al, 90			; compare char diff for case
	jg	.ret_02			; if not upper case, return 0 - str2
	mov	rax, QWORD [rbp-16]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	movsx	edx, al			; signed int for calc
	mov	eax, -32		; lower case int
	sub	eax, edx		; return 0 - str2 - 32
	jmp	.allisdone		; go to the end
.ret_02:		; return 0 - str2
	mov	rax, QWORD [rbp-16]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	movsx	eax, al			; signed int for calc
	neg	eax			; return 0 - str2
	jmp	.allisdone		; go to the end
.s2null:		; if str2 is null
	mov	rax, QWORD [rbp-16]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	test	al, al			; find out if str1 is null
	jne	.char_diff		; if not null byte, go to char comparison loop
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	cmp	al, 64			; compare char diff for case
	jle	.ret_10			; if not upper case, return str1
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	cmp	al, 90			; compare char diff for case
	jg	.ret_10			; if not upper case, return str1
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	movsx	eax, al			; signed int for calc
	add	eax, 32			; return 32 + str1
	jmp	.allisdone		; go to the end
.ret_10:		; return str1
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	movsx	eax, al			; signed int for calc
	jmp	.allisdone		; go to the end
.s1big:			; while loop to search char difference, str1 lower case
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	movsx	edx, al			; signed int for calc
	mov	rax, QWORD [rbp-16]	; str2 comes in
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	movsx	ecx, al			; signed int for calc
	mov	eax, edx		; value loaded for calc
	sub	eax, ecx		; str1 char - str2 char
	cmp	eax, 32			; compare char diff for case
	jne	.s2big			; diff != 32, jump to str++
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	cmp	eax, 96			; compare char diff for case
	jle	.s2big			; str1 > 96, jump to str++
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	cmp	eax, 122		; compare char diff for case
	jg	.s2big			; str1 <= 122, jump to str++
	jmp	.incs			; str++
.s2big:			; while loop to search char difference, str2 lower case
	mov	rax, QWORD [rbp-16]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	movsx	edx, al			; signed int for calc
	mov	rax, QWORD [rbp-8]	; str1 comes in
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	movsx	ecx, al			; signed int for calc
	mov	eax, edx		; value loaded for calc
	sub	eax, ecx		; str2 char - str1 char
	cmp	eax, 32			; compare char diff for case
	jne	.loop_start		; diff != 32, jump to str++
	mov	rax, QWORD [rbp-16]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	eax, 96			; compare char diff for case
	jle	.loop_start		; str2 > 96, jump to str++
	mov	rax, QWORD [rbp-16]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	eax, 122		; compare char diff for case
	jg	.loop_start		; str2 <= 122, jump to str++
	jmp	.incs			; str++
.loop_start:		; the if statement in the loop, jump out for diff of 2 strs
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	edx, BYTE [rax]		; str1 byte qword ptr to get the char
	mov	rax, QWORD [rbp-16]	; str2 comes in
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	dl, al			; comparison between str1 and str2 chars
	jne	.ret_diff		; if greater, return ascii diff of chars
.incs:			; next chars
	inc	DWORD [rbp-8]		; str1 index increment for next char
	inc	DWORD [rbp-16]		; str2 index increment for next char
	dec	DWORD [rbp-20]		; range integer decrement
.char_diff:		; while loop to search char difference
	cmp	DWORD [rbp-20], 0	; int length check
	je	.ret_zzz		; if n = 0, return ascii diff of chars
	jmp	.s1big			; if all not equal to 0, loop
.ret_diff:		; return the string askii difference 1
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	movsx	edx, al			; signed int for calc
	mov	rax, QWORD [rbp-16]	; str2 comes in
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	movsx	ecx, al			; signed int for calc
	mov	eax, edx		; str1 char
	sub	eax, ecx		; return str1 - str2
	jmp	.allisdone		; go to the end
.ret_zzz:		; return 0
	mov	eax, 0			; return 0
.allisdone:		; end the function
	pop	rbp			; end the function
	ret

BITS 64
	global asm_strcasecmp	; export for external files
	SECTION .text		; this section stores code
asm_strcasecmp:		; setup & variables init
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-24], rdi	; copy given str1 ptr dest to local rbp
	mov	QWORD [rbp-32], rsi	; copy given str2 ptr dest to local rbp
	jmp	.char_diff		; char comparison loop
.int_lows:		; int buffers to save str1 and str2 char values
	mov	rax, QWORD [rbp-24]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	movsx	edx, al			; signed int for calc
	mov	DWORD [rbp-4], eax	; int low1 = *str1
	mov	rax, QWORD [rbp-32]	; str2 comes in
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	movsx	eax, al			; signed int for calc
	mov	DWORD [rbp-8], eax	; int low2 = *str2
.lowers1:		; while loop to search char difference, str2 upper case
	mov	rax, QWORD [rbp-24]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	cmp	eax, 65			; compare char diff for upper case
	jle	.lowers2		; str1 <= 65, check str2
	mov	rax, QWORD [rbp-24]	; str1 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str1 byte qword ptr to get the char
	cmp	eax, 90			; compare char diff for upper case
	jg	.lowers2		; str1 > 90, check str2
	add	DWORD [rbp-4], 32	; low1 = low1 + 32
.lowers2:		; while loop to search char difference, str2 lower case
	mov	rax, QWORD [rbp-32]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	eax, 65			; compare char diff for upper case
	jle	.check_diff		; str2 <= 65, ready to check difference
	mov	rax, QWORD [rbp-24]	; str2 saved to the top regular gpr
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	eax, 90			; compare char diff for upper case
	jg	.check_diff		; str2 > 90, ready to check difference
	add	DWORD [rbp-8], 32	; low2 = low2 + 32
.check_diff:		; if statement to check char difference
	mov	eax, DWORD [rbp-4] 	; load low1
	cmp	eax, DWORD [rbp-8]	; compare with low2
	je	.incs			; if equal, next chars
	mov	eax, DWORD [rbp-4]	; load low1 to return position
	sub	eax, DWORD [rbp-8]	; low1 - low2
	jmp	.allisdone		; return result and go to the end
.incs:			; next chars
	inc	DWORD [rbp-24]		; str1 index increment for next char
	inc	DWORD [rbp-32]		; str2 index increment for next char
.char_diff:		; while loop to search char difference
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	edx, BYTE [rax]		; str1 byte qword ptr to get the char
	test	dl, dl			; str1 null byte check
	je	.ret_zzz		; if null byte, return 0
	jmp	.int_lows		; if all not equal to null byte, loop
.ret_zzz:		; return 0
	mov	eax, 0			; return 0
.allisdone:		; end the function
	pop	rbp			; end the function
	ret

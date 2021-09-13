BITS 64
	global asm_strpbrk	; export for external files
	SECTION .text		; this section stores code
asm_strpbrk:		; setup & variables init
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-24], rdi	; copy given str s ptr dest to local rbp
	mov	QWORD [rbp-32], rsi 	; copy given str accept ptr dest to local rbp
.ifs1_null:		; check if s or accept is null string
	mov	rax, QWORD [rbp-24] 	; s saved to the top regular gpr
	movzx	eax, BYTE [rax]		; s byte qword ptr to get the char
	test	al, al			; checking null termination
	je	.ret_zzz		; if s[j] equal to null byte, return 0
	mov	rax, QWORD [rbp-32] 	; accept saved to the top regular gpr
	movzx	eax, BYTE [rax]		; accept byte qword ptr to get the char
	test	al, al
	je	.ret_zzz		; if accept[i] equal to null byte, return 0
	mov	DWORD [rbp-8], 0	; init int j = 0
	jmp	.outer_loop		; outer loop start
.inner_start:		; nested loop start
	mov	DWORD [rbp-4], 0	; init int i = 0
	jmp	.inner_loop		; outer loop start
.find_char:		; setup & variables init
	mov	edx, DWORD [rbp-4]	; i saved to the top regular gpr
	mov	rax, QWORD [rbp-32]	; accept saved to the top regular gpr
	add	rax, rdx		; scan each element when index increases
	movzx	edx, BYTE [rax]		; byte dword ptr to get the char from str
	mov	ecx, DWORD [rbp-8]	; j saved to the top regular gpr
	mov	rax, QWORD [rbp-24]	; s saved to the top regular gpr
	add	rax, rcx
	movzx	eax, BYTE [rax]
	cmp	dl, al			; compare s[j] with accept[i]
	je	.ret_null		; if s[j] = accept[i], check return value
	inc	DWORD [rbp-4]		; i++
.inner_loop:		; nested loop for next accept char
	mov	edx, DWORD [rbp-4]	; i saved to the top regular gpr
	mov	rax, QWORD [rbp-32]	; accept saved to the top regular gpr
	add	rax, rdx
	movzx	eax, BYTE [rax]
	test	al, al			; checking accept[i] null termination
	jne	.find_char		; if not null byte, run inner loop again
	inc	DWORD [rbp-8]		; go to the outer loop, j++
.outer_loop:		; outer loop for next s char
	mov	edx, DWORD [rbp-8]	; j saved to the top regular gpr
	mov	rax, QWORD [rbp-24]	; s saved to the top regular gpr
	add	rax, rdx
	movzx	eax, BYTE [rax]
	test	al, al			; checking s[j] null termination
	jne	.inner_start		; if not null byte, run outer loop again
.ret_null:		; if statement for return value
	mov	edx, DWORD [rbp-8] 	; j saved to the top regular gpr
	mov	rax, QWORD [rbp-24]	; s saved to the top regular gpr
	add	rax, rdx		; scan each element when index increases
	movzx	eax, BYTE [rax]		; byte dword ptr to get the char from str
	test	al, al			; checking null termination
	jne	.ret_charptr		; if not null byte, return pointer to the char
.ret_zzz:		; return zero for null string/byte
	mov	eax, 0			; return 0
	jmp	.all_finished		; go to end the function
.ret_charptr:			; return ptr to the first found char
	mov	edx, DWORD [rbp-8] 	; j saved to the top regular gpr
	mov	rax, QWORD [rbp-24]	; s saved to the top regular gpr
	add	rax, rdx		; return &s[j]
.all_finished:			; end the function
	pop	rbp
	ret

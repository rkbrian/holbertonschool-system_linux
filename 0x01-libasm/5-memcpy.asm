BITS 64
	global asm_memcpy	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_memcpy:
	push	rbp 			; push rbp register to stack
	mov	rbp, rsp		; move rsp register content to rbp register
	mov	QWORD [rbp-16], rdi	; copy dest string to local rbp
	mov	QWORD [rbp-24], rsi	; copy src string to local rbp
	mov	DWORD [rbp-28], edx	; copy int n to local rbp
	mov	DWORD [rbp-4], 0	; initialize index, null terminator if unused
	jmp	.L2
.L3:	; loop content
	mov	edx, DWORD [rbp-4]	; load index
	mov	rax, QWORD [rbp-24]	; load src str
	add	rax, rdx		; scan src char when index increases
	mov	ecx, DWORD [rbp-4]	; load index again for dest str
	mov	rdx, QWORD [rbp-16]	; load dest str
	add	rdx, rcx		; scan dest char when index increases
	movzx	eax, BYTE DWORD [rax]	; byte dword src ptr to get the char
	mov	BYTE [rdx], al		; save copy of src char into dest address 
	inc	DWORD [rbp-4]		; increment of 1 in the loop
.L2:	; loop limit and return
	mov	eax, DWORD [rbp-4]	; load index
	cmp	eax, QWORD [rbp-28]	; compare index with limit n
	jb	.L3	 		; if index is below n, loop
	mov	rax, QWORD [rbp-16]	; return mem-copied dest
	pop	rbp	; end the function
	ret

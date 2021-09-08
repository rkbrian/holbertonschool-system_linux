BITS 64
	global asm_memcpy	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_memcpy:
	push	rbp 			; push rbp register to stack
	mov	rbp, rsp		; move rsp register content to rbp register
	mov	QWORD [rbp-8], rdi	; copy dest string to local rbp
	mov	QWORD [rbp-16], rsi	; copy src string to local rbp
	mov	DWORD [rbp-20], edx	; copy int n to local rbp
	jmp	.L2
.L3:	; loop content
	mov	rax, QWORD [rbp-16]	; load src str
	movzx	edx, BYTE DWORD [rax]	; byte dword src ptr to get the char
	
	mov	rax, QWORD [rbp-8]	; load dest str, prepare to overwrite char
	mov	BYTE [rax], dl		; save copy of src char into dest address
	mov	BYTE [rbp-8], al		; work?
	
	inc	QWORD [rbp-16]		; move ptr to next char in src
	inc	QWORD [rbp-8]		; move ptr to next char in dest
	dec	DWORD [rbp-20]		; range decrement
.L2:	; loop limit and return
	cmp	QWORD [rbp-20], 0	; compare index with 0
	jne	.L3	 		; if n > 0, loop
	nop				; break
	pop	rbp	; end the function
	ret

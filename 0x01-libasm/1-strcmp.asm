BITS 64
	global asm_strcmp	; export for external files
	extern main	; import main file
	SECTION .text	; this section stores code
asm_strcmp:
	push	rbp
	mov	rbp, rsp	; function start
	mov	QWORD [rbp-24], rdi	; copy given str ptr1 dest to local rbp 24
	mov	QWORD [rbp-32], rsi	; copy given str ptr2 dest to local rbp 24

	
	mov	DWORD [rbp-4], 0	; initialize start number with 0
	jmp	.L2
.L3:
	inc	DWORD [rbp-4]	; increment of 1, in the loop condition
.L2:
	mov	edx, DWORD [rbp-4]	; int 0 saved to the top regular gpr
	mov	rax, QWORD [rbp-24]	; what is this
	add	rax, rdx	; what is this
	movzx	eax, BYTE DWORD [rax]	; what is this
	test	al, al	; compare with null byte
	jne	.L3	; call L3 for not equal to null byte
	jmp	.L4	; exit loop
.L4:
	mov	eax, DWORD [rbp-4]	; loop finished, add 1 for the last byte
	pop	rbp
	ret
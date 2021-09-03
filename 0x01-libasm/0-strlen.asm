BITS 64
	global asm_strlen	; export for external files
	extern main	; import main file
	SECTION .text	; this section stores code
asm_strlen:
	push	rbp ; push rbp register to stack
	mov	rbp, rsp	; move rsp register content to rbp register 
	mov	QWORD PTR [rbp-24], rdi	; copy given str ptr dest to local rbp 24
	mov	DWORD PTR [rbp-4], 0	; initialize start number with 0
	jmp	.L2
.L3:
	inc	DWORD PTR [rbp-4]	; increment of 1, in the loop condition
.L2:
	mov	edx, DWORD PTR [rbp-4]	; int 0 saved to the top regular gpr
	mov	rax, QWORD PTR [rbp-24]	; what is this
	add	rax, rdx	; what is this
	movzx	eax, BYTE DWORD PTR [rax]	; what is this
	test	al, al	; compare with null byte
	jne	.L3	; call L3 for not equal to null byte
	jmp	.L4	; exit loop
.L4
	mov	eax, DWORD PTR [rbp-4]	; loop finished, add 1 for the last byte
	pop	rbp
	ret

BITS 64
	global asm_strlen	; export for external files
	extern main	; import main file
	SECTION .text	; this section stores code
asm_strlen:
	push	rbp ; push rbp register to stack
	mov	rbp, rsp	; move rsp register content to rbp register 
	mov	QWORD [rbp-24], rdi	; copy given str ptr dest to local rbp 24
	mov	DWORD [rbp-4], 0	; initialize index, null terminator if unused
	jmp	.L2
.L3:
	inc	DWORD [rbp-4]	; increment of 1, in the loop condition
.L2:
	mov	edx, DWORD [rbp-4]	; index number saved to the top regular gpr
	mov	rax, QWORD [rbp-24]	; str comes in
	add	rax, rdx	; null byte comes after
	movzx	eax, BYTE DWORD [rax]	; get the byte size of str ptr
	test	al, al	; compare with null byte in rax
	jne	.L3	; call L3 for not equal to null byte
	jmp	.L4	; call L4 for case meet, exit loop
.L4:
	mov	eax, DWORD [rbp-4]	; loop finished, add 1 for the last byte
	pop	rbp	; end the function
	ret

BITS 64
	global asm_strcmp	; export for external files
	extern main	; import main file
	SECTION .text	; this section stores code
asm_strcmp:
	push	rbp
	mov	rbp, rsp	; function start
	mov	QWORD [rbp-24], rdi	; copy given str ptr1 dest to local rbp 24
	mov	QWORD [rbp-32], rsi	; copy given str ptr2 dest to local rbp 32
	mov	DWORD [rbp-4], 0	; init 1st index, null terminator if unused
	jmp	.L2	; str1 length counting loop
.L3:
	inc	DWORD [rbp-4]	; 1st index increment of 1 in the loop
.L2:
	mov	eax, DWORD [rbp-4]	; 1st index saved to the top regular gpr
	movsx	rdx, eax	; signed-extand counter
	mov	rax, QWORD [rbp-24]	; str1 comes in
	add	rax, rdx	; null byte comes after
	movzx	eax, BYTE DWORD [rax]	; get the byte size of str ptr
	test	al, al	; compare with null byte
	jne	.L3	; call L3 for not equal to null byte
	mov	DWORD [rbp-8], 0	; for case meet, init 2nd index
	jmp	.L4	; call L4 to next loop
.L5:
	inc	DWORD [rbp-8]	; 2nd index increment of 1
.L4:
	mov	eax, DWORD [rbp-8]	; 2nd index saved to the top regular gpr
	movsx	rdx, eax	; signed-extand counter
	mov	rax, QWORD [rbp-32]	; str2 comes in
	add	rax, rdx	; null byte comes after
	movzx	eax, BYTE DWORD [rax]	; get the byte size of str ptr
	test	al, al	; compare with null byte
	jne	.L5	; call L5 for not equal to null byte
	mov	eax, DWORD [rbp-4]	; pull byte size saved in rbp-8
	cmp	eax, DWORD [rbp-8]	; commpare with data saved in rbp-12
	je	.L6	; if lengths are equal, do the char comparison
	mov	eax, DWORD [rbp-4]	; do the comparison again for rbp-8 & -12
	cmp	eax, DWORD [rbp-8]
	jne	.L7	; if lengths aren't equal, return the diff in L7
.L6:
	mov	DWORD [rbp-12], 0	; init 3rd index
	jmp	.L8	; call L4 to next loop

.L10

.L9:
	inc	DWORD [rbp-12]	; 3rd index increment
.L8:
	mov	eax, DWORD [rbp-12]	; 3rd index saved to the top regular gpr
	movsx	rdx, eax	; signed-extand counter
	mov	rax, QWORD [rbp-24]	; str comes in
.L7:
	pop	rbp
	ret
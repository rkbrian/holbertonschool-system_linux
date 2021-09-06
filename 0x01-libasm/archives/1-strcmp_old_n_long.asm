BITS 64
	global asm_strcmp	; export for external files
	extern main	; import main file
	SECTION .text	; this section stores code
asm_strcmp:	; setup & variables init
	push	rbp
	mov	rbp, rsp	; function start
	mov	QWORD [rbp-24], rdi	; copy given str1 ptr dest to local rbp 24
	mov	QWORD [rbp-32], rsi	; copy given str2 ptr dest to local rbp 32
	mov	DWORD [rbp-4], 0	; init 1st index, null terminator if unused
	jmp	.L2	; str1 length counting loop
.L3:	; str1 loop increment
	inc	DWORD [rbp-4]	; 1st index increment of 1 in the loop
.L2:	; str1 length counting loop
	mov	eax, DWORD [rbp-4]	; 1st index saved to the top regular gpr
	movsx	rdx, eax	; signed-extend counter
	mov	rax, QWORD [rbp-24]	; str1 comes in
	add	rax, rdx	; scan each element when index increases
	movzx	eax, BYTE [rax]	; byte dword ptr to get the char
	test	al, al	; flag setting only
	jne	.L3	; call L3 for not equal to null byte
	mov	DWORD [rbp-8], 0	; for case meet, init 2nd index
	jmp	.L4	; call L4 for next loop
.L5:	; str2 loop increment
	inc	DWORD [rbp-8]	; 2nd index increment of 1
.L4:	; str2 length counting loop
	mov	eax, DWORD [rbp-8]	; 2nd index saved to the top regular gpr
	movsx	rdx, eax
	mov	rax, QWORD [rbp-32]	; str2 comes in
	add	rax, rdx
	movzx	eax, BYTE [rax]
	test	al, al
	jne	.L5	; call L5 for not equal to null byte
	mov	eax, DWORD [rbp-4]	; pull length saved in rbp-8
	cmp	eax, DWORD [rbp-8]	; commpare with data saved in rbp-12
	je	.L6	; if lengths are equal, do the char comparison
	mov	eax, DWORD [rbp-4]	; pull length again for rbp-8 & -12
	sub	eax, DWORD [rbp-8]	; len(str1) - len(str2), return eax
	jmp	.L7	; end the function
.L6:	; init 3rd index
	mov	DWORD [rbp-12], 0	; init 3rd index
	jmp	.L8	; call L8 for next loop
.L9:	; return difference of str1 & str2 in current index
	mov	eax, DWORD [rbp-12]	; 3rd index saved to the top regular gpr
	movsx	rdx, eax
	mov	rax, QWORD [rbp-24]	; str1 comes in
	add	rax, rdx
	movzx	edx, BYTE [rax]	; str1 byte dword ptr to get the char
	mov	eax, DWORD [rbp-12]	; same index for the str coming up
	movsx	rcx, eax	; different signed-ext required for subtraction
	mov	rax, QWORD [rbp-32]	; str2 comes in
	add	rax, rcx
	movzx	eax, BYTE [rax]	; str2 byte dword ptr to get the char
	cmp	dl, al	; comparison between str1 and str2 chars
	je	.L10	; if same char, increment
	mov	eax, DWORD [rbp-12]	; find the current char in str1
	movsx	rdx, eax
	mov	rax, QWORD [rbp-24]
	add	rax, rdx
	movzx	eax, BYTE [rax]
	movsx   eax, al	; signed str1 char byte value
	mov	edx, DWORD [rbp-12]	; find the current char in str2
	movsx	rcx, edx
	mov	rdx, QWORD [rbp-32]
	add	rdx, rcx
	movzx	edx, BYTE [rdx]
	movsx   edx, dl
	sub	eax, edx	; str1[i] - str2[i], return eax
	jmp	.L7	; end the function
.L10:	; comparison increment
	inc	DWORD [rbp-12]	; 3rd index increment
.L8:	; char difference search loop
	mov	eax, DWORD [rbp-12]	; 3rd index saved to the top regular gpr
	movsx	rdx, eax	; signed-extend counter
	mov	rax, QWORD [rbp-24]	; str1 comes in
	add	rax, rdx	; scan each element when index increases
	movzx	eax, BYTE [rax]	; byte dword ptr to get the char
	test	al, al	; flag setting only
	je	.L11	; if equal to null byte, return 0
	mov	eax, DWORD [rbp-12]	; same index for the str coming up
	movsx	rdx, eax
	mov	rax, QWORD [rbp-32]	; str2 comes in
	add	rax, rdx
	movzx	eax, BYTE [rax]
	test	al, al
	jne	.L9	; if not equal to null byte, go to L9 to return str diff
.L11:
	mov	eax, 0	; return 0 for no difference between the strings
.L7:
	pop	rbp	; end the function
	ret

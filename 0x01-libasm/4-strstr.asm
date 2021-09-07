BITS 64
	global asm_strstr	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_strstr:	; setup & variables init
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-16], rdi	; copy given str1 ptr dest to local rbp
	mov	QWORD [rbp-16], rdi	; copy given str2 ptr dest to local rbp
	mov	eax, esi		; make a char ptr to store the target char
	mov	BYTE [rbp-24], al	; copy given char ptr dest to local rbp 12
	mov	DWORD [rbp-8], 0	; initialize index, null terminator if unused
	jmp	.L2			; char search loop
.L3:		; check current str char, if equal to target char, return char ptr
	mov	edx, DWORD [rbp-8]	; index number saved to the top regular gpr
	mov	rax, QWORD [rbp-16]	; str comes in
	add	rax, rdx		; scan each element when index increases
	movzx	eax, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	cmp	BYTE [rbp-24], al	; compare newfound char with target char
	jne	.L4			; if not equal, loop for next char
	mov	edx, DWORD [rbp-8]
	mov	rax, QWORD [rbp-16]
	add	rax, rdx		; move ptr from str start to current index
	jmp	.L5			; end the function
.L4:		; loop increment and decrement
	inc	DWORD [rbp-4]		; increment of 1, in the loop condition
.L2:		; loop with null byte check
	mov	edx, DWORD [rbp-8]	; index number saved to the top regular gpr
	mov	rax, QWORD [rbp-16]	; str comes in
	add	rax, rdx		; scan each element when index increases
	movzx	eax, BYTE DWORD [rax]	; byte dword ptr to get the char
	test	al, al			; flag setting only
	jne	.L3			; call L3 for not equal to null byte
.L5:		; end the function
	pop	rbp			; end the function
	ret

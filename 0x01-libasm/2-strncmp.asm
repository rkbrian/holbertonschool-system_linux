BITS 64
	global asm_strncmp	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_strncmp:	; setup & variables init
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-8], rdi	; copy given str1 ptr dest to local rbp 8
	mov	QWORD [rbp-16], rsi	; copy given str2 ptr dest to local rbp 16
	mov	DWORD [rbp-20], edx	; copy given range integer
	jmp	.L2			; char comparison loop
.L3:		; the if statement in the loop, jump out for diff of 2 strs
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	edx, BYTE [rax]		; str1 byte qword ptr to get the char
	mov	rax, QWORD [rbp-16]	; str2 comes in
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	dl, al			; comparison between str1 and str2 chars
	je	.L4			; if the same char, go to next if statement
	mov	rax, QWORD [rbp-8]
	movzx	eax, BYTE [rax]
	movzx	edx, al			; unsigned str saved in a gpr
	mov	rax, QWORD [rbp-16]
	movzx	eax, BYTE [rax]
	movzx	ecx, al			; unsigned str saved in another gpr
	mov	eax, edx		; str1 in return value position
	sub	eax, ecx		; subtraction of 2 str and return the value
	jmp	.L5			; end the function
.L4:		; the if statement to check null byte reached
	mov	rax, QWORD [rbp-8]	; find the current char in str1
	movzx	eax, BYTE [rax]		; byte qword ptr to get the ascii of str1
	test	al, al			; flag setting only
	jne	.L6			; if not equal to null byte, loop
	mov	eax, 0			; return 0
	jmp	.L5			; end the function
.L6:		; loop increment and decrement
	inc	QWORD [rbp-8]		; str1 index increment for next char
	inc	QWORD [rbp-16]		; str2 index increment for next char
	dec	DWORD [rbp-20]		; range integer decrement
.L2:		; range limit check
	cmp	DWORD [rbp-20], 0	; check if length meets the end
	jne	.L6			; if not decreased to 0, keep looping
	mov	eax, 0			; return 0
.L5:		; end the function
	pop	rbp			; end the function
	ret

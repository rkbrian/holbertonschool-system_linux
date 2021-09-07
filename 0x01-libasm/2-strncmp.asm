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
.L3:		; return the string askii difference 1
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	edx, BYTE [rax]		; str1 byte qword ptr to get the char
	mov	rax, QWORD [rbp-16]	; str2 comes in
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	dl, al			; comparison between str1 and str2 chars
	jle	.L4			; if less than, go to next if statement
	mov	eax, 1			; return 1
	jmp	.L5			; end the function
.L4:		; return the string askii difference -1
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	edx, BYTE [rax]		; str1 byte qword ptr to get the char
	mov	rax, QWORD [rbp-16]	; str2 comes in
	movzx	eax, BYTE [rax]		; str2 byte qword ptr to get the char
	cmp	dl, al			; comparison between str1 and str2 chars
	jns	.L6			; if not a signed number, jump to L8
	mov	eax, -1			; return -1
	jmp     .L5			; end the function
.L6:		; the if statement to check null byte reached
	mov	rax, QWORD [rbp-8]	; find the current char in str1
	movzx	eax, BYTE [rax]		; byte qword ptr to get the ascii of str1
	test	al, al			; flag setting only
	jne	.L7			; if not equal to null byte, loop
	mov	eax, 0			; return 0
	jmp	.L5			; end the function
.L7:		; loop increment and decrement
	inc	QWORD [rbp-8]		; str1 index increment for next char
	inc	QWORD [rbp-16]		; str2 index increment for next char
	dec	DWORD [rbp-20]		; range integer decrement
.L2:		; while loop with range limit check
	cmp	DWORD [rbp-20], 0	; check if length meets the end
	jne	.L3			; if not decreased to 0, keep looping
	mov	eax, 0			; return 0
.L5:		; end the function
	pop	rbp			; end the function
	ret

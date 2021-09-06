BITS 64
	global asm_strcmp	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_strcmp:	; setup & variables init
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-8], rdi	; copy given str1 ptr dest to local rbp 8
	mov	QWORD [rbp-16], rsi	; copy given str2 ptr dest to local rbp 16
	jmp	.L2			; char comparison loop
.L3:		; the if statement in the loop, jump out for diff of 2 strs
	mov	rax, QWORD [rbp-8]	; str1 saved to the top regular gpr
	movzx	edx, BYTE [rax]		; str1 byte dword ptr to get the char
	mov	rax, QWORD [rbp-16]	; str2 comes in
	movzx	eax, BYTE [rax]		; str2 byte dword ptr to get the char
	cmp	dl, al			; comparison between str1 and str2 chars
	jne	.L4			; if not the same char, break
	inc	DWORD [rbp-8]		; str1 index increment for next char
	inc	DWORD [rbp-16]		; str2 index increment for next char
.L2:		; while loop to search char difference
	mov	rax, QWORD [rbp-8]	; find the current char in str1
	movzx	eax, BYTE [rax]		; byte qword ptr to get the ascii of str1
	test	al, al			; flag setting only
	jne	.L3			; if not equal to null byte, loop
	jmp	.L5			; end the function
.L4:		; loop break
	nop			; do nothing, jump here to continue the following
.L5:		; return the string askii difference 1
	mov	rax, QWORD [rbp-8]	; str1 comes in
	movzx	eax, BYTE [rax]		; byte qword ptr to get the ascii of str1
	movzx	edx, al			; unsigned str saved in a gpr
	mov	rax, QWORD [rbp-16]	; str2 comes in
	movzx	eax, BYTE [rax]		; byte qword ptr to get the ascii of str1
	movzx	ecx, al			; unsigned str saved in another gpr
	mov	eax, edx		; str1 in return value position
	sub	eax, ecx		; subtraction of 2 str and return the value
	test	eax, eax		; flag setting only, comparison with 0
	jle     .L6			; if less than or equal to 0, jump to L6
	mov	eax, 1			; return 1
	jmp	.L7			; go to the end
.L6:		; return the string askii difference -1
	mov     rax, QWORD [rbp-8] 	; steps similar to L5
	movzx   eax, BYTE [rax]		; byte qword ptr to get the ascii of str1
	movzx   edx, al			; unsigned str saved in a gpr
	mov     rax, QWORD [rbp-16]	; str2 comes in
	movzx   eax, BYTE [rax]	    	; byte qword ptr to get the ascii of str1
	movzx   ecx, al			; unsigned str saved in another gpr
	mov     eax, edx	    	; str1 in return value position
	sub     eax, ecx	    	; subtraction of 2 str and return the value
	test    eax, eax	    	; flag setting only, comparison with 0
	jns	.L8		    	; if not a signed number, jump to L8
	mov	eax, -1			; return -1
	jmp	.L7			; go to the end
.L8:		; return 0
	mov	eax, 0			; return 0
.L7:		; end the function
	pop	rbp			; end the function
	ret

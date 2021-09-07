BITS 64
	global asm_strstr	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_strstr:	; setup & variables init
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-24], rdi	; copy haystack ptr dest to local rbp
	mov	QWORD [rbp-32], rsi	; copy needle ptr dest to local rbp
	mov	rax, QWORD [rbp-32]	; if statement: needle is null byte
	movzx	eax, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	test	al, al			; flag setting only
	jne	.L2			; call L2 for not equal to null byte
	mov	rax, QWORD [rbp-24]	; haystack comes in for return
	jmp	.L3			; jump to end the function
.L2:		; if haystack is a null byte only string
	mov	rax, QWORD [rbp-24]	; haystack comes in for upcoming if condition
	movzx	eax, BYTE DWORD [rax]
	test	al, al
	jne	.L4			; call L4 for not equal to null byte
	mov 	eax, 0			; return null ptr
	jmp	.L3			; jump to end the function
.L4:		; haystack str length
	mov	DWORD [rbp-12], 0	; haystack increment hal = 0
	jmp	.L5			; find str len
.L6:		; haystack increment
	inc	DWORD [rbp-12]		; increment of 1 in the loop
.L5:		; haystack loop condition
	mov     edx, DWORD [rbp-12] 	; index number saved to the top regular gpr
	mov     rax, QWORD [rbp-24]	; str comes in
	add     rax, rdx		; scan each element when index increases
        movzx   eax, BYTE DWORD [rax] 	; byte dword ptr to get the char from str
	test    al, al                  ; flag setting only
	jne     .L6			; loop for not equal to null byte
	mov     DWORD [rbp-16], 0       ; needle increment nel = 0
	jmp     .L7			; find str len
.L8:		; needle increment
	inc     DWORD [rbp-16]
.L7:		; needle loop condition
	mov	edx, DWORD [rbp-16]
	mov	rax, QWORD [rbp-32]
	add	rax, rdx
	movzx	eax, BYTE [rax]
	test	al, al
	jne	.L8
	mov	DWORD [rbp-4], 0 	; search loop: haystack increment i = 0
	jmp	.L9			; outer loop conditions
.L10:		; search loop: needle increment
	mov	DWORD [rbp-8], 0 	; j = 0
	jmp	.L11
.L12:		; if statement of comparing each char in haystack and needle
	mov	edx, DWORD [rbp-4]	; i saved to the top regular gpr
	mov	rax, QWORD [rbp-24]	; haystack comes in
	add	rax, rdx		; scan each element when index increases
	movzx	edx, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	mov	ecx, DWORD [rbp-8]	; j saved to the next regular gpr
	mov	rax, QWORD [rbp-32]	; needle comes in
	add	rax, rcx		; scan each element when index increases
	movzx	eax, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	cmp	dl, al			; comparison between haystack and needle chars
	jne	.L13			; if not equal, break
	inc	DWORD [rbp-4]		; otherwise, i++ for next haystack char
	mov	eax, DWORD [rbp-16]	; nel value
	sub	eax, 1
	cmp	DWORD [rbp-8], eax 	; if j reaches the end
	jne	.L14
	mov	edx, DWORD [rbp-4]	; save i
	sub	eax, DWORD [rbp-16]	; i - nel
	mov	edx, eax		; save the start of sub string found
	mov	rax, QWORD [rbp-24]     ; haystack comes in
	add	rax, rdx		; return the pointer to addr in haystack
	jmp	.L3			; jump to end the function
.L14:		; check current str char, if equal to target char, return char ptr
	inc	DWORD [rbp-8]		; increment of 1 in j loop
.L11:		; search loop: nested loop of j
	mov	eax, DWORD [rbp-8]	; j saved to the top regular gpr
	cmp	eax, DWORD [rbp-16]	; compare j and nel
	jb	.L12			; jump if j is below nel
	jmp	.L15			; end the function
.L13:		; break
	nop
.L15:		; loop increment and decrement
	inc	DWORD [rbp-4]		; increment of 1, in i loop
.L9:		; search loop: outer loop of i
	mov	eax, DWORD [rbp-4]	; i saved to the top regular gpr
	cmp     eax, DWORD [rbp-12]     ; compare i and hal
	jb	.L10			; jump if i is below hal
	mov	eax, 0			; return null ptr
.L3:		; end the function
	pop	rbp			; end the function
	ret

BITS 64
	global asm_strcspn	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_strcspn:
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-24], rdi	; copy str s ptr dest to local rbp
	mov	QWORD [rbp-32], rsi	; copy str reject ptr dest to local rbp
	mov	DWORD [rbp-12], 0	; init length counter k = 0
	mov	DWORD [rbp-16], 0	; init flag of reject char break f = 0
	mov	DWORD [rbp-8], 0	; init outer loop increment j = 0
	jmp	.outer_start		; outer loop start
.inner_start:		; inner loop start
	mov	DWORD [rbp-4], 0 	; init inner loop increment i = 0
	jmp	.inner_null		; reject[i] null byte checker
.if_match:		; compare the chararcters
	mov	edx, DWORD [rbp-8] 	; index j saved to the regular gpr
	mov	rax, QWORD [rbp-24]	; s comes in
	add	rax, rdx		; scan each element when index increases
	movzx	edx, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	mov	ecx, DWORD [rbp-4]	; index j saved to the regular gpr
	mov	rax, QWORD [rbp-32]	; reject comes in
	add	rax, rcx
	movzx	eax, BYTE DWORD [rax]
	cmp	dl, al			; compare s char with reject char
	jne	.i_inc			; if not match, next reject[i]
	inc	DWORD [rbp-16]		; else, raise flag f++
.i_inc:			; i increment
	inc	DWORD [rbp-4]		; i++
.inner_null:		; reject[i] null byte checker
	mov	edx, DWORD [rbp-4] 	; index i saved to the regular gpr
	mov	rax, QWORD [rbp-32]	; reject comes in
	add	rax, rdx		; scan each element when index increases
	movzx	eax, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	test	al, al			; null byte checking
	jne	.if_match		; back to inner loop if not null byte
	cmp	DWORD [rbp-16], 0	; compare f with 0
	jne	.br			; if f > 0, break
	inc	DWORD [rbp-12]		; k++
	inc	DWORD [rbp-8]		; else, j++, back to the outer loop
.outer_start:		; outer loop start
	mov	edx, DWORD [rbp-8] 	; index j saved to the regular gpr
	mov	rax, QWORD [rbp-24]	; s comes in
	add	rax, rdx		; scan each element when index increases
	movzx	eax, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	test	al, al			; null byte checking
	jne	.inner_start		; back to outer loop if not null byte
	jmp	.rk			; to return
.br:
	nop				; break
.rk:
	mov	eax, DWORD [rbp-12] 	; prepare return value k
	pop	rbp			; end the function
	ret

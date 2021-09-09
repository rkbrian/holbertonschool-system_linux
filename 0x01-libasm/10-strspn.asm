BITS 64
	global asm_strspn	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_strspn:
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-24], rdi	; copy str s ptr dest to local rbp
	mov	QWORD [rbp-32], rsi	; copy str accept ptr dest to local rbp
	mov	DWORD [rbp-12], 0	; init length counter k = 0
	mov	DWORD [rbp-16], 0	; init flag of segment break f = 0
	mov	DWORD [rbp-8], 0	; init outer loop increment j = 0
	jmp	.outer_start		; outer loop start
.inner_start:		; inner loop start
	mov	DWORD [rbp-4], 0 	; init inner loop increment i = 0
	jmp	.inner_null		; accept[i] null byte checker
.if_match:		; compare the chararcters
	mov	edx, DWORD [rbp-8] 	; index j saved to the regular gpr
	mov	rax, QWORD [rbp-24]	; s comes in
	add	rax, rdx		; scan each element when index increases
	movzx	edx, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	mov	ecx, DWORD [rbp-4]	; index j saved to the regular gpr
	mov	rax, QWORD [rbp-32]	; accept comes in
	add	rax, rcx		;
	movzx	eax, BYTE DWORD [rax]	;
	cmp	dl, al			; compare s char with accept char
	jne	.i_inc			; if not match, next accept[i]
	inc	DWORD [rbp-12]		; k++
	jmp	.flag_inc		; jump out of inner loop for flag check
.i_inc:			; i increment
	inc	DWORD [rbp-4]	 	; i++
.inner_null:
	mov	edx, DWORD [rbp-4] 	; index i saved to the regular gpr
	mov	rax, QWORD [rbp-32]	; accept comes in
	add	rax, rdx		; scan each element when index increases
	movzx	eax, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	test	al, al			; null byte checking
	jne	.if_match		; back to inner loop if not null byte
.flag_inc:		; f increment for 1st segment found
	cmp	DWORD [rbp-12], 0 	; compare k with 0
	je	.br			; if k = 0, break
	inc	DWORD [rbp-16]		; else, f++
	mov	eax, DWORD [rbp-16] 	; load f value
	cmp	eax, DWORD [rbp-12]	; compare f with k
	ja	.br			; if f > k, break
	inc	DWORD [rbp-8]		; else, j++, back to outer loop
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
	mov	eax, DWORD [rbp-12] 	; return k
	pop	rbp			; end the function
	ret

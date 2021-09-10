BITS 64
	global asm_memcpy	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_memcpy:
	push	rbp 			; push rbp register to stack
	mov	rbp, rsp		; move rsp register content to rbp register
	mov	QWORD [rbp-24], rdi	; copy void dest ptr to local rbp
	mov	QWORD [rbp-32], rsi	; copy void src ptr to local rbp
	mov	QWORD [rbp-40], rdx	; copy unsigned long int n to local rbp
	mov	rdx, QWORD [rbp-32]	; 1st loop, regular case, load src
	mov	rax, QWORD [rbp-40]	; 1st loop, regular case, load n
	add	rax, rdx		; src + n
	cmp	QWORD [rbp-24], rax	; src + n compared with dest
	ja	.norm_case		; if dest > src + n, normal case
	mov	rax, QWORD [rbp-24]	; load dest
	cmp	rax, QWORD [rbp-32]	; dest compare src
	jnb	.overlapped		; if dest < src, normal case, otherwise jump
.norm_case:	; normal case
	mov	rax, QWORD [rbp-24]	; load dest
	mov	QWORD [rbp-8], rax	; new char str ptr dest_mem point to dest
	mov	rax, QWORD [rbp-32]	; load src
	mov	QWORD [rbp-16], rax	; new char str ptr src_mem point to dest
	jmp	.norm_loop		; go to loop
.norm_inc:	; loop increment for normal case
	mov	rdx, QWORD [rbp-16] 	; load src_mem
	lea	rax, [rdx+1]		; load effective address offset
	mov	QWORD [rbp-16], rax	; src_mem++
	mov	rax, QWORD [rbp-8]	; load dest_mem
	lea	rcx, [rax+1]		; load effective address offset
	mov	QWORD [rbp-8], rcx	; dest_mem++
	movzx	edx, BYTE [rdx]		; byte ptr to get the char from str
	mov	BYTE [rax], dl		; dest_mem++ point to the char
.norm_loop:	; loop starter for normal case
	mov	rax, QWORD [rbp-40]	; load n
	lea	rdx, [rax-1]		; load effective address offset
	mov	QWORD [rbp-40], rdx	; n--
	test	rax, rax		; null terminate / 0 check
	jne	.norm_inc		; if not null byte, back to loop
	jmp	.br			; otherwise, go to end the function
.overlapped:	; loop for dest (or dest_mem) overlapping src
	mov	rax, QWORD [rbp-40] 	; load n
	lea	rdx, [rax-1]		; load effective address offset
	mov	rax, QWORD [rbp-24]	; dest + n
	add	rax, rdx		; dest + n - 1
	mov	QWORD [rbp-8], rax	; dest_mem = dest + n - 1
	mov	rax, QWORD [rbp-40]	; load n
	lea	rdx, [rax-1]		; load effective address offset
	mov	rax, QWORD [rbp-32]	; src + n
	add	rax, rdx		; src + n - 1
	mov	QWORD [rbp-16], rax	; src_mem = src + n - 1
	jmp	.over_loop		; go to loop
.over_inc:	; loop increment for normal case
	mov	rdx, QWORD [rbp-16] 	; load src_mem
	lea	rax, [rdx-1]	    	; load effective address offset
	mov	QWORD [rbp-16], rax 	; src_mem--
	mov	rax, QWORD [rbp-8]  	; load dest_mem
	lea	rcx, [rax-1]		; load effective address offset
	mov	QWORD [rbp-8], rcx	; dest_mem--
	movzx	edx, BYTE [rdx]		; byte ptr to get the char from str
	mov	BYTE [rax], dl		; dest_mem-- point to the char
.over_loop:     ; loop starter for normal case
	mov	rax, QWORD [rbp-40] 	; load n
	lea	rdx, [rax-1]		; load effective address offset
	mov	QWORD [rbp-40], rdx	; n--
	test	rax, rax		; null terminate / 0 check
	jne	.over_inc		; if not null byte, back to loop
.br:
	nop				; break
	mov	rax, [rbp-8]		; return dest_mem
	pop	rbp			; end the function
	ret

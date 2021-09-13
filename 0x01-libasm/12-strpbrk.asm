BITS 64
	global asm_strpbrk	; export for external files
	SECTION .text		; this section stores code
asm_strpbrk:		; setup & variables init
	push	rbp
	mov	rbp, rsp		; function start
	mov	QWORD [rbp-24], rdi	; copy given str s ptr dest to local rbp
	mov	QWORD [rbp-32], rsi 	; copy given str accept ptr dest to local rbp
.ifs1_null:		;check if s or accept is null string
	mov	rax, QWORD [rbp-24] 	; s saved to the top regular gpr
	movzx	eax, BYTE [rax]		; s byte qword ptr to get the char
	test	al, al			; checking null termination
	je	.ret_zzz		; if equal to null byte, return 0
	mov	rax, QWORD [rbp-32] 	; accept saved to the top regular gpr
	movzx	eax, BYTE [rax]		; accept byte qword ptr to get the char
	test	al, al			; checking null termination
	je	.ret_zzz		; if equal to null byte, return 0
	mov	DWORD [rbp-8], 0	; unsigned int 
	jmp	.L2
.L9:			;setup & variables init
	mov	DWORD [rbp-4], 0
	jmp	.L3
.L6:			;setup & variables init
	mov	edx, DWORD [rbp-4]
	mov	rax, QWORD [rbp-32]
	add	rax, rdx
	movzx	edx, BYTE [rax]
	mov	ecx, DWORD [rbp-8]
	mov	rax, QWORD [rbp-24]
	add	rax, rcx
	movzx	eax, BYTE [rax]
	cmp	dl, al
	je	.L12
	add	DWORD [rbp-4], 1
.L3:			;setup & variables init
	mov	edx, DWORD [rbp-4]
	mov	rax, QWORD [rbp-32]
	add	rax, rdx
	movzx	eax, BYTE [rax]
	test	al, al
	jne	.L6
	jmp	.L5
.L12:			;setup & variables init
	nop
.L5:			;setup & variables init
	mov	edx, DWORD [rbp-8]
	mov	rax, QWORD [rbp-24]
	add	rax, rdx
	movzx	edx, BYTE [rax]
	mov	ecx, DWORD [rbp-4]
	mov	rax, QWORD [rbp-32]
	add	rax, rcx
	movzx	eax, BYTE [rax]
	cmp	dl, al
	je	.L13
	add	DWORD [rbp-8], 1
.L2:			;setup & variables init
	mov	edx, DWORD [rbp-8]
	mov	rax, QWORD [rbp-24]
	add	rax, rdx
	movzx	eax, BYTE [rax]
	test	al, al
	jne	.L9
	jmp	.L8
.L13:			;setup & variables init
	nop
.L8:			;setup & variables init
	mov	edx, DWORD [rbp-8] 	;
	mov	rax, QWORD [rbp-24]	;
	add	rax, rdx		;
	movzx	eax, BYTE [rax]		;
	test	al, al			;
	jne	.ret_charptr		;
.ret_zzz:		; return zero for null string/byte
	mov	eax, 0			; return 0
	jmp	.all_finished		; go to end the function
.ret_charptr:			; p
	mov	edx, DWORD [rbp-8] 	;
	mov	rax, QWORD [rbp-24]	;
	add	rax, rdx		;
.all_finished:			; end the function
	pop	rbp
	ret

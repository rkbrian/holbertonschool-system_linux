BITS 64
	global asm_memcpy	; export for external files
	extern main		; import main file
	SECTION .text		; this section stores code
asm_memcpy:
	push	rbp 			; push rbp register to stack
	mov	rbp, rsp		; move rsp register content to rbp register
	mov	QWORD [rbp-40], rdi	; copy void dest ptr to local rbp
	mov	QWORD [rbp-48], rsi	; copy void src ptr to local rbp
	mov	DWORD [rbp-52], edx	; copy int n to local rbp
	mov	rax, QWORD [rbp-40]	; type cast dest as char str
	mov	QWORD [rbp-24], rax	; new char str ptr dest_mem point to dest
	mov	rax, QWORD [rbp-48]	; type cast src as char str
	mov	QWORD [rbp-16], rax	; new char str ptr src_mem point to dest
	mov	DWORD [rbp-4], 0	; init increment i = 0 for copying char
	jmp	.L2
.L3:	; loop content
	mov	edx, DWORD [rbp-4]	; index i saved to the regular gpr
	mov	rax, QWORD [rbp-16]	; load src_mem
	add	rax, rdx		; scan each char when index increases
	mov	ecx, DWORD [rbp-4]	; index i saved to the regular gpr
	mov	rdx, QWORD [rbp-24]	; load dest_mem
	add	rdx, rcx		; scan each char when index increases
	movzx	eax, BYTE DWORD [rax]	; byte dword ptr to get the char from str
	mov	BYTE DWORD [rdx], al	; save copy of src char into dest address
	inc	DWORD [rbp-4]		; i++
.L2:	; loop limit and return
	mov	eax, DWORD [rbp-4]	; index i saved to the regular gpr
	cmp	eax, DWORD [rbp-52]	; compare i with n
	jb	.L3	 		; if i < n, loop
	nop				; otherwise, break for savely exit
	pop	rbp			; end the function
	ret

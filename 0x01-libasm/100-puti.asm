BITS 64
	global asm_puti		; export for external files
	extern write, asm_putc		; import main file
	SECTION .text		; this section stores code
asm_puti:
	push    rbp
	mov     rbp, rsp
	sub     rsp, 48
	mov     DWORD [rbp-36], edi
	mov     eax, DWORD [rbp-36]
	mov     DWORD [rbp-4], eax
	mov	DWORD [rbp-8], 0
	mov     DWORD [rbp-12], 0
	mov     DWORD [rbp-16], 0
	mov     DWORD [rbp-20], 0
	mov     DWORD [rbp-24], 1
	cmp     DWORD [rbp-36], 0
	je	.L6
	cmp     DWORD [rbp-36], 0
	jns     .L3
	mov     edi, 45
	mov     eax, 0
	call    asm_putc
	neg     DWORD [rbp-4]
	add     DWORD [rbp-12], 1
	jmp     .L3
.L9:
	mov     eax, DWORD [rbp-4]
	mov     DWORD [rbp-8], eax
	jmp     .L4
.L5:
	mov     edx, DWORD [rbp-24]
	mov     eax, edx
	sal     eax, 2
	add     eax, edx
	add     eax, eax
	mov     DWORD [rbp-24], eax
	mov     eax, DWORD [rbp-8]
	mov     edx, eax
	mov     eax, 3435973837
	imul    rax, rdx
	shr     rax, 32
	shr     eax, 3
	mov     DWORD [rbp-8], eax
	add     DWORD [rbp-20], 1
.L4:
	cmp     DWORD [rbp-8], 9
	ja      .L5
	mov     eax, DWORD [rbp-16]
	sub     eax, DWORD [rbp-20]
	cmp     eax, 1
	jbe     .L6
	cmp     DWORD [rbp-16], 0
	je      .L6
	jmp     .L7
.L8:
	mov     edi, 48
	mov     eax, 0
	call    asm_putc
	inc	DWORD [rbp-12]
	sub     DWORD [rbp-16], 1
.L7:
	mov     eax, DWORD [rbp-16]
	sub     eax, DWORD [rbp-20]
	cmp     eax, 1
	ja      .L8
.L6:
	mov     eax, DWORD [rbp-8]
	add     eax, 48
	mov     edi, eax
	mov     eax, 0
	call    asm_putc
	mov     edx, DWORD [rbp-4]
	mov     eax, DWORD [rbp-8]
	imul    eax, DWORD [rbp-24]
	mov     ecx, eax
	mov     eax, edx
	sub     eax, ecx
	mov     DWORD [rbp-4], eax
	add     DWORD [rbp-12], 1
	mov     DWORD [rbp-24], 1
	mov     eax, DWORD [rbp-20]
	mov     DWORD [rbp-16], eax
	mov     DWORD [rbp-20], 0
.L3:
	cmp     DWORD [rbp-4], 0
	jne     .L9
	mov     eax, DWORD [rbp-12]
	leave
	ret

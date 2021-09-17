BITS 64
	global asm_puti_base		; export for external files
	extern asm_strlen, asm_putc	; import main file
	SECTION .text			; this section stores code
asm_puti_base:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 64
        mov     DWORD [rbp-52], edi
        mov     QWORD [rbp-64], rsi
        mov     DWORD [rbp-4], 0
        mov     DWORD [rbp-8], 1
        mov     eax, DWORD [rbp-52]
        mov     DWORD [rbp-12], eax
        mov     rax, QWORD [rbp-64]
        mov     rdi, rax
        call    asm_strlen
        mov     DWORD [rbp-32], eax
        mov     DWORD [rbp-28], 0
        cmp     DWORD [rbp-52], 0
        jne     .L2
        mov     rax, QWORD [rbp-64]
        movzx   eax, BYTE [rax]
        movsx   eax, al
        mov     edi, eax
        call    asm_putc
        add     DWORD [rbp-28], 1
        mov     eax, DWORD [rbp-28]
        jmp     .L3
.L2:
        cmp     DWORD [rbp-52], 0
        jns     .L4
        mov     edi, 45
        call    asm_putc
        neg     DWORD [rbp-12]
.L4:
        mov     eax, DWORD [rbp-12]
        mov     DWORD [rbp-16], eax
        jmp     .L5
.L6:
        mov     eax, DWORD [rbp-16]
        cdq
        idiv    DWORD [rbp-32]
        mov     DWORD [rbp-16], eax
        add     DWORD [rbp-4], 1
.L5:
        cmp     DWORD [rbp-16], 0
        jg      .L6
        mov     eax, DWORD [rbp-4]
        sub     eax, 1
        mov     DWORD [rbp-20], eax
        jmp     .L7
.L10:
        mov     DWORD [rbp-24], 0
        jmp     .L8
.L9:
        mov     eax, DWORD [rbp-8]
        imul    eax, DWORD [rbp-32]
        mov     DWORD [rbp-8], eax
        add     DWORD [rbp-24], 1
.L8:
        mov     eax, DWORD [rbp-24]
        cmp     eax, DWORD [rbp-20]
        jl      .L9
        mov     eax, DWORD [rbp-12]
        cdq
        idiv    DWORD [rbp-8]
        mov     DWORD [rbp-36], eax
        mov     eax, DWORD [rbp-36]
        movsx   rdx, eax
        mov     rax, QWORD [rbp-64]
        add     rax, rdx
        movzx   eax, BYTE [rax]
        movsx   eax, al
        mov     edi, eax
        call    asm_putc
        mov     eax, DWORD [rbp-12]
        cdq
        idiv    DWORD [rbp-8]
        mov     DWORD [rbp-12], edx
        mov     DWORD [rbp-8], 1
        add     DWORD [rbp-28], 1
	sub     DWORD [rbp-20], 1
.L7:
	cmp     DWORD [rbp-20], 0
	jns     .L10
	mov     eax, DWORD [rbp-28]
.L3:
	leave
	ret

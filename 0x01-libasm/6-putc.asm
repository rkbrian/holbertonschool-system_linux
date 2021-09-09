BITS 64
	global asm_putc		; export for external files
	extern main		; import main file and syscall
	SECTION .texts		; this section stores code
asm_putc:
	push	rbp			; push rbp register to stack
	mov	rbp, rsp		; move rsp register content to rbp register
	sub	rsp, 16			; alloc for return addr of local var for no frame ptr
	mov	DWORD [rbp-4], edi	; copy int c to local rbp

	mov	ebx, 1			; file descriptor of stdout, 1st input regi
	lea	rcx, [rbp-4]		; int c saved to buffer
	mov	edi, 1			; count of output, 3rd input regi
	mov	eax, 1			; use the write syscall
	syscall			; interupt with identifier of running write

	mov	ebx, 0			; close file
	mov	ecx, 0			; clear buffer
	mov	eax, 60			; return fd of stdout
	syscall			; interupt with identifier of running write

	leave				; destroy stack frame
	ret

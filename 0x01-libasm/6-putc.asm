BITS 64
	global asm_putc	; export for external files
	extern write	; import write file
	section .text	; this section stores code
asm_putc:
	push	rbp
	mov	rbp, rsp		; push rbp register to stack
	sub	rsp, 16			; alloc for addr of local var for frame ptr
	mov	DWORD [rbp-4], edi	; copy int c to local rbp and redeclare as char
	lea	rax, [rbp-4]		; load effective address
	mov	edx, 1			; write: 3rd var for write length
	mov	rsi, rax		; write: 2nd var for print content
	mov	edi, 1			; write: 1st var for file descriptor of stdout
	mov	eax, 0			; clear buffer
	call    write			; print char
	leave				; destroy stack frame
	ret

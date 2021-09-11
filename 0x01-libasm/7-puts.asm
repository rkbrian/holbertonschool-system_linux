BITS 64
	global asm_puts			; export for external files
	extern asm_strlen, write 	; import asm_ file
	SECTION .text			; this section stores code
asm_puts:
	push	rbp
	mov	rbp, rsp		; push rbp register to stack
	sub	rsp, 32			; alloc for addr of local var for frame ptr
	mov	QWORD [rbp-24], rdi	; copy str ptr to local rbp
	mov	rax, QWORD [rbp-24]	; load str
	mov	rdi, rax		; str to be input of upcoming function
	mov	eax, 0			; clear buffer
	call	asm_strlen		; find str length, save the value to buffer
	mov	DWORD [rbp-4], eax	; load buffer, int i = len(str)
	mov	edx, DWORD [rbp-4]	; write: 3rd var for write length
	mov	rax, QWORD [rbp-24]	; load str
	mov	rsi, rax		; write: 2nd var for print content
	mov	edi, 1			; write: 1st var for file descriptor of stdout
	mov	eax, 1			; syscall of write
	syscall				; print str
	mov	eax, DWORD [rbp-4]	; return i
	leave				; destroy stack frame
	ret

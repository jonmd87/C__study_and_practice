; ssize_t WRITE(int fd, const char *buf, size_t count);

section .text
global ft_write

ft_write:
	mov rax, 1
	syscall
	ret

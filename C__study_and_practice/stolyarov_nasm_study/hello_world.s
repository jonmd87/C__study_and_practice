global _start

section .data
	msg db "hello world", 10
	len equ $-msg
section .text
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg 
	mov edx, len
	int	80h

	mov eax, 1
	mov ebx, 0
	int 80h



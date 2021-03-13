section .text
	global _start
_start:
	mov edx, 1
	mov	ecx, char
	mov ebx, sys_exit
	mov eax, sys_write 
	int 0x80

	mov eax, 1
	int	0x80
	
section .data
	char db 'j'
section .bss

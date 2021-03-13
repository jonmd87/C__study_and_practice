# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    fill_char.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgen <jonmd87@live.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 10:35:55 by evgen             #+#    #+#              #
#    Updated: 2021/03/13 11:45:36 by evgen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%define MAX 10

section .bss
	array resb MAX

section .text
	global _start

_start:
	mov ecx, MAX
	mov edi, array
	mov al, '@'
	dec ecx
again: mov [edi], al
	inc edi
	dec ecx
	jnz again

	inc ecx
	mov edi, 0xa

	mov edx, MAX
	lea ecx, [array]
	mov ebx, 1
	mov eax, 4
	int 0x80

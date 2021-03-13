# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_number_show_number.s                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgen <jonmd87@live.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 14:07:09 by evgen             #+#    #+#              #
#    Updated: 2021/03/13 15:24:15 by evgen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .data
	first_msg db "Please, enter first number:"
	displMsg db "You have entered:"
	len_first equ $-first_ms
	len_dispMsg equ $-displMsg

section .bss
	number resb 5

section .text
	global _start

_start: ;<-----------метка начало исполнения команд; 
; запращивает  пользовательский ввод
	mov eax, 4 ;<---------Помещает системный вызов (sys_write(4)) в РЕГ[eax]
	mov ebx, 1 ;<---------Помещает в РЕГ[ebx] файловый дескриптор (stdout)
	mov ecx, first_msg ;<-Помещает в РЕГ[ecx] "начало строки" first_msg	
	mov edx, len_first ;<-Помещает в РЕГ[edx] длину строки first_msg
	int	80h ;<------------Вызов ядра(прерывания )
; считываем и сохраняем польз. ввод 
		mov 
	


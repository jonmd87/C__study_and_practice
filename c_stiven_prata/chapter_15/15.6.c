/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EvGeN <jonmd87@yandex.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 by EvGeN                      #+#    #+#             */
/*   Updated: 2021/02/20 by EvGeN                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
**Develop a bit field structure that contains the following information:
** 		• Font ID: a number from O to 255
** 		• Font size: number from O to 127
** 		• Alignment: A number from O to 2 (representing the left, center,
**												    and right alignment options)
**		• Bold: disabled (O) or enabled (1)
** 	 	• Italics: disabled (O) or enabled (1)
** 	 	• Underlined: Disabled (O) or enabled (1)
**
** Use this structure in a program that displays font parameters 
** and gives the user the ability to change parameters using a circular menu.
** The following is an example of the program execution:
** |--------------------------------------------------------------------------|
** |  ID     SIZE     ALIGNMENT           BOLD       ITALICS       UNDERLINED |
** |   1	  12		left			disabled	 disabled		disabled  |
** | ________________________________________________________________________ |
** | |   [f] change font      [s] change size       [a] change alignment    | |
** | |	 [b] bold			  [i] italics			[u] underlined			| |
** | |																        | |
** | |						   q) QUIT										| |
** | |______________________________________________________________________| |
** |																		  |
** | 	-YOUR answer-: s													  |
** | Enter new size of font(from 0 to 127):									  |
** | 	-YOUR answer-: 36													  |
** |																		  |
** |  ID     SIZE     ALIGNMENT           BOLD       ITALICS       UNDERLINED |
** |   1	  36		left			disabled	 disabled		disabled  |
** | ________________________________________________________________________ |
** | |   [f] change font      [s] change size       [a] change alignment    | |
** | |	 [b] bold			  [i] italics			[u] underlined			| |
** | |																        | |
** | |						   q) QUIT										| |
** | |______________________________________________________________________| |
** |																		  |
** | -YOUR answer-: s														  |
** | Chose alignmet:														  | 
** |			  	[l] left	[c] centre	[r] right				 		  |
** | -YOUR answer-: right													  |
** |																		  |
** |  ID     SIZE     ALIGNMENT           BOLD       ITALICS       UNDERLINED |
** |   1	  36		rigt			disabled	 disabled		disabled  |
** | ________________________________________________________________________ |
** | |   [f] change font      [s] change size       [a] change alignment    | |
** | |	 [b] bold			  [i] italics			[u] underlined			| |
** | |																        | |
** | |						   q) QUIT										| |
** | |______________________________________________________________________| |
** |																		  |
** | -YOUR answer-: b														  |
** |																		  |
** |  ID     SIZE     ALIGNMENT           BOLD       ITALICS       UNDERLINED |
** |   1	  36		rigt			enabled		 disabled		disabled  |
** | ________________________________________________________________________ |
** | |   [f] change font      [s] change size       [a] change alignment    | |
** | |	 [b] bold			  [i] italics			[u] underlined			| |
** | |																        | |
** | |						   q) QUIT										| |
** | |______________________________________________________________________| |
** |																		  |
** | -YOUR answer-: b														  |
** | GOOD BUY																  |
** |			etc.....													  |
** |__________________________________________________________________________|
** To ensure that the input ID and font size values are converted to a value 
** from the specified range, the program must apply the -=[&]=- operation 
** and appropriate masks.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MASK 0x0
#define BLD 0x4
#define ITL 0x2
#define UNL 0x1

#define LEFT 0x1
#define RIGH 0x2

#define NONE 0x0

#define ENB " enabled"
#define DIS "disebled" 
#define ANSWER "dsabiu"

#define MAX_SIZE 127
#define MAX_ALIG 2
#define MAX_ID 255
#define MIN 0

#define WRONG "Wrong input data"
#define BYE "!!!GOOD BYE!!!"

typedef struct			s_fild {
	unsigned int		id : 8;
	unsigned int		size : 7;
	unsigned int		alig : 2;
	unsigned int		bld : 1;
	unsigned int		itl : 1;
	unsigned int		unl : 1;
}						t_fild;

const char *alig[3] = {"left", "centre", "right"};

static void				menu(void);
static int				get_answer(unsigned char *ch);
static void				distribution(t_fild *fild, const char ch);
static int				get_number(int min, int max);
static void				show_data(t_fild *fild);
static void				ft_quit(int val, const char *message);

int						main(void)
{
	t_fild				fild;
	unsigned char		ch;

	ch = 0;
	show_data(&fild);
	menu();
	*(unsigned int*)&fild = (unsigned int)NONE;
	while (get_answer(&ch) > 0)
	{
		distribution(&fild, ch);
		while (getchar() != '\n');
		show_data(&fild);
	}
	printf(BYE);
	return (0);
}

static void				menu(void)
{
	putchar('\n');
	printf("\t\t\t\t\t ________________________________________________________ \n");
	printf("\t\t\t\t\t|                                                        |\n");
	printf("\t\t\t\t\t| [d] change ID    [s] change size  [a] change alignment |\n");
	printf("\t\t\t\t\t| [b] bold         [i] italics      [u] underlined       |\n");
	printf("\t\t\t\t\t|                                                        |\n");
	printf("\t\t\t\t\t|                  q) QUIT                               |\n");
	printf("\t\t\t\t\t|________________________________________________________|\n");
	putchar('\n');
}

static int				get_answer(unsigned char *ch)
{
	while (1)
	{
		scanf("%c", &(*ch));
		if (tolower(*ch) == 'q')
			return (0);
		else if ((strchr(ANSWER, *ch)))
			return (1);
		menu();
		puts(WRONG);
		while (getchar() != '\n');
	}	
	return (0);
}

static void				distribution(t_fild *fild, const char ch)
{
		if (ch == 's')
			fild->size = get_number(MIN, MAX_SIZE);
		else if (ch == 'a')
			fild->alig = get_number(MIN, MAX_ALIG);
		else if (ch == 'd')
			fild->id = get_number(MIN, MAX_SIZE * 2 + 1);
		else if (ch == 'b')
			fild->bld = get_number(MIN, 1);
		else if (ch == 'i')
			fild->itl = get_number(MIN, 1);
		else if (ch == 'u')
			fild->unl = get_number(MIN, 1);
}

static int				get_number(int min, int max)
{
	int					val;

	val = 0;
	while (1)
	{
		puts("<----------------Changing size");
		printf("Enter number in limits [%i] and [%i]\n", min, max);
		while (scanf("%i", &val) != 1)
		{
			if (tolower(getchar()) == 'q')
				ft_quit(EXIT_SUCCESS, "Program closed");
			while (getchar() != '\n');
			puts(WRONG);
		}
		if (val > min - 1 && val < max + 1)
			return (val);
		printf("%s", WRONG);
		continue ;
	}
	return (0);
}

static void				show_data(t_fild *fild)
{
	printf("\n%10s %10s %10s %10s %10s %10s\n",
	"ID", "SIZE", "ALIGNMENT", "BOLD", "ITALICS", "UNDERLINED");
	printf("%10u %10u ", fild->id, fild->size);
	printf("%10s ", alig[fild->alig]);
	printf("%10s ", fild->bld > 0 ? ENB : DIS);
	printf("%10s ", fild->itl > 0 ? ENB : DIS);
	printf("%10s\n", fild->unl > 0 ? ENB : DIS);
}

static void				ft_quit(int val, const char *message)
{
	puts(message);
	puts(BYE);
	exit(val);
}

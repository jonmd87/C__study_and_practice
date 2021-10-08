//**************************************************************************** /
//                                                                            */
//                        #' ,#,    #    #  #.  .`#  #==,    .*.  + + +       */
// ~~~CREATED~~~         #  #   #  # #  #  # *.* #  #   #   *._.*    +        */
// ~~~~~BY~~~~~~    #. .#  #   #  #   ##  #     #  #  ,#    ,' ',   +         */
// ~<<jonmd87>>~     ###    '#'  #    #  #     #  #==*       *.*   +          */
//                                                                            */
//**************************************************************************** /
//
// header file 
//
//

#include <stdio.h>

int     main_mode = -1;
double	distance;
double	fuel_consumption;

void    ft_putchar(char c);
void    ft_putstr(char *str);
void    set_mode(int *n);
void    get_info(void);
void    show_info(void);

#define GL "galons"
#define L "litrs"
#define M "miles"
#define KM "kilometrs"

void    set_mode(int *n)
{
	if (*n == 0 || *n == 1)
		main_mode = *n;
	else 
		printf("!!!WRONG MODE!!!\n using  mode %s\n",
					 main_mode == 0 ? "[euro]" : "[USA]");
}

void    get_info(void)
{
	double dist = 0;
	double fuel = 0;
	
	while (getchar() != '\n');
	printf("please enter distance in %s\n", main_mode == 0 ? KM : M);
	scanf("%lf", &dist);
	while (getchar() != '\n');
	while (dist <= 0)
	{
		ft_putstr("only positive mumber!!!\n");
		printf("enter distance in %s\n", main_mode == 0 ? KM : M);
		scanf("%lf", &dist);
		while (getchar() != '\n');
	}
	printf("now enter fuel_consumption in %s\n", main_mode == 0 ? L : GL);
	scanf("%lf", &fuel);
	while (getchar() != '\n');
	while (fuel <= 0)
	{
		ft_putstr("only positive mumber!!!\n");
		printf("enter fuel consumption in %s\n", main_mode == 0 ? L : GL);
		scanf("%lf", &fuel);
		while (getchar() != '\n');
	}
	distance = dist;
	fuel_consumption = fuel;
}

void    show_info(void)
{
	if (main_mode == 0)
	{
		ft_putstr("\nmode [euro]\n");
		printf("way - %.2lf fuel_consumption - %.2lf\n", distance, fuel_consumption);
		printf("fuel consumption = %.2lf litrs on 100 km\n",
		fuel_consumption/distance * 100);
	}
	else if (main_mode == 1)
	{
		ft_putstr("\nmode [USA]\n");
		printf("way - %.2lf fuel_consumption = %.2lf\n", distance, fuel_consumption);
		printf("on one gallon of fuel you proedesh %.2lf\n",
		distance/fuel_consumption);
	}
}

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 12:25:05 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 10:42:46 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>      ////////////////////////////////////////////////////////////DELETE


int		main(void)
{

	int		c;
	int		val;

	c = 34;
	val = 0;


puts("UNSIGNED___@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
puts("1___________________________________________");
val = printf(" M (%%8.5, 0); Return : %d\n", ft_printf("[%8.5u]", 0));
val = printf(" S (%%8.5, 0); Return : %d\n",    printf("[%8.5u]", 0));
puts("2__________________________________________");
val = printf(" M (%%-8.5, 0); Return : %d\n", ft_printf("[%-8.5u]", 0));
val = printf(" S (%%-8.5, 0); Return : %d\n",    printf("[%-8.5u]", 0));
puts("3__________________________________________");
val = printf(" M (%%-8.5, 1); Return : %d\n", ft_printf("[%-8.5u]", 1));
val = printf(" S (%%-8.5, 1); Return : %d\n",    printf("[%-8.5u]", 1));
puts("4__________________________________________");
val = printf(" M (%%+8.5, 7); Return : %d\n", ft_printf("[%+8.5u]", 7));
val = printf(" S (%%+8.5, 7); Return : %d\n",    printf("flag '+' results in undefined behavior with 'u' conversion specifier"));
puts("5__________________________________________");
val = printf(" M (%%8.5, 7); Return : %d\n", ft_printf("[%8.5u]", 7));
val = printf(" S (%%8.5, 7); Return : %d\n",    printf("[%8.5u]", 7));

puts("6__________________________________________");
val = printf(" M (%%-5.0u, 0); Return : %d\n", ft_printf("[%-5.0u]", 0));
val = printf(" S (%%-5.0u, 0); Return : %d\n",    printf("[%-5.0u]", 0));
puts("6-A__________________________________________");
val = printf(" M (%%5.0u, 0); Return : %d\n", ft_printf("[%5.0u]", 0));
val = printf(" S (%%5.0u, 0); Return : %d\n",    printf("[%5.0u]", 0));
puts("7__________________________________________");
val = printf(" M (%%.*u,-1 0); Return : %d\n", ft_printf("[%.*u]", -1, 0));
val = printf(" S (%%.*u,-1 0); Return : %d\n",    printf("[%.*u]", -1, 0));
puts("8__________________________________________");
val = printf(" M (%%.*u,1 0); Return : %d\n", ft_printf("[%.*u]", 1, 0));
val = printf(" S (%%.*u,1 0); Return : %d\n",    printf("[%.*u]", 1, 0));
puts("8-A__________________________________________");
val = printf(" M (%%2.*u,1 0); Return : %d\n", ft_printf("[%2.*u]", 1, 0));
val = printf(" S (%%2.*u,1 0); Return : %d\n",    printf("[%2.*u]", 1, 0));
puts("9__________________________________________");
val = printf(" M (%%.*u,-3 0); Return : %d\n", ft_printf("[%.*u]", -3, 0));
val = printf(" S (%%.*u,-3 0); Return : %d\n",    printf("[%.*u]", -3, 0));
puts("10!@#$%^&*__________________________________________");
val = printf(" M (%%5.*u,-3 0); Return : %d\n", ft_printf("[%5.*u]", -3, 0));
val = printf(" S (%%5.*u,-3 0); Return : %d\n",    printf("[%5.*u]", -3, 0));
puts("11__________________________________________");
val = printf(" M (%%u, 0); Return : %d\n", ft_printf("[%u]", 0));
val = printf(" S (%%u, 0); Return : %d\n",    printf("[%u]", 0));
puts("12__________________________________________");
val = printf(" M (%%-u, 0); Return : %d\n", ft_printf("[%-u]", 0));
val = printf(" S (%%-u, 0); Return : %d\n",    printf("[%-u]", 0));
puts("12-A__________________________________________");
val = printf(" M (%%.u, 0); Return : %d\n", ft_printf("[%.u]", 0));
val = printf(" S (%%.u, 0); Return : %d\n",    printf("[%.u]", 0));
puts("12-B__________________________________________");
val = printf(" M (%%.*u, 0, 0); Return : %d\n", ft_printf("[%.*u]", 0, 0));
val = printf(" S (%%.*u, 0, 0); Return : %d\n",    printf("[%.*u]", 0, 0));
puts("12-C__________________________________________");
val = printf(" M (%%.0u, 0); Return : %d\n", ft_printf("[%.0u]", 0));
val = printf(" S (%%.0u, 0); Return : %d\n",    printf("[%.0u]", 0));
puts("12-D__________________________________________");
val = printf(" M (%%0.0u, 0); Return : %d\n", ft_printf("[%0.0u]", 0));
val = printf(" S (%%0.0u, 0); Return : %d\n",    printf("[%0.0u]", 0));
puts("12-E__________________________________________");
val = printf(" M (%%2.0u, 0); Return : %d\n", ft_printf("[%2.0u]", 0));
val = printf(" S (%%2.0u, 0); Return : %d\n",    printf("[%2.0u]", 0));
puts("13__________________________________________");
val = printf(" M (%%-.1u, 0); Return : %d\n", ft_printf("[%-.1u]", 0));
val = printf(" S (%%-.1u, 0); Return : %d\n",    printf("[%-.1u]", 0));
puts("14__________________________________________");
val = printf(" M (%%-5.1u, 0); Return : %d\n", ft_printf("[%-5.1u]", 0));
val = printf(" S (%%-5.1u, 0); Return : %d\n",    printf("[%-5.1u]", 0));
puts("15__________________________________________");
val = printf(" M (%%5.1u, 0); Return : %d\n", ft_printf("[%5.3u]", 0));
val = printf(" S (%%5.1u, 0); Return : %d\n",    printf("[%5.3u]", 0));
puts("16__________________________________________");
val = printf(" M (%%5.1u, 0); Return : %d\n", ft_printf("[%5.3u]", 0));
val = printf(" S (%%5.1u, 0); Return : %d\n",    printf("[%5.3u]", 0));
puts("17__________________________________________");
val = printf(" M (%%.u, 0); Return : %d\n", ft_printf("[%.u]", 0));
val = printf(" S (%%.u, 0); Return : %d\n",    printf("[%.u]", 0));
puts("18__________________________________________");
val = printf(" M (%%.-1u, 0); Return : %d\n", ft_printf("[%.*u]", -1, 0));
val = printf(" S (%%.-1u, 0); Return : %d\n",    printf("[%.*u]", -1, 0));
puts("19__________________________________________");
val = printf(" M (%%05u, 43); Return : %d\n", ft_printf("[%05u]", 43));
val = printf(" S (%%05u, 43); Return : %d\n",    printf("[%05u]", 43));
puts("20__________________________________________");
val = printf(" M (%%8.3u, 8375)); Return : %d\n", ft_printf("[%8.3u]", 8375));
val = printf(" S (%%8.3u, 8375)); Return : %d\n",    printf("[%8.3u]", 8375));

puts("0___________________________________________");
	printf(" M i[(*)+10.4i] Return : %d\n", ft_printf("[%+*.*i]", 10, 4, c));
	printf(" S i[(*)+10.4i] Return : %d\n",    printf("[%+*.*i]", 10, 4, c));

puts("1____________________________________________");
val = ft_printf("M[%--- 5.3i] [%%--- 5.3i]", c);
printf("return = %i\n", val);
	val = printf("S[%--- 5.3i] [%%--- 5.3i]", c);
printf("return = %i\n", val);

puts("1-A____________________________________________");
val = ft_printf("M[%--- 05.3i] [%%--- 05.3i]", c);
printf("return = %i\n", val);
	val = printf("main.c:48:22: error: flag '0' is ignored when flag '-' is present [-Werror,-Wformat]");
printf("return = %i\n", val);
puts("1-B____________________________________________");
val = ft_printf("M[%-+-- 05.3i] [%%-+-- 05.3i]", c);
printf("return = %i\n", val);
	val = printf("main.c:52:22: error: flag ' ' is ignored when flag '+' is present [-Werror,-Wformat]");
printf("return = %i\n", val);

puts("2____________________________________________");
 val = ft_printf("[%-+5.3i] [%%-+5.3i]", c);
printf("return = %i\n", val);
	val = printf("[%-+5.3i] [%%-+5.3i]", c);
printf("return = %i\n", val);

puts("2-A____________________________________________");
 val = ft_printf("[%+10.0i] [%%+10.0i](0)", 0);
printf(" M return = %i\n", val);
	val = printf("[%+10.0i] [%%+10.0i](0)", 0);
printf(" S return = %i\n", val);

puts("2-B____________________________________________");
 ft_printf("[%+0.0i] [%%+1.0i](0)", 0);
printf(" M return = %i\n", val);
	val = printf("[%+0.0i] [%%+1.0i](0)", 0);
printf(" S return = %i\n", val);

puts("2-C____________________________________________");
 ft_printf("[%+.0i] [%%+.0i](0)", 0);
printf("return = %i\n", val);
	val = printf("[%+.0i] [%%+.0i](0)", 0);
printf("return = %i\n", val);

puts("3____________________________________________");
 val =ft_printf("[%-+5.3i] [%%--+5.3i(c == -23)]", c*-1);
printf("return = %i\n", val);
   val = printf("[%-+5.3i] [%%--+5.3i(c == -23)]", c*-1);
printf("return = %i\n", val);

puts("4____________________________________________");
 val =ft_printf("[%-+5.3i] [%%-+5.3i]", c);
printf("return = %i\n", val);
   val =printf("[%-+5.3i] [%%-+5.3i]", c);
printf("return = %i\n", val);

puts("5____________________________________________");
puts("widh - yes // accur - no");
 val =ft_printf("[%--- 5i] [%%--- 5i]", c);
printf("return = %i\n", val);
   val =printf("[%--- 5i] [%%--- 5i]", c);
printf("return = %i\n", val);

puts("6____________________________________________");
 val =ft_printf("[%- --5i] [%%- --5i]", c);
printf("return = %i\n", val);
   val =printf("[%- --5i] [%%- --5i]", c);
printf("return = %i\n", val);
puts("7____________________________________________");
 val =ft_printf("[%-+5i] [%%--+5i]", c);
printf("return = %i\n", val);
   val =printf("[%-+5i] [%%--+5i]", c);
printf("return = %i\n", val);

puts("8____________________________________________");
 val =ft_printf("[%-+5i] [%%--+5i(c == -23)]", c*-1);
printf("return = %i\n", val);
  val = printf("[%-+5i] [%%--+5i(c == -23)]", c*-1);
printf("return = %i\n", val);

puts("9____________________________________________");
 val = ft_printf("[% 5i] [%% 5i]", c);
printf("return = %i\n", val);
   val = printf("[% 5i] [%% 5i]", c);
printf("return = %i\n", val);


puts("10____________________________________________");
 val =ft_printf("[% 5i] [%% 5i]", c);
printf("return = %i\n", val);
   val =printf("[% 5i] [%% 5i]", c);
printf("return = %i\n", val);
puts("11____________________________________________");
 val =ft_printf("[%-+5i] [%%-+5i]", c);
printf("return = %i\n", val);
  val = printf("[%-+5i] [%%-+5i]", c);
printf("return = %i\n", val);

puts("12____________________________________________");
puts("accur > width");
 val =ft_printf("[%--- 5.7i] [%%--- 5.7i]", c);
printf("return = %i\n", val);
  val = printf("[%--- 5.7i] [%%--- 5.7i]", c);
printf("return = %i\n", val);
puts("13____________________________________________");
 val =ft_printf("[%- --5.7i] [%%- --5.7i]", c);
printf("return = %i\n", val);
  val = printf("[%- --5.7i] [%%- --5.7i]", c);
printf("return = %i\n", val);
puts("14____________________________________________");
 val =ft_printf("[%-+5.7i] [%%--+5.7i]", c);
printf("return = %i\n", val);
  val = printf("[%-+5.7i] [%%--+5.7i]", c);
printf("return = %i\n", val);
puts("15____________________________________________");
 val =ft_printf("[%-+5.7i] [%%--+5.7i(c == -23)]", c*-1);
printf("return = %i\n", val);
  val = printf("[%-+5.7i] [%%--+5.7i(c == -23)]", c*-1);
printf("return = %i\n", val);
puts("16____________________________________________");
 val =ft_printf("[% 05.7i] [%% 05.7i]", c);
printf("return = %i\n", val);
   printf("[% 05.7i] [%% 05.7i]", c);
printf("return = %i\n", val);

puts("17____________________________________________");
 val =ft_printf("[% 5.7i] [%%05.7i]", c);
printf("return = %i\n", val);
  val = printf("[% 5.7i] [%%05.7i]", c);
printf("return = %i\n", val);

puts("17-A-____________________________________________");
 val =ft_printf("[%05.7i] [%%05.7i]", c);
printf("return = %i\n", val);
  val = printf("[%05.7i] [%%05.7i]", c);
printf("return = %i\n", val);

puts("18____________________________________________");
 val =ft_printf("[% 5.7i] [%% 5.7i]", c);
printf("return = %i\n", val);
   val =printf("[% 5.7i] [%% 5.7i]", c);
printf("return = %i\n", val);
puts("19____________________________________________");
 val =ft_printf("[%-+5.7i] [%%-+5.7i]", c);
printf("return = %i\n", val);
   val =printf("[%-+5.7i] [%%-+5.7i]", c);
printf("return = %i\n", val);
puts("20___________________________________________");
 val =ft_printf(" M i[+0.3i] Return : %d\n", ft_printf("[%+0.3i]", c * -1));
printf("return = %i\n", val);
	val =printf(" S i[+0.3i] Return : %d\n",    printf("[%+0.3i]", c * -1));
printf("return = %i\n", val);
puts("21___________________________________________");
 val =ft_printf(" M (%%-5.i, 0); Return : %d\n", ft_printf("[%-5.i]", 0));
	val =printf(" S (%%-5.i, 0) Return : %d\n",    printf("[%-5.i]", 0));
puts("22____________________________________________");
 val =ft_printf(" M (%%08.3i, -8473); Return : %d\n", ft_printf("[%08.3i]", -8473));
	val =printf(" S (%%08.3i, -8473) Return : %d\n",    printf("[%08.3i]", -8473));
puts("22____________________________________________");
 val =ft_printf(" M (%%04i, -532); Return : %d\n", ft_printf("[%04i]", -532));
	val =printf(" S (%%04i, -532) Return : %d\n",    printf("[%04i]", -532));


puts("ADRES___@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");


char	*a01 = "AAAAAA";
char	*a02 = "BBBBBB";
char	*a03 = "CCCCCC";
char	*a08 = "HHHHHH";
char	*a09 = "JJJJJJ";
char	*a10 = "school21";
char	*a11 = "GREATE";
char	*a12 = NULL;

puts("1____________________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%32p]",&a01));
val =    printf(" S (%%p) Return : %d\n",     printf("[%32p]",&a01));

puts("2____________________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%16p]",&a02));
val =    printf(" S (%%p) Return : %d\n",     printf("[%16p]",&a02));

puts("_3___________________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%0p]",&a03));
val =    printf(" S (%%p) Return : %d\n",     printf("[%p]",&a03));

puts("__4__________________________________________");
puts("********************************************************");
val = ft_printf(" M (%%5%%); Return : %d\n", ft_printf("[%5%]"));
val =    printf(" S (%%5%%) Return : %d\n",     printf("[%5%]"));
puts("********************************************************");

puts("___5_________________________________________");
puts("********************************************************");
val = ft_printf(" M (%%-5%%); Return : %d\n", ft_printf("[%-5%]"));
val =    printf(" S (%%-5%%) Return : %d\n",     printf("[%-5%]"));
puts("********************************************************");

puts("____6________________________________________");
puts("********************************************************");
val = ft_printf(" M (%%05%%); Return : %d\n", ft_printf("[%05%]"));
val =    printf(" S (%%05%%) Return : %d\n",     printf("[%05%]"));
puts("********************************************************");

puts("_____7_______________________________________");
puts("********************************************************");
val = ft_printf(" M (%%-05%%); Return : %d\n", ft_printf("[%-05%]"));
val =    printf(" S (%%-05%%) Return : %d\n",     printf("[%-05%]"));
puts("********************************************************");
puts("_____7-a_______________________________________");
puts("********************************************************");
val = ft_printf(" M (%%+05%%); Return : %d\n", ft_printf("[%+05%]"));
val =    printf(" S (%%+05%%) Return : %d\n",     printf("[%+05%]"));
puts("********************************************************");
puts("_____7-B_______________________________________");
puts("********************************************************");
val = ft_printf(" M (%% 05.3%%); Return : %d\n", ft_printf("[% 05.3%]"));
val =    printf(" S (%% 05.3%%) Return : %d\n",     printf("[% 05.3%]"));
puts("********************************************************");
puts("_____7-C_______________________________________");
puts("********************************************************");
val = ft_printf(" M (%%.10%%); Return : %d\n", ft_printf("[%.10%]"));
val =    printf(" S (%%.10%%) Return : %d\n",     printf("[%.10%]"));
puts("********************************************************");

puts("______8______________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%32p]",&a08));
val =    printf(" S (%%p) Return : %d\n",     printf("[%32p]",&a08));

puts("9____________________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%32p]",&a09));
val =    printf(" S (%%p) Return : %d\n",     printf("[%32p]",&a09));

puts("10____________________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%32p]",&a10));
val =    printf(" S (%%p) Return : %d\n",     printf("[%32p]",&a10));

puts("__11__________________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%32p]",&a11));
val =    printf(" S (%%p) Return : %d\n",     printf("[%32p]",&a11));

puts("____12________________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%32p]",&a12));
val =    printf(" S (%%p) Return : %d\n",     printf("[%32p]",&a12));
puts("____13________________________________________");
val = ft_printf(" M (%%p); Return : %d\n", ft_printf("[%3p%5%]",&a12));
val =    printf(" S (%%p) Return : %d\n",     printf("[%3p%5%]",&a12));
puts("__14__________________________________________");
puts("********************************************************");
val = ft_printf(" M (%%5%%); Return : %d\n", ft_printf("[%5%]"));
val =    printf(" S (%%5%%) Return : %d\n",     printf("[%5%]"));
puts("********************************************************");
ft_printf("[%0+.3i]\n", 34);
printf("[%0+.3i]\n", 34);



puts("ADRES___@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
puts("********************************************************");

puts("1____________________________________________");
val = ft_printf(" M (Hello %%s.)(John); Return : %d\n", ft_printf("[hello, %s.", "John"));
val =    printf(" S (Hello %%s)(John); Return : %d\n",     printf("[hello, %s.", "John"));
puts("2____________________________________________");
val = ft_printf(" M ((Hello %%10.3s)(John);); Return : %d\n", ft_printf("[hello, %10.3s.]", "gavin"));
val =    printf(" S ((Hello %%10.3s.)(John);) Return : %d\n",     printf("[hello, %10.3s.]", "gavin"));
puts("3____________________________________________");
val = ft_printf(" M ((Hello %%0.7s)(John);); Return : %d\n", ft_printf("[hello, %0.7s.]", "gavin"));
val =    printf(" S ((Hello %%0.7s)(John);) Return : %d\n",     printf("[hello, %.7s.]", "gavin"));
puts("4____________________________________________");
val = ft_printf(" M ((Hello %%5.0s)(John);); Return : %d\n", ft_printf("[hello, %5.0s.]", "gavin"));
val =    printf(" S ((Hello %%5.0s)(John);) Return : %d\n",     printf("[hello, %5.0s.]", "gavin"));
puts("5____________________________________________");
val = ft_printf(" M ((Hello %%5.s)(John);); Return : %d\n", ft_printf("[hello, %5s.]", "gavin"));
val =    printf(" S ((Hello %%5.s)(John);) Return : %d\n",     printf("[hello, %5s.]", "gavin"));
puts("6____________________________________________");
val = ft_printf(" M ((Hello %%5.s)(NULL);); Return : %d\n", ft_printf("[hello, %5s.]", a12));
val =    printf(" S ((Hello %%5.s)(NULL);) Return : %d\n",     printf("[hello, %5s.]", a12));
puts("********************************************************");
puts("C 1____________________________________________");
val = ft_printf(" M ((Hello %%c)(NULL);); Return : %d\n", ft_printf("[hello, %c.]", *a01));
val =    printf(" S ((Hello %%c)(NULL);) Return : %d\n",     printf("[hello, %c.]", *a01));
puts("********************************************************");
puts("NEGATIVE____________________________________________");
int	*ss = NULL;
val = ft_printf(" M ((Hello %%p) (NULL);); Return : %d\n", ft_printf("%.*p", -1, ss));
val =    printf(" S ((Hello %%p) (NULL);); Return : %d\n",    printf("%*p", -1, ss));
puts("********************************************************");
puts("7____________________________________________");

	int     a = 0;
	int     b = 5;
    int     j = -12;
	char    cc = 'a';
	int     d = 2147483647;
    int     e = -2147483648;
    int     i = 8;
    int     k = 123456789;
    int     l = 0;
    int     m = -12345678;



puts("******BBBBB**************************************************");
ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, cc, a, b, e, a,     b, d));

   printf(" --- Return : %d\n",    printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, cc, a, b, e, a,     b, d));
puts("***AAA*****************************************************");
ft_printf(" --- Return : %d\n", ft_printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
   printf(" --- Return : %d\n",    printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));

puts("***AAA* [-1 & 0] ****************************************************");
ft_printf(" --- Return : %d\n", ft_printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
   printf(" --- Return : %d\n",    printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));

puts("********************************************************");
ft_printf(" -M-- Return : %d\n",
 ft_printf("%.*x", a, j));
   printf(" -S-- Return : %d\n",
    printf("%.*x", a, j));
puts("********************************************************");
ft_printf(" -M-- Return : %d\n",
 ft_printf("%.*x", a, 0));
   printf(" -S-- Return : %d\n",
    printf("%.*x", a, 0));

a = -1;
b = 0;
puts("***1***[-1.0]**************************************************");
ft_printf(" --M- Return : %d\n", ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
   printf(" -S-- Return : %d\n",    printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
puts("**2*******[-1.0]***********************************************");
			ft_printf(" -M-- Return : %d\n", ft_printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			   printf(" --S- Return : %d\n",    printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
puts("*****2********[-1.0]*******************************************");
ft_printf(" -M-- Return : %d\n", ft_printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
   printf(" --S- Return : %d\n",    printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));

puts("****REMAKE[AA]*******************************************");
ft_printf(" -M-- Return : %d\n", ft_printf("[%++0++0.*i], [%---------*.*X]",  b, j, a, b, j));
   printf(" -M-- Return : %d\n",    printf("[%++0++0.*i], [%---------*.*X]",  b, j, a, b, j));
puts("****REMAKE[-1.2]*******************************************");
ft_printf(" -M-- Return : %d\n", ft_printf("[%-*.*x], [%---------*.*X]", a, b, j, a, b, j));
   printf(" -M-- Return : %d\n",    printf("[%-*.*x], [%---------*.*X]", a, b, j, a, b, j));
puts("****REMAKE[BB]*******************************************");
ft_printf("[ MY more per %%%i %%%%%]\n", 10);
//printf("[STD more per %%%i %%%%%]\n", 10);
ft_printf("[ MY more per %%%i %%%%%]\n", 10);
ft_printf("[%]\n");
//printf("[%]\n");
puts("10!@#$%^&*__________________________________________");
printf(" M (%%5.*u,-3 0); Return : %d\n", ft_printf("[%5.*u]", -3, 0));
puts("\n\n##########################################___THE_____END___###################################\n\n");
	return (0);
}

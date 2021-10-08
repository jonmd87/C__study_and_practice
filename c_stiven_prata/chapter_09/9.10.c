//
//
// программа запрашивает целое число и выводит на экран все числа 
// фибоначчи до введенного числа
// программа интерактивна и работает пока не введено целое число
//
//
//
// created by jonmd87
//
//


#include <stdio.h>


int main()
{
	int x;
	int last_num;
	int ent_num;
	
	printf("pleaase enter the integer number!:\n");
	
	
	while( (scanf("%d", &ent_num)) == 1);
	{
	      if(ent_num <1)
	      {
	      	printf("only integer and positive numbers!!!\n");
	      	continue;
	      }	
	     
	       else
	      {
	           for(x = 0, last_num = 0;  x < ent_num; x++ )
	              {
	                  printf("%d\n", x);
	                  last_num = (x + last_num);
	              	                  	                  
	              }
	      }
	      
	      printf("enter another number or \"q\" to exit\n");
	      continue;
	}
	
	
	return 0;
}






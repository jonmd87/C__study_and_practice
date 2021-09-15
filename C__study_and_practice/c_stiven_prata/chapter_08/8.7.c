//
//
//
// программа запрашивает отработанные часы и предлагает выбрать ставку.
// затем выводит на экран сумму зП, налог и конечную суммую
// программа интерактивна.
//
//
// created by jonmd87
//
//

#include <stdio.h>
#include<ctype.h>


#define ONE 8.75        // salary rate
#define TWO 9.33		// salary rate
#define THRE 10.00		// salary rate
#define FOUR 11.20		// salary rate
#define STDWEEK 40      // standart work week
#define TP1 300         // first tax point
#define TP2 450         // second tax point
#define TR1 0.15        // % tax rate ,from first 300$
#define TR2 0.2         // % from next 150$
#define TR3 0.05        // % from remaining amount.
#define TAX1 (TR1* TP1) // tax from first 300$
#define TAX2 (TAX1+ ((TP2-TP1) * TR2))  // a tax of more than 300 to 450


   // ВСе раьботает но если ввести букву цикл бесконечен


char menu(void);

int main(void)
{
	int hours;

	double salary;
	double hourly_pay; 
	double tax_rate;

	char choose;


	printf("******************************************************\n");
	printf("Choose your salary rate:\n");
	printf("\na) $8.75/hour\nb) $9.33/hour\nc) $10.00/hour\nd) $11.20/hour\ne)EXIT\n");
	printf("******************************************************\n");

	while( (choose = getchar()) != 'e' )
	{

		while(getchar() != '\n');

			switch(choose)

					{
						case 'a':
						hourly_pay = ONE;
						printf("%.2lf\n", ONE);
						break;
						
						case 'b':
						hourly_pay = TWO;
						printf("%.2lf\n", TWO);
						break;

						case 'c':
						hourly_pay = THRE;
						printf("%.2lf\n", THRE);
						break;

						case 'd':
						hourly_pay = FOUR;
						printf("%.2lf\n", FOUR);
						break;

						case 'e':
						printf("GOOD BUY!!!!\n");
						return 0;


					}



	   if(choose == 'a' || choose == 'b' || choose == 'c' || choose == 'd' )
       {

	            printf("Now entre hours work.\n");
	            scanf("%i", &hours);

	                if(hours > STDWEEK)
						salary = ( STDWEEK * hourly_pay ) + ( (hours - STDWEEK) * hourly_pay);
	                else
		                salary = hours * hourly_pay;




	       if( salary <= TP1 )
	   	      tax_rate = salary * TR1;
	       else if( salary > TP1 && salary <= TP2)
	   	      tax_rate = TAX1 + ( ( salary - TP1 ) * TR2 );
	       else 
	   	      tax_rate = TAX2 + (( salary - TP2 ) * TR3);

		             

	       printf("\n\n\n    Your work time is %i.\n ", hours);
	            printf("    Your salary rate is %.2lf.\n", hourly_pay );
                printf("    Your salary is %.2lf.\n", salary);
                printf("    Tax rate is %.2lf.\n", tax_rate);
                printf("    Your net profit is %.2lf.\n\n\n", salary - tax_rate);
	            printf("******************************************************\n");
	            printf("Choose your salary rate:\n");          
	            printf("\na) $8.75/hour\nb) $9.33/hour\nc) $10.00\nd) $11.20\ne)EXIT\n");         
	            printf("******************************************************\n\n\n");
	            while(getchar() != '\n');
	            continue;
	            

       	}

       else	
	   		{    
	   			    printf("You need enter the a, b, c, d, or e for exit!!!!!\n");					
	  				continue;
	   		}			
	   	

	}    

	


}

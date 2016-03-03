#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CERO 48
#define UNO 49
typedef enum
{ false, true } bool;
int
main (void)
{
  char input[100]; //= { '1', '1', '1' };
  bool fin = false;
  int inicio = 1, final = 5, actual = inicio, contador = 0;
printf("Ingresa tu cadena\tNOTA: Recuerda que la cadena solo puede tener '0' y '1'\n\n");
  fgets(input, 100, stdin);
  while (fin == false)
    {	
    	if( contador > (int) strlen(input)){
    		fin = true;
    		break;
    	}
    	//primera transición
	      if (actual == 1)
	      {
	      		if (input[contador]== CERO)
	      		{
	      			printf("q1(0)->q2 ");
	      			actual=2;
	      		}
	      		if (input[contador] == UNO)
	      		{
	      			printf("q1(1)->q4 ");
	      			actual=4;
	      		}
	      		contador++;
	      		continue;
	      }
	     //primera transición

	     //segunda transición
	      if (actual == 2)
	      {
	      		if (input[contador]== CERO)
	      		{
	      			printf("q2(0)->q2 ");
	      			actual=2;
	      		}
	      		if (input[contador] == UNO)
	      		{
	      			printf("q2(1)->q3 ");
	      			actual=3;
	      		}
	      		contador ++; 
	      		continue;
	      }
	     //segunda transición 

	     //tercera transición
	      if (actual == 3)
	      {
	      		if (input[contador]== CERO)
	      		{
	      			printf("q3(0)->q2 ");
	      			actual=2;
	      		}
	      		if (input[contador] == UNO)
	      		{
	      			printf("q3(1)->q5 ");
	      			actual=5;
	      		}
	      		contador ++; 
	      		continue;
	      }
	     //tercera transición 

	     //cuarta transición
	      if (actual == 5)
	      {
	      		if (input[contador]== CERO)
	      		{
	      			printf("q5(0)->q2 ");
	      			actual=2;
	      		}
	      		if (input[contador] == UNO)
	      		{
	      			printf("q5(1)->q4 ");
	      			actual=4;
	      		}
	      		contador ++; 
	      		continue;
	      }
	     //cuarta transición 

	     //quinta transición
	      if (actual == 4)
	      {
	      		if (input[contador]== CERO)
	      		{
	      			printf("q4(0)->q2 ");
	      			actual=2;
	      		}
	      		if (input[contador] == UNO)
	      		{
	      			printf("q4(1)->q4 ");
	      			actual=4;
	      		}
	      		contador ++; 
	      		continue;
	      }
	     //quinta transición 
    }
if(actual == final)
	printf("\nLa cadena es correcta\n");
else
	printf("\tNo es estado final\n");
	printf("\nCadena no aceptada\n");
  return 0;
}
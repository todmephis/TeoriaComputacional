#include <stdio.h>
#include <string.h>
#define CERO 48
#define UNO 49
typedef enum
{ false, true } bool;
bool checkString (char[]);

bool
checkString (char input[])
{
  int contador = 0, checks = contador;
  while (contador < (int) strlen (input))
    {
      if ((input[contador] == CERO) || (input[contador] == UNO))
	{
	  checks++;
	}
      else if ((input[contador] != CERO) || (input[contador] != UNO))
	{
	  checks = (-1);
	  break;
	}			//scriptkiddie1 | todmephis.tk
      contador++;
    }
  if (contador == checks)
    {
      return true;
    }
  else if (contador == -1)
    {
      return false;
    }
}

int
main (void)
{
  char input[100];
  bool fin = false;
  int inicio = 1, final = 5, actual = inicio, contador = 0;
  printf
    ("\n\t\t\tIngresa tu cadena\n\tNOTA: Recuerda que la cadena solo puede tener '0' y '1'\n Cadena: ");
  while (!checkString (input))
    {
      fgets (input, 100, stdin);
      printf ("\n");
      if (!checkString (input))
	printf ("Cadena invalida, intentalo de nuevo.\nCadena: ");
    }
  while (fin == false)
    {
      if (contador > (int) strlen (input))
	{
	  fin = true;
	  break;
	}
      //primera transición
      if (actual == 1)
	{
	  if (input[contador] == CERO)
	    {
	      printf ("q1(0)->q2 ");
	      actual = 2;
	    }
	  if (input[contador] == UNO)
	    {
	      printf ("q1(1)->q4 ");
	      actual = 4;
	    }
	  contador++;
	  continue;
	}			// fin primera transición
      //segunda transición
      if (actual == 2)
	{			//scriptkiddie1 | todmephis.tk
	  if (input[contador] == CERO)
	    {
	      printf ("q2(0)->q2 ");
	      actual = 2;
	    }
	  if (input[contador] == UNO)
	    {
	      printf ("q2(1)->q3 ");
	      actual = 3;
	    }
	  contador++;
	  continue;
	}			//fin segunda transición 
      //tercera transición
      if (actual == 3)
	{
	  if (input[contador] == CERO)
	    {
	      printf ("q3(0)->q2 ");
	      actual = 2;
	    }
	  if (input[contador] == UNO)
	    {
	      printf ("q3(1)->q5* ");
	      actual = 5;
	    }
	  contador++;
	  continue;
	}			//fin tercera transición 
      //cuarta transición
      if (actual == 5)
	{
	  if (input[contador] == CERO)
	    {
	      printf ("q5(0)->q2 ");
	      actual = 2;
	    }
	  if (input[contador] == UNO)
	    {
	      printf ("q5(1)->q4 ");
	      actual = 4;
	    }			//scriptkiddie1 | todmephis.tk
	  contador++;
	  continue;
	}			//fin cuarta transición 
      //quinta transición
      if (actual == 4)
	{
	  if (input[contador] == CERO)
	    {
	      printf ("q4(0)->q2 ");
	      actual = 2;
	    }
	  if (input[contador] == UNO)
	    {
	      printf ("q4(1)->q4 ");
	      actual = 4;
	    }
	  contador++;
	  continue;
	}			//fin quinta transición   
    }
  if (actual == final)
    printf ("\n\n\tLa cadena es correcta\n\n");
  else
    {				//scriptkiddie1 | todmephis.tk
      printf ("\t->No es estado final\n");
      printf ("\nCadena no aceptada\n");
    }
  return 0;
}
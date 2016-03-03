#include "funciones.h"
int
concats (char U[], char V[])
{
  char U2[20];
  char V2[20];
  strcpy (U2, U);
  strcpy (V2, V);
  printf ("U+V = %s\n", strcat (U, V));
  printf ("V+U = %s\n", strcat (V2, U2));
  return 0;
}

int
prefix (char U[], int pre, int len)
{
  int contador = 0;
  if (pre > len)
    {
      printf ("Error\n");
    }
  else if (pre == len)
    {
      printf (LAMBDA "\n");
    }
  else if (pre == 0)
    {
      printf ("%s\n", U);
    }
  else
    {
      /*printf("Prefijo\n");
         printf("w = %s\n", U); */
      for (contador = 0; contador < (len - pre); contador++)
	{
	  printf ("%c", U[contador]);
	}
      printf ("\n");
    }
  return 0;
}

int
subfix (char U[], int sub, int len)
{
  int contador = 0;
  if (sub > len)
    {
      printf ("Error\n");
    }
  else if (sub == len)
    {
      printf (LAMBDA "\n");
    }
  else if (sub == 0)
    {
      printf ("%s\n", U);
    }
  else
    {
      /*printf("Prefijo\n");
         printf("w = %s\n", U); */
      for (contador = sub; contador < len; contador++)
	{
	  printf ("%c", U[contador]);
	}
      printf ("\n");
    }
  return 0;
}

int
substring (char U[], int pre, int sub, int len)
{
  int contador = 0;
  if (pre > len || sub > len || pre + sub > len)
    {
      printf ("Error\n");
    }
  else if (pre == len || sub == len || pre + sub == len)
    {
      printf (LAMBDA "\n");
    }
  else if (sub == 0)
    {
      printf ("%s\n", prefix (U, pre, len));
    }
  else if (pre == 0)
    {
      printf ("%s\n", subfix (U, sub, len));
    }
  else
    {
      /*printf("Prefijo\n");
         printf("w = %s\n", U); */
      for (contador = sub; contador < (len - pre); contador++)
	{
	  printf ("%c", U[contador]);
	}
      printf ("\n");
    }
  return 0;
}

int
inverse (char U[], int len)
{
  int contador = 0;
  for (contador = len; contador >= 0; contador--)
    {
      printf ("%c", U[contador]);
    }
  printf ("\n");
  return 0;
}

int
strpow (char U[], int pown, int len)
{
  int contador = 0, contador1 = 0;
  if (pown == 0)
    printf (LAMBDA "\n");
  else if (pown > 0)
    {
      while (contador1 < pown)
	{
	  for (contador = 0; contador < len; contador++)
	    {
	      printf ("%c", U[contador]);
	    }
	  contador = 0;
	  contador1++;
	}
      printf ("\n");
    }
  else if (pown < 0)
    {
      pown = pown * (-1);
      while (contador1 < pown)
	{
	  for (contador = len; contador >= 0; contador--)
	    {
	      printf ("%c", U[contador]);
	    }
	  contador = len;
	  contador1++;
	}
      printf ("\n");
    }
  return 0;
}

int
subsec (char U[], char b[], int u_len)
{
char a[100], character;
char * ptr;
int contador=0;
strcpy(a, U);
while(contador< 2/*(int)strlen(b)*/){
	character=b[contador];
  ptr=strchr(U, character);
  strncpy(ptr, " ", 1);
contador++;
}
printf("%s\n", U);
return 0;
}

int
menu (char U[], char V[], int u_len, int v_len)
{
	char b[100];
  int opt = 0, aux1 = 0, aux2 = 0, conti = 0, flag1 = 0, flag2 = 0;
  printf ("1. Concatenar\n");
  printf ("2. Prefijo\n");
  printf ("3. Subfijo\n");
  printf ("4. Subcadena\n");
  printf ("5. Inversa\n");
  printf ("6. Potencia\n");
  printf ("7. Subsecuencia\n");
  scanf ("%d", &opt);
  switch (opt)
    {
    case 1:
      concats (U, V);
      printf ("1. Mostrar menu / 2. Salir\n");
      scanf ("%d", &conti);
      if (conti == 1)
	{
	  system ("clear");
	  menu (U, V, u_len, v_len);
	}
      else
	exit (1);
      break;
    case 2:
      printf ("Número del prefijo:\n");
      if (scanf ("%d", &aux1) == 1)
	{
	  prefix (U, aux1, u_len);
	  prefix (V, aux1, v_len);
	  printf ("1. Mostrar menu / 2. Salir\n");
	  scanf ("%d", &conti);
	  if (conti == 1)
	    {
	      system ("clear");
	      menu (U, V, u_len, v_len);
	    }
	  else
	    exit (1);
	}
      else
	{
	  printf ("Error fatal\n");
	  printf ("Ingresa un dígito entre 0-9\n");
	}
      break;
    case 3:
      printf ("Número del subfijo:\n");
      if (scanf ("%d", &aux1) == 1)
	{
	  subfix (U, aux1, u_len);
	  subfix (V, aux1, v_len);
	  printf ("1. Mostrar menu / 2. Salir\n");
	  scanf ("%d", &conti);
	  if (conti == 1)
	    {
	      system ("clear");
	      menu (U, V, u_len, v_len);
	    }
	  else
	    exit (1);
	}
      else
	{
	  printf ("Error fatal\n");
	  printf ("Ingresa un dígito entre 0-9\n");
	}
      break;
    case 4:
      printf ("Valor del prefijo: ");
      flag1 = scanf ("%d", &aux1);
      printf ("Valor del subfijo: ");
      flag2 = scanf ("%d", &aux2);
      if (flag1 == 1 && flag2 == 1)
	{
	  substring (U, aux1, aux2, u_len);
	  substring (V, aux1, aux2, v_len);
	  printf ("1. Mostrar menu / 2. Salir\n");
	  scanf ("%d", &conti);
	  if (conti == 1)
	    {
	      system ("clear");
	      menu (U, V, u_len, v_len);
	    }
	  else
	    exit (1);
	}
      else
	{
	  printf ("Error fatal\n");
	  printf ("Ingresa un dígito entre 0-9\n");
	}
      break;
    case 5:
      inverse (U, u_len);
      inverse (V, v_len);
      printf ("1. Mostrar menu / 2. Salir\n");
      scanf ("%d", &conti);
      if (conti == 1)
	{
	  system ("clear");
	  menu (U, V, u_len, v_len);
	}
      else
	exit (1);
      break;
    case 6:
      printf ("Indica la potencia: \n");
      scanf ("%d", &aux1);
      strpow (U, aux1, u_len);
      strpow (V, aux1, u_len);
      printf ("1. Mostrar menu / 2. Salir\n");
      scanf ("%d", &conti);
      if (conti == 1)
	{
	  system ("clear");
	  menu (U, V, u_len, v_len);
	}
      else
	exit (1);
      break;
    case 7:
    printf("Ingresa cadena para la subsecuencia\n");
    gets(b);
       subsec(U, b, u_len);
    break;
    default:
      printf ("Opción no válida\n");
      menu (U, V, u_len, v_len);
      break;
    }
}
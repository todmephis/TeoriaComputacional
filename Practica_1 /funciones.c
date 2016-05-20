#include "funciones.h"

void flush_in() 
{ 
int ch; 
while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
} 

void
concats (char U[], char V[])
{
  char U2[20];
  char V2[20];
  strcpy (U2, U);
  strcpy (V2, V);
  printf ("U+V = %s\n", strcat (U, V));
  printf ("V+U = %s\n", strcat (V2, U2));
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
        for(contador = pre; contador < len; contador ++)
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
        for(contador =0; contador < (len-sub); contador++)
	{
	  printf ("%c", U[contador]);
	}
      printf ("\n");
    }
    return 0;
}

void
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
      for (contador = sub; contador < (len - pre); contador++)
	{
	  printf ("%c", U[contador]);
	}
      printf ("\n");
    }
}

void
inverse (char U[], int len)
{
  int contador = 0;
  for (contador = len; contador >= 0; contador--)
    {
      printf ("%c", U[contador]);
    }
  printf ("\n");
}

void
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
}

void
subsec (char U[], int u_len, char b[], int b_len)
{
char character=' ';
char * ptr=NULL, * temp=NULL;
int contador=0, index=0, aux=0;
while(contador< b_len){
	character=b[contador];
  ptr=strchr(U, character);
  strncpy(ptr, " ", 1);
contador++;
}
for(contador=0; contador < (int)strlen(U); contador++){
if(U[contador]==' ')
  aux++;
}
temp=(char *)malloc(aux * sizeof(char));
for(index=0; index < aux; index++){
  temp[index]='#';
}
index=0;

for(contador=0; contador < (int)strlen(U); contador++){
  if(U[contador]!=' '){
  temp[index]=U[contador];
  index++;
}
}
printf("%s\n", temp);
free(temp);
}

void
menu (char U[], char V[], int u_len, int v_len)
{
	char * u_temp=NULL, * v_temp=NULL, b[20];
  int opt = 0, aux1 = 0, aux2 = 0, conti = 0, flag1 = 0, flag2 = 0, b_len=0;
  printf ("1. Concatenar\n");
  printf ("2. Prefijo\n");
  printf ("3. Subfijo\n");
  printf ("4. Subcadena\n");
  printf ("5. Inversa\n");
  printf ("6. Potencia\n");
  printf ("7. Subsecuencia\n");
  printf("8.  Salir\n");
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
	  substring (V, aux1, aux2, v_len);//creo que hay que voltear el aux1 y aux2
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
    flush_in();
    u_temp=(char *)malloc(u_len * sizeof(char));
    v_temp=(char *)malloc(v_len * sizeof(char));
    if(u_temp==NULL || v_temp==NULL){
      perror("Error de memoria\n");
      exit(1);
    }
    strcpy(u_temp, U);
    strcpy(v_temp, V);
printf("Ingresa cadena para obtener la subsecuencia\n");
fgets(b, sizeof(b), stdin);
b_len=( (int)strlen(b)-1);
printf("%d\n", b_len);
       subsec(u_temp, u_len, b, b_len);
       subsec(v_temp, v_len, b, b_len);
       free(u_temp);
       free(v_temp);
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
    case 8:
    exit(1);
    break;
    default:
      printf ("Opción no válida\n");
      menu (U, V, u_len, v_len);
      break;
    }
}
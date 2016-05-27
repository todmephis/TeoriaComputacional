#include "funciones.h"

void
set_str (int rows, char **mat, int n_language)
{
  char p_auxiliar[COLUMNS];
  int auxiliar = 0, s_len = 0;
  for (auxiliar = 0; auxiliar < rows; auxiliar++)
    {
      printf ("Ingresa la cadena número %d del Lenguaje_%d: ",
	      (auxiliar + 1), n_language);
      fgets (p_auxiliar, COLUMNS, stdin);
      s_len = (int) strlen (p_auxiliar);
      p_auxiliar[s_len - 1] = '\0';
      strcpy (mat[auxiliar], p_auxiliar);
      s_len = 0;
    }
}

void
union_lang (char **language1, int filas1, char **language2, int filas2)
{
  char **language_r = NULL;
  int total_filas = filas1 + filas2, aux = 0, index_r = 0, aux2 = 0;
  bool flag = true;

  language_r = (char **) malloc (total_filas * sizeof (char *));
  if (language_r == NULL)
    {
      perror ("Error while allocating memory");
      exit (1);
    }
  for (aux = 0; aux < total_filas; aux++)
    {
      language_r[aux] = (char *) malloc (COLUMNS * sizeof (char));
      if (language_r == NULL)
	{
	  perror ("Error while allocating memory");
	  exit (1);
	}
    }

  for (aux = 0; aux < filas1; aux++)
    {
      strcpy (language_r[aux], language1[aux]);
    }

  index_r = aux;
  for (aux = 0; aux < filas2; aux++)
    {
      for (aux2 = 0; aux2 < index_r; aux2++)
	{
	  if (strcmp (language2[aux], language_r[aux2]) == 0)
	    {
	      flag = false;
	      break;
	    }
	  if (strcmp (language2[aux], language_r[aux2]) != 0)
	    {
	      flag = true;
	    }
	}
      if (flag == true)
	{
	  strcpy (language_r[index_r], language2[aux]);
	  index_r++;
	}
    }
  printf ("L1 U L2={");
  for (aux = 0; aux < index_r; aux++)
    {
      printf ("%s, ", language_r[aux]);
    }
  printf ("\b\b}\n");
  free (language_r);
}

void
concat_lang (char **language1, int filas1, char **language2, int filas2,
	     int nl1, int nl2)
{
  char **language_r = NULL;
  int total_filas = filas1 * filas2, aux = 0, aux2 = 0, poss = 0;
  language_r = (char **) malloc (total_filas * sizeof (char *));
  if (language_r == NULL)
    {
      perror ("Error while allocating memory");
      exit (1);
    }
  for (aux = 0; aux < total_filas; aux++)
    {
      language_r[aux] = (char *) malloc (COLUMNS * sizeof (char));
      if (language_r == NULL)
	{
	  perror ("Error while allocating memory");
	  exit (1);
	}			//programado con amor por Ivan :v 
    }
  poss = aux = aux2 = 0;
  while (aux < total_filas)
    {
      for (aux2 = 0; aux2 < filas2; aux2++)
	{
	  strcpy (language_r[aux], language1[poss]);
	  aux++;
	}
      poss++;
    }
  aux = aux2 = 0;
  while (aux < total_filas)
    {
      for (aux2 = 0; aux2 < filas2; aux2++)
	{
	  strcat (language_r[aux], language2[aux2]);
	  aux++;
	}

    }
  printf ("L%dL%d={", nl1, nl2);
  for (aux = 0; aux < total_filas; aux++)
    {
      printf ("%s, ", language_r[aux]);
    }
  printf ("\b\b}\n");
  free (language_r);
}

void
inversa_lang (char **language, int filas, int nl)
{
  char **len_inverso = NULL;
  char cadena[COLUMNS];
  int aux = 0;

  len_inverso = (char **) malloc (filas * sizeof (char *));
  if (len_inverso == NULL)
    {
      perror ("Error while allocating memory");
      exit (1);
    }
  for (aux = 0; aux < filas; aux++)
    {
      len_inverso[aux] = (char *) malloc (COLUMNS * sizeof (char));
      if (len_inverso == NULL)
	{
	  perror ("Error while allocating memory");
	  exit (1);
	}
    }
  for (aux = 0; aux < filas; aux++)
    {
      strcpy (cadena, language[aux]);
      reverse_string (cadena);
      strcpy (len_inverso[aux], cadena);
    }
  printf ("L%d^-1={", nl);
  for (aux = 0; aux < filas; aux++)
    {
      printf ("%s, ", len_inverso[aux]);
    }
  printf ("\b\b}\n");
  free (len_inverso);
}

void
pow_lang (char **language, int filas, int nl, int potencia)
{
  char **language_r = NULL;
  char cadena[COLUMNS];
  int aux = 0, aux2 = 0;
  language_r = (char **) malloc (filas * sizeof (char *));
  if (language_r == NULL)
    {
      perror ("Error while allocating memory");
      exit (1);
    }
  for (aux = 0; aux < filas; aux++)
    {
      language_r[aux] = (char *) malloc (COLUMNS * sizeof (char));
      if (language_r == NULL)
	{
	  perror ("Error while allocating memory");
	  exit (1);
	}
    }
  if (potencia == 0)
    printf (LAMBDA "\n");
  else if (potencia > 0)
    {

      if (potencia == 1)
	{
	  printf ("L%d^%d={", nl, potencia);
	  for (aux = 0; aux < filas; aux++)
	    {
	      printf ("%s, ", language[aux]);
	    }
	  printf ("\b\b}\n");
	}

      else if (potencia > 1)
	{
	  for (aux = 0; aux < filas; aux++)
	    {
	      strcpy (language_r[aux], language[aux]);
	    }
	  for (aux = 0; aux < potencia - 1; aux++)
	    {
	      for (aux2 = 0; aux2 < filas; aux2++)
		{
		  strcpy (cadena, language[aux2]);
		  strcat (language_r[aux2], cadena);
		}
	    }
	  printf ("L%d^%d={", nl, potencia);
	  for (aux = 0; aux < filas; aux++)
	    {
	      printf ("%s, ", language_r[aux]);
	    }
	  printf ("\b\b}\n");
	}

    }
  else if (potencia < 0)
    {
      for (aux = 0; aux < filas; aux++)
	{
	  strcpy (cadena, language[aux]);
	  reverse_string (cadena);
	  strcpy (language_r[aux], cadena);
	}
      for (aux = 0; aux < -1 * (potencia + 1); aux++)
	{
	  for (aux2 = 0; aux2 < filas; aux2++)
	    {
	      strcpy (cadena, language[aux2]);
	      reverse_string (cadena);
	      strcat (language_r[aux2], cadena);
	    }
	}
      printf ("L%d^%d={", nl, potencia);
      for (aux = 0; aux < filas; aux++)
	{
	  printf ("%s, ", language_r[aux]);
	}
      printf ("\b\b}\n");
    }
}

void
reverse_string (char *string)
{
  int length, c;
  char *begin, *end, temp;

  length = string_length (string);
  begin = string;
  end = string;

  for (c = 0; c < length - 1; c++)
    end++;

  for (c = 0; c < length / 2; c++)
    {
      temp = *end;
      *end = *begin;
      *begin = temp;

      begin++;
      end--;
    }
}

int
string_length (char *pointer)
{
  int c = 0;

  while (*(pointer + c) != '\0')
    c++;

  return c;
}

void
main_menu (char **lang_1, int filas_lan_1, char **lang_2, int filas_lan_2)
{
  int opc = 0, conti = 0, potencia = 0;
  printf ("1. Union.\n");
  printf ("2. Concatenación.\n");
  printf ("3. Inversa de un lenguaje.\n");
  printf ("4. Potencia de un lenguaje.\n");
  printf ("5. Salir\n");
  printf ("Digita la opción deseada: ");
  scanf ("%d", &opc);
  switch (opc)
    {
    case 1:
      union_lang (lang_1, filas_lan_1, lang_2, filas_lan_2);
      printf ("1. Mostrar menu / 2. Salir\n");
      scanf ("%d", &conti);
      if (conti == 1)
	{
	  system ("clear");
	  main_menu (lang_1, filas_lan_1, lang_2, filas_lan_2);
	}
      else
	exit (1);
      break;
    case 2:
      concat_lang (lang_1, filas_lan_1, lang_2, filas_lan_2, 1, 2);
      concat_lang (lang_2, filas_lan_2, lang_1, filas_lan_1, 2, 1);
      printf ("1. Mostrar menu / 2. Salir\n");
      scanf ("%d", &conti);
      if (conti == 1)
	{
	  system ("clear");
	  main_menu (lang_1, filas_lan_1, lang_2, filas_lan_2);
	}
      else
	exit (1);
      break;
    case 3:
      inversa_lang (lang_1, filas_lan_1, 1);
      inversa_lang (lang_2, filas_lan_2, 2);
      printf ("1. Mostrar menu / 2. Salir\n");
      scanf ("%d", &conti);
      if (conti == 1)
	{
	  system ("clear");
	  main_menu (lang_1, filas_lan_1, lang_2, filas_lan_2);
	}
      else
	exit (1);
      break;
    case 4:
      printf ("Ingresa la potencia deseada:\n");
      scanf ("%d", &potencia);
      pow_lang (lang_1, filas_lan_1, 1, potencia);
      pow_lang (lang_2, filas_lan_2, 2, potencia);
      printf ("1. Mostrar menu / 2. Salir\n");
      scanf ("%d", &conti);
      if (conti == 1)
	{
	  system ("clear");
	  main_menu (lang_1, filas_lan_1, lang_2, filas_lan_2);
	}
      else
	exit (1);
      break;
    case 5:
      exit (1);
      break;
    default:
      printf ("Opción inválida. Intenta de nuevo\n");
      main_menu (lang_1, filas_lan_1, lang_2, filas_lan_2);
      break;
    }
}

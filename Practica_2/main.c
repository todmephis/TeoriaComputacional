#include "funciones.h"

int
main (void)
{
  char **lang_1 = NULL, **lang_2 = NULL;
  const int columnas = COLUMNS;
  int filas_lan_1 = 0, filas_lan_2 = 0;	//número de cadenas de cada lenguaje
  int auxiliar = 0;
//lenguaje1
  printf ("Ingresa el número de cadenas que tendrá el \"Lenguaje_1\": ");
  scanf ("%d", &filas_lan_1);
  lang_1 = (char **) malloc (filas_lan_1 * sizeof (char *));
  if (lang_1 == NULL)
    {
      perror ("Error while allocating memory");
      exit (1);
    }
  for (auxiliar = 0; auxiliar < filas_lan_1; auxiliar++)
    {
      *(lang_1 + auxiliar) = (char *) malloc (columnas * sizeof (char));
      if (lang_1 == NULL)
	{
	  perror ("Error while allocating memory");
	  exit (1);
	}
    }
//lenguaje2
  printf ("Ingresa el número de cadenas que tendrá el \"Lenguaje_2\": ");
  scanf ("%d", &filas_lan_2);
  lang_2 = (char **) malloc (filas_lan_2 * sizeof (char *));
  if (lang_2 == NULL)
    {
      perror ("Error while allocating memory");
      exit (1);
    }
  for (auxiliar = 0; auxiliar < filas_lan_2; auxiliar++)
    {
      *(lang_2 + auxiliar) = (char *) malloc (columnas * sizeof (char));
      if (lang_2 == NULL)
	{
	  perror ("Error while allocating memory");
	  exit (1);
	}
    }
  flush_in ();
  set_str (filas_lan_1, lang_1, 1);
  set_str (filas_lan_2, lang_2, 2);
  main_menu (lang_1, filas_lan_1, lang_2, filas_lan_2);
  return 0;
}

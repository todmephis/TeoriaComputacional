#include "funciones.h"
int
main (void)
{
  char U[100], V[100];
  int u_len = 0, v_len = 0;
  printf ("Operaciones con cadenas\n");
  printf ("Ingresa U\n");
  gets (U);
  printf ("Ingresa V\n");
  gets (V);
  u_len = (int) strlen (U);
  v_len = (int) strlen (V);
  printf("%d\n", u_len);
  printf("%d\n", u_len);
  menu (U, V, u_len, v_len);
  return 0;
}

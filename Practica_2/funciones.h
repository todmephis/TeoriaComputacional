#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "limpiabf.h"
#define COLUMNS 40
#define LAMBDA "\u03BB"

typedef enum
{ false, true } bool;

void set_str (int, char **, int);	//el primer entero es el número de cadenas, se le pasa la matriz y el número del lenguaje correspondiente
void union_lang (char **, int, char **, int);	//lenguaje 1 y el número de cadenas del lenguaje 1 (char **, int)
void concat_lang (char **, int, char **, int, int, int);	//los dos últimos int representan el orden de los lenguajes (L1 y L2)
void inversa_lang (char **, int, int);	//lenguaje, su número de cadenas del lenguaje, el número de lenguaje que es.
void pow_lang (char **, int, int, int);	//lenguaje, su número de cadenas, número del lenguaje, la potencia a la que se va a elevar.
void reverse_string (char *);
int string_length (char *);
void main_menu (char **, int, char **, int);	//menú principal del programa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#define LAMBDA "\u03BB"
#define OMEGA "\u03C9"
void flush_in(void);
void concats (char[], char[]);
int prefix (char[], int, int);
int subfix (char[], int, int);
void substring (char[], int, int, int);
void inverse (char[], int);
void strpow (char[], int, int);
void subsec (char[], int, char[], int);
void menu (char[], char[], int, int);
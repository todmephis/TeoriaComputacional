#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#define LAMBDA "\u03BB"
#define OMEGA "\u03C9"
int concats (char[], char[]);
//concats espera dos cadenas de char
int prefix (char[], int, int);
int subfix (char[], int, int);
int substring (char[], int, int, int);
int inverse (char[], int);
int strpow (char[], int, int);
int subsec (char[], char[]);
int menu (char[], char[], int, int);

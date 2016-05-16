#ifndef STRINGS
#define STRINGS

#include <stdio.h>
char input(char paths[]);
int slen(char paths[]);
int schr(char paths[], char delim);
int stok(char paths[], char delim, char *ptr[]);
int checksmbl(char paths[], char *ptr[]);
void printstring(char paths[], char *ptr[]);
#endif

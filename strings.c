#include <stdio.h>
#include <stdlib.h>

#define MAXPATH 261
#define MAXCNT 10
#define MAXSIZE (MAXPATH*MAXCNT)

//Input function
char input(char paths[])
{
    char delim;

    printf("input delim (+, or <space>): ");
    scanf("%c%*c",&delim);

    if( delim == ' '){
        printf("delim is <space>\n");
    }else

        if( delim != '+' ){
            printf ("delim isn't correct. Autoset delim is '+'\n");
            delim = '+';
        }

    printf("input Windows paths (URL format): ");
    fgets(paths,MAXSIZE,stdin);

    printf("delim is %c\n",delim);
    printf("path string is: %s\n",paths);
    return delim;
}

/* :::::::::: PROCESS FUNCTIONS ::::::::::
 1. String length (slen) */

int slen(char paths[])
{
//  obratit' vnimanie na index i-1 !!!!!
    int i, len;
    for (i = 0; paths[i] != '\0'; i++);
        len=i-1;
    return len-1;
}

// 2. Search of character (schr)
int schr(char paths[], char delim)
{
    int i, idx=-1;
    for(i=0; (paths[i] != '\0') && (paths[i] != delim); i++);
        if(paths[i] == delim)
            idx = i;
    return idx;
}

// 3. String partition on fields (stok)

int stok(char paths[], char delim, char *ptr[])
{
    char *suf = paths;
    int i, j = 1;
    ptr[0] = paths;
    while((i = schr(suf, delim)) >= 0){
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    return j-1; //OBRATIT' VNIMANIE!!!!!!!
}

void print_str(char paths[], char *ptr[])   //ФИЛЬТР ПО "\\....." ???
{
    int i=(slen(paths))+3;
    while (paths[i] != '\0'){
        printf ("%c", paths[i]);
        i++;
    }
    printf("\n");
    if (paths[0] != '\\')
        printf("\nERROR: not URL path!\n");
}




/* :::::::::: CHECK FUNCTIONS ::::::::::  */
// 1. Check of symbols

int checksmbl(char paths[], char *ptr[])
{
    char nsym[6] = {'<', '>', '?', '*', '|', '"'};
    int i, j;
    for (i = 0; i <= slen(paths); i++){
        if( schr(nsym, paths[i]) >=  0 ){
            fprintf(stderr, "\nERROR: Found illegal symbol! (<, >, ?, |, *)\n ");
            j = i;
            break;
        }else{
            j = -1;
        }
    }
    return j;
}




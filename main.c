#include <stdio.h>
#include "strings.h"

#define MAXPATH 261
#define MAXCNT 10
#define MAXSIZE (MAXPATH*MAXCNT)

int main()
{
	int length, delim_pos, ptrs;
	char paths[MAXSIZE], delim, *ptr[MAXCNT];

   
	    delim=input(paths);
       

//Length of pahts
	length=slen(paths);
	printf("String length: %d\n", length);

//Search of delim
	delim_pos=schr(paths, delim);
	printf("position of delim: %d\n", delim_pos);

//Paths partition
	ptrs=stok(paths, delim, ptr);
	printf("quantity of fields: %d\n", ptrs);
return 0;
}

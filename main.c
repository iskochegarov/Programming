#include <stdio.h>
#include "strings.h"

#define MAXPATH 261
#define MAXCNT 10
#define MAXSIZE (MAXPATH*MAXCNT)

int main()
{
	int length, delim_pos, ptrs, chk_result;
	char paths[MAXSIZE], delim, *ptr[MAXCNT];
//input
    delim = input(paths);
       
//Length of pahts
	length = slen(paths);
	printf("String length: %d\n", length);

//Search of delim
	delim_pos = schr(paths, delim);
	printf("Position of delim: %d\n", delim_pos);

//Paths partition
	ptrs = stok(paths, delim, ptr);
	printf("Quantity of fields: %d\n", ptrs);

//Check symbols
    chk_result = checksmbl(paths, ptr);

//print test string
    printstring(paths, ptr);
    
return 0;
}

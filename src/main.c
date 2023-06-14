 
#include <stdio.h>
#include <stdlib.h>
#include "dstring.h"

int main()
{
    dstring* dstr = DSTRING();
    puts("\nadd");
    dstradds(dstr,"s-a-b");


    printf("\n---  %d",dstrfind(dstr,"p"));

    for(int i=0;i<dstrlen(dstr);i++)
    {
        printf("\n%c\n",dstrat(dstr,i));
    }

    puts(dstrtos(dstr));
    puts("\nfree");
    dstrfree(dstr);
    return 0;
}

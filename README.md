# dstring.h
dynamic string in c

### Example

```c
#include <stdio.h>
#include <stdlib.h>
#include "dstring.h"

int main()
{
    dstring* dstr = DSTRING();
    dstrcpy(dstr,"welcome");
    dstradds(dstr," all");

    puts("\n");
    for(int i=0;i<dstrlen(dstr);i++)
    {
        printf("%c",dstrat(dstr,i));
    }
    printf("\nfind e to %d pos",dstrfind(dstr,"e"));
    puts("\n");

    dstrcpy(dstr,"hello word");
    dstrsubn(dstr,6,4);
    puts(dstrtos(dstr));
    dstrfree(dstr);
    return 0;
}
```

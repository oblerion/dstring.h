#include "dstring.h"
// ---- private function
struct e_string* ESTRING()
{
    struct e_string* estr = (struct e_string*) malloc(sizeof(struct e_string));
    estr->car=0;
    estr->ptr_d=NULL;
    estr->ptr_u=NULL;
    return estr;
}

// ----- public function
dstring* DSTRING()
{
    dstring* dstr = (dstring*)malloc(sizeof(dstring));
    dstr->ptr= NULL;
    dstr->size=0;
    return dstr;
}
void dstrprint(dstring* dstr)
{
    struct e_string* estr = dstr->ptr;
    while(estr!=NULL)
    {
        char pu =0;
        char pd=0;
        if(estr->ptr_u==NULL) pu=0;
        else pu=1;

        if(estr->ptr_d==NULL) pd=0;
        else pd=1;
        printf("\npd %d pu %d car %c",pd,pu,estr->car);
        estr = estr->ptr_u;
    }
}

int dstrlen(dstring* dstr)
{
    if(dstr==NULL) return -1;
    return dstr->size;
}

void dstraddc(dstring* dstr, char c)
{
    if(dstr==NULL) return;
    struct e_string* estr = dstr->ptr;
    if(estr==NULL)
    {
        dstr->ptr = ESTRING();
        dstr->ptr->car = c;
        dstr->size++;
    }
    else
    {
        while(estr!=NULL)
        {
            if(estr->ptr_u==NULL)
            {
                estr->ptr_u = ESTRING();
                estr->ptr_u->car=c;
                estr->ptr_u->ptr_d = estr;
                dstr->size++;
                break;
            }
            estr = estr->ptr_u;
        }
    }

}
void dstradds(dstring* dstr, char* s)
{
    for(int i=0;i<strlen(s);i++)
    {
        dstraddc(dstr,s[i]);
    }
}
void dstrdel(dstring* dstr, int pos)
{
    if(pos>=dstrlen(dstr)) return;
    struct e_string* estr = dstr->ptr;
    int ipos=0;

    while(estr!=NULL)
    {
        if(ipos==pos)
        {
            if(estr->ptr_d==NULL &&
                estr->ptr_u!=NULL)
            {
                estr->ptr_u->ptr_d=NULL;
                dstr->ptr = estr->ptr_u;
                free(estr);
                dstr->size--;
            }
            else if(estr->ptr_d!=NULL &&
                    estr->ptr_u!=NULL)
            {
                estr->ptr_d->ptr_u = estr->ptr_u;
                free(estr);
                dstr->size--;
            }
            else if(estr->ptr_d!=NULL &&
                    estr->ptr_u==NULL)
            {
                estr->ptr_d->ptr_u = NULL;
                free(estr);
                dstr->size--;
            }
            break;
        }
        ipos++;
        estr = estr->ptr_u;
    }
}

char dstrat(dstring* dstr, int id)
{
    struct e_string* estr = dstr->ptr;
    int ipos=0;
    while(estr!=NULL)
    {
        if(id==ipos)
        {
            return estr->car;
        }
        ipos++;
        estr = estr->ptr_u;
    }
    return 0;
}

void dstrcpy(dstring* dstr, char* s)
{
    dstrclear(dstr);
    dstradds(dstr,s);
}

void dstrsub(dstring* dstr, int pos)
{
    if(pos>dstr->size || pos<=0) return;
    struct e_string* estr;
    int ipos=0;
    while(dstr->ptr!=NULL)
    {
        if(ipos==pos) break;
        estr = dstr->ptr->ptr_u;
        estr->ptr_d=NULL;
        free(dstr->ptr);
        dstr->ptr = estr;
        dstr->size--;
        ipos++;
    }
}

void dstrsubn(dstring* dstr, int pos, int n)
{
    dstrsub(dstr,pos);
    while(dstr->size>n)
    {
        dstrdel(dstr,n);
    }
}

char* dstrtos(dstring* dstr)
{
    char* tstr = (char*) malloc(dstr->size);
    tstr[0]='\0';
    for(int i=0;i<dstrlen(dstr);i++)
    {
        sprintf(tstr,"%s%c",tstr,dstrat(dstr,i));
    }
    return tstr;
}

void dstrclear(dstring* dstr)
{
    if(dstr==NULL) return;
    struct e_string* estr;
    while(dstr->ptr!=NULL)
    {
        estr = dstr->ptr->ptr_u;
        free(dstr->ptr);
        dstr->ptr = estr;
    }
    dstr->size=0;
    dstr->ptr=NULL;
}

int dstrfind(dstring* dstr, char* s)
{
    char* tstr = dstrtos(dstr);
    int tofnd = strlen(s);
    int fnd = 0;
    int pos = -1;
    for(int i=0;i<dstrlen(dstr);i++)
    {
        if(tstr[i]==s[fnd])
        {
            if(fnd==0 && pos==-1)
                pos=i;
            if(fnd==tofnd-1)
                return pos;
            fnd++;

        }
        else
        {
            pos=-1;
            fnd=0;
        }
    }
    return -1;
}


void dstrfree(dstring* dstr)
{
    if(dstr==NULL) return;
    struct e_string* estr;
    while(dstr->ptr!=NULL)
    {
        estr = dstr->ptr->ptr_u;
        free(dstr->ptr);
        dstr->ptr = estr;
    }
    free(dstr);
}

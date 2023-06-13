#ifndef DSTRING_H
#define DSTRING_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct e_string
{
    char car;
    struct e_string* ptr_d;
    struct e_string* ptr_u;
};

typedef struct
{
    int size;
    struct e_string* ptr;
}dstring;

dstring* DSTRING();
void dstrprint(dstring* dstr);
int dstrlen(dstring* dstr);
void dstraddc(dstring* dstr,char c);
void dstradds(dstring* dstr,char* s);
void dstrdel(dstring* dstr,int pos);
char dstrat(dstring* dstr,int id);
void dstrcpy(dstring* dstr,char* s);
void dstrsub(dstring* dstr,int pos);
void dstrsubn(dstring* dstr,int pos,int n);
char* dstrtos(dstring* dstr);
int dstrfind(dstring* dstr,char* s);
void dstrclear(dstring* dstr);
void dstrfree(dstring* dstr);
#endif

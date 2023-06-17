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

dstring* DSTRING();                         //constructor
void dstrprint(dstring* dstr);              //debug print string
int dstrlen(dstring* dstr);                 //get lenght 
void dstraddc(dstring* dstr,char c);        //add char to end
void dstradds(dstring* dstr,char* s);       //add string to end
void dstrdel(dstring* dstr,int pos);        //remove char at pos
char dstrat(dstring* dstr,int id);          //get char at id
void dstrcpy(dstring* dstr,char* s);        //clear and copy string
void dstrsub(dstring* dstr,int pos);        //dstr = all after pos
void dstrsubn(dstring* dstr,int pos,int n); //dstr = n char after pos 
char* dstrtos(dstring* dstr);               //create char* with dstr
int dstrfind(dstring* dstr,char* s);        //get pos of string s
void dstrclear(dstring* dstr);              //clear string
void dstrfree(dstring* dstr);               //free memory
#endif

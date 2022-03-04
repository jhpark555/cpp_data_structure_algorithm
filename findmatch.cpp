
#include <stdio.h>
#include <string.h>

void findmatch(char *p, char *t)
{
    int i,j;
    int plen,tlen;
    int flag=0;

    plen=strlen(p);  tlen=strlen(t);

    for ( i=0; i < plen; i++)
    {
        if( strncmp(&p[i],t,4)==0) {
            flag =i;
            printf("%c%c%c%c  %d\n",p[i],p[i+1],p[i+2],p[i+3], i);
            break;
        }

    }

    for(i=flag;i<4;i++) printf("%c ",p[i]);
}
int main()
{
    char *test="abaababbaba";
    char *t="abba";

    findmatch(test,t);
    printf("Hello World");

    return 0;
}

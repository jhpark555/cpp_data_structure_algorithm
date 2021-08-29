#include <stdio.h>

char zero_term(char *b)
{
    while(*b!='\0')
    b++;

   char c='A';
    *b=c;
   return *b;
}
int main()
{
    char x[]="hello";

    char r= zero_term(x);

    printf("%d ",r);

    return 0;
}

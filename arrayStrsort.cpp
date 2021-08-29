#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define swap(a,b)  ( a^=b^=a^=b )
void swap( char *a,char *b)
{
  char temp;
  temp=*b;
  *b=*a;
  *a=temp;
}

void bubble(char *input,char *output)
{
    int  i,j;

    int n=strlen(input)+1;

    //for( i=0; input[i]!='\0';i++)
    //for(j=0;j<n-input[i]-1;j++)
    for( i=0; i< n;i++)
    for(j=0;j< n-i-1;j++)
    {
      //  printf("%c ",input[j],input[j+1]);
      if(input[j]>input[j+1])  swap(&input[j],&input[j+1]);
    }

    for(i=0;i< n;i++)  {
      output[i]=input[i];
      //printf("%c ",output[i]);
    }
    output[i]='\0';

}
void sort_strings(int n, char *input[], char *output[])
{

   for (int i = 0; i < n; i++) {
        bubble(input[i],output[i]);
   }
}

int main(void)
{
    char *array[] = {
         "foo",
         "test"
     };

    int n = sizeof array / sizeof *array;
    char *output[n];

    for(int i=0;i< n; i++)
    {
      output[i]=(char*)malloc(sizeof(char));
    }

    //printf("size = %d \n",n);

    sort_strings(n, array, output);

    for (int i = 0; i < n; i++) {
        printf("%s ", output[i]);
    }
    return 0;
}

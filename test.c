#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void firstarr(char *arr,int n)
{
    int i;

   for(i=0;i<n;i++){
   arr[i]= arr[i]+1;
   //printf("%c ", arr[i]);

   }

}

int main()
{
   // int *arr=malloc(5);
    char arr[]="hello";
    int i;
    int n=strlen(arr);

   // for(i=0;i<5;i++) arr[i]=i;

    firstarr(arr,n);

    for(i=0;i<5;i++)
    printf("%c ",arr[i]);

    return 0;
}

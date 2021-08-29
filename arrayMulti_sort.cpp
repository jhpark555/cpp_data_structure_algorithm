#include <stdio.h>

#define swap(a,b)  ( a^=b^=a^=b )

void sort_strings(int n,char arr[][4],char output[][4] )
{

    int i,j,k;

    for(k=0;k< n; k++)
    {
      for( i=0 ; i< 4; i++ )
      for( j=0 ; j< 4-i-1 ; j++ )
      {
         //printf(" % d  %d  \n",arr[k][j],arr[k][j+1]);
          if(arr[k][j]>arr[k][j+1])
          {
              swap(arr[k][j],arr[k][j+1]);
          }
      }


     for(i=0;i<4;i++)
     {
         output[k][i]=arr[k][i];
        // printf(" %d  ",arr[k][i]);
     }
    }

}

int main(void)
{
    char array[][4] = {
      //  {2,6,7,10},
      //  {3,10,8,4}
      {'f','o','o'},
      {'t','e','s','t'}
     };


    int n = sizeof array / sizeof *array;
    char output[n][4];

    printf("size = %d \n",n);

    sort_strings(n, array, output);

    for(int k=0;k< n;k++)
    for (int i = 0; i < 4; i++) {
        printf("%c ", output[k][i]);
    }
    return 0;
}

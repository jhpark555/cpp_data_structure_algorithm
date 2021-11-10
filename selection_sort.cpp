
#include <stdio.h>
#include <stdlib.h>
// Xor swap condition should be a!=b.
#define swap(a,b)\
   if(a!=b){\
    ( a^=b^=a^=b);\
  }\

//void XorSwap(int *x, int *y)
//{
//  if (x != y)
//  {
//    *x ^= *y;
//    *y ^= *x;
//    *x ^= *y;
//  }
//}
//void swap(int *xp, int *yp)
//{
 //   int temp = *xp;
 //  *xp = *yp;
 //   *yp = temp;
//}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }

}
int main()
{

    int arr[]={5, 3, 6, 2, 10};
    int n=sizeof(arr)/sizeof(arr[0]);


    selectionSort(arr,n);

    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);

    return 0;
}

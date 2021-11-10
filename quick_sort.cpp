#include <iostream>
using namespace std;

#define swap(a,b) (a^=b^=a^=b)

int partition(int arr[],int low,int high)
{
   int pivot =arr[high];
   int i=(low-1), j;
   for(j=low; j<=high-1;j++)
   {
     if(arr[j]< pivot)
     {
       i++;
       swap(arr[i],arr[j]);
     }
   }
   swap(arr[i+1],arr[high]);
   return i+1;

}
void quicksort(int arr[], int low,int high)
{
  if(low< high)
  {
    int pivot=partition(arr,low,high);

    quicksort(arr,low,pivot-1);
    quicksort(arr,pivot+1,high);
  }
}
int main()
{
  int arr[]={10,7,8,9,1,5};
  int n= sizeof(arr)/sizeof(arr[0]);
  int i;

  quicksort(arr,0,n-1);
  cout<<"Sorted array: \n";

  for(i=0;i<n;i++) printf("%d ",arr[i]);
}

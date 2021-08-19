#include <iostream>
using namespace std;

int getCount(int arr[],int n)
{
  int i,j,k;
  int count=0;

  for( i=0;i <n; i++)
  {
    for(j=i+1;j<n;j++)
    {
       if(arr[j-1]>= arr[j]) break;
       ++count;
    }
  }

  return count;
}

int main()
{
  int arr[] = { 1, 2, 4, 4, 5 };
  //int arr[]={1,3,2};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "The total number of strictly increasing subarrays is "
     << getCount(arr, n);

  return 0;
}

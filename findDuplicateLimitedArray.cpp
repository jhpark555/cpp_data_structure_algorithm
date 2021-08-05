#include <iostream>
using namespace std;


int findDuplicate(int arr[],int n)
{
  bool visited[n];
  fill(visited,visited+n,0); //set every value in the array to 0

  int i;
  for(i=0;i<n;i++)
  {
    if(visited[arr[i]]++>=1) return arr[i];

    //visited[arr[i]] = true;
  }

  return -1;

}

int findDuplicatec(int arr[],int n)
{
  int visited[n] ={0};
  int i;

  for(i =0;i<n ; i++)
  {

    if(visited[arr[i]]++>=1) {
       return arr[i];
     }
  }
  return -1;
}
int main()
{
  int arr[]={1,2,3,4,4};
  int n= sizeof(arr)/sizeof(arr[0]);

  cout<<"The duplicate element is "<<findDuplicate(arr,n);

  return 0;
}

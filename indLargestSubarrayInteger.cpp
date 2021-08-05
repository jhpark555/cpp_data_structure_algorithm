#include <iostream>
using namespace std;


void findMaxSubarray(int arr[],int n,int *a, int *b)
{
  int i,j,k;
  int visited[n]={0};
  int l;
  int sum=0;
  int max=0;
  int start,end;
  int start1,end1;
  int maxmax=0;

  for(i =0; i< n; i++)
   for( j=i; j< n; j++)
    {
         sum=0; max=0;
         //printf("{");
         for(l=0;l<n;l++) visited[l]=0;
         for(k =i;k <=j ; k++)
         {
           if( visited[arr[k]]++ >=1) break;
          // else printf("%d ",arr[k]);
           sum +=arr[k];
           if(sum> max){
               max=sum;
               start=i; end=k;
             }
         }
        // printf("}");
        // printf("max=%d [%d %d]\n",max,start,end);
         if(max> maxmax) {
           start1 = start;
           end1=end;
           maxmax=max;
         }
    }
  //  printf("mxmax=%d [%d %d]",maxmax,start1,end1);
    *a=start1; *b=end1;
}
int main()
{
  int A[]={2,0,2,1,4,3,1,0};
  int n = sizeof(A)/sizeof(A[0]);
  int start,end;

  findMaxSubarray(A,n,&start,&end);

  printf(" Largest array : %d %d \n",start,end);
  return 0;
}

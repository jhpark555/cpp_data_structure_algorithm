#include <iostream>
#include<string.h>
using namespace std;

void removeDuplicate(char s[])
{
  int i=0,k=0;

  for(i=0; s[i]!='\0';i++)
  {
    if(s[i] !=s[i+1])
    {
      s[k++]=s[i];
    }
  }
  s[k]='\0';
}

int main()
{
  char s[]="AAABBCDDD";
  removeDuplicate(s);

  printf("%s \n",s);

  return 0;
}

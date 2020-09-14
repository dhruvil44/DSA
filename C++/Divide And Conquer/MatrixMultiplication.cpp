/*Author: Dhruvil Patel*/

#include<bits/stdc++.h>

using namespace std;

void MM (int a[],int b[],int n)
{
  if(n<=2)
  {
    c[0][0]=a[0][0]*b[0][0] + a[0][1]*b[1][0];
    c[0][1]=a[0][0]*b[0][1] + a[0][1]*b[1][1];
    c[1][0]=a[1][0]*b[0][0] + a[1][1]*b[1][0];
    c[1][1]=a[1][0]*b[0][1] + a[1][1]*b[1][1];
    return;
  }

   


}


int main()
{

  int a[4][4]={{1,2,3,4},{1,2,3,4},{1,1,1,1},{2,2,2,2}};

  int b[4][4]={{1,1,1,1},{2,2,2,2},{1,2,3,4},{3,3,3,3}};

  int c[][];

  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      cout<<a[i][j]<<" ";
    }
      cout<<endl;
  }


  return 0;
}

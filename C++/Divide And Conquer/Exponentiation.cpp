/*Author:Dhruvil Patel(DP)*/

#include<bits/stdc++.h>

using namespace std;

//calculate a^b in logn complexity
long long int expo(long long int a,long long int b)
{

  if(b==0)
  {
    return 1;
  }

  if(b==1)
  {
    return a;
  }

  if(b&1)
  {
    return (expo(a,b/2)*expo(a,b/2)*a);
  }
  else{
    return (expo(a,b/2)*expo(a,b/2));
  }

}


int main()
{

cout<<expo(2,5);


  return 0;
}

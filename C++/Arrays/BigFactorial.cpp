//Author: Dhruvil Patel

//Andrew was attempting a mathematics test where he needed to solve problems with factorials.
//One such problem had an answer which equaled 100! ,He wondered what would this number look like.
//He tried to calculate 100! On his scientific calculator but failed to get a correct answer.
//Can you write a code to help Andrew calculate factorials of such large numbers?

#include<bits/stdc++.h>

using namespace std;

void multiply(int res[], int &resSize, int x) {

  int carry=0;

  for(int i=0;i<resSize;i++) {
    int product = (res[i]*x)+carry;
    res[i] = product%10;
    carry = product/10;
  }

  while(carry) {
    res[resSize++] = carry%10;
    carry/=10;
  }

}

int main() {

  int n;
  cin>>n;

  int res[100000];
  int resSize=1;

  res[0]=1;

  for(int i=2;i<=n;i++) {
    multiply(res,resSize,i);
  }

  reverse(res,res+resSize);

  for(int i=0;i<resSize;i++) {
    cout<<res[i];
  }

  return 0;
}

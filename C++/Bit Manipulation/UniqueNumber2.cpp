//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given a set of integers where each number occurs twice except for two numbers.Find those 2 numbers.
//Example : [1,2,3,1,2,4,4,5]
//Output: 3,5

int main() {

int a[] = {1,2,3,1,2,4,4,5};
int n = sizeof(a)/sizeof(int);

//First find out the XOR of all numbers
int res=0;
for(int i=0;i<n;i++) {
  res = res^a[i];
}

//So Now eventually res=3(011)^5(101)=6(110)
//res can never be 0 because XOR  of 2 different numbers is always greater than zero.

//Now we calculate the first set bit in res from right
int pos=0;
int temp=res;
while((temp&1)==0) {
  pos++;
  temp = temp>>1;
}

//creating the mask
int mask = (1<<pos);

//Now from all the numbers we check which number has the set bit at position=pos
int x=0;
int y=0;
for(int i=0;i<n;i++) {
  if((a[i]&mask)!=0) {
    x=x^a[i];
  }
}


//So we got one number which is x.
//And the second number y would be res^x;

y=res^x;

cout<<min(x,y)<<" "<<max(x,y);

  return 0;
}

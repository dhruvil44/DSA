//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


int knapsack(int i, int sizes[], int value[], int n, int sizeOfBag) {


  if(i==n) {
    return 0;
  }


  int op1=INT_MIN,op2=INT_MIN;

  //include the ith element
  if(sizes[i]<=sizeOfBag) {
    op1 = value[i] + knapsack(i+1,sizes,value,n,sizeOfBag-sizes[i]);
  }

  //discard the ith element
   op2 = knapsack(i+1,sizes,value,n,sizeOfBag);


  return max(op1,op2);


}



int main() {

  int sizeOfBag = 4;

  int sizes[] = {1,2,3,2,2};
  int value[] = {8,4,0,5,3};

  int n = sizeof(sizes)/sizeof(int);

  cout<<knapsack(0,sizes,value,n,sizeOfBag);

  return 0;
}

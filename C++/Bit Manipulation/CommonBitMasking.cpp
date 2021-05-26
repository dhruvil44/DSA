//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;


bool isOdd(int n) {
  return n&1;
}

//get the ith bit from the right (0 based index)
int getBit(int n, int i) {
  int mask = (1<<i);      //Left Shift

  int ans = (n&mask);

  if(ans>0) {
    return 1;
  }

  return 0;
}

//sets the ith bit from right
int setBit(int n, int i) {
  int mask = (1<<i);

  int ans = (n|mask);

  return ans;
}


//clear the ith bit from right
int clearBit(int n, int i) {
  int mask = ~(1<<i);

  int ans = n&mask;

  return ans;
}

//update ith bit with the new_bit from right
int updateBit(int n, int i, int new_bit) {

  //Step 1:- Cleat the ith bit
  int cleared_bit_number = clearBit(n,i);

  //Step 2:- Bit Wise OR Operation with the mask (v<<i)
  int updated_number = cleared_bit_number | (new_bit<<i);

  return updated_number;
}


int clearLastIBits(int n, int i) {
  int mask = (~0)<<i;

  return (n&mask);
}

int clearBitsInRangeFromIToJ(int n, int i, int j) {
  int a = (~0)<<(j+1);
  int b = (1<<i)-1;
  int mask = a|b;

  int ans = n&mask;
  return ans;
}



int main() {

  int n=5; //0000101
  cout<<getBit(5,2)<<endl;

  cout<<setBit(5,1)<<endl;

  cout<<clearBit(5,2)<<endl;

  cout<<updateBit(5,2,1)<<endl;

  cout<<updateBit(5,3,1)<<endl;

  cout<<updateBit(5,0,0)<<endl;

  cout<<clearLastIBits(15,3)<<endl;

  cout<<clearBitsInRangeFromIToJ(31,1,3)<<endl;
  return 0;
}

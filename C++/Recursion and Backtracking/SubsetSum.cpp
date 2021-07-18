//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

// Given a set of "n" non-negative integers,
// and a value "sum", determine if there is a subset of the given set with sum equal to given sum.


bool is_subset_present(int i, int a[], int n, int target) {


  if(target==0) {
    return true;
  }

  if(i==n) {
    return false;
  }

  //option1:- either to take this ith element
  bool op1 = is_subset_present(i+1,a,n,target-a[i]);


  //option2:- either to discard this ith element
  bool op2 = is_subset_present(i+1,a,n,target);

  return (op1||op2);

}



int main() {

  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  int target = 14;

  cout<<is_subset_present(0,a,n,target);




  return 0;
}

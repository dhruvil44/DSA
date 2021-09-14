//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

/*
Given an array and a key element.
Find the last occurence of the key element in the array using recursion.

Input:-
        7
        86 -16 77 65 45 77 28
        77

Output:-
        5 because the last occurence of 77 is at index 5
*/

int find_last_idx(long long int *a, int n, long long int key) {

	if(n==0) {
		return -1;
	}

	int idx = find_last_idx(a+1,n-1,key);

	if(idx!=-1) {
		return idx+1;
	}

	if(a[0]==key) {
		return 0;
	}

	return -1;
}


int main() {

  long long int a[] = {86, 16, 77, 65, 45, 77, 28};
  int n = 7;
  long long int key = 77;

  cout<<find_last_idx(a,n,key);

  return 0;
}

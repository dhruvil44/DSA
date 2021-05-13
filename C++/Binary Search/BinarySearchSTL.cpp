//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

int main() {

  int a[] = {1,2,3,44,44,44,44,50};
  int n = sizeof(a)/sizeof(int);

  bool present = binary_search(a,a+n,44);

  if(present) {
    cout<<"The element is present"<<endl;
  } else{
    cout<<"The element is absent"<<endl;
  }

  //In STL the Lower Bound returns the address of first element which is >=key
  auto lb = lower_bound(a,a+n,44);
  cout<<"The Lower Bound of 44 is "<<(lb-a)<<endl;

  //In STL the Upper Bound returns the address of first element which is >key
  auto ub = upper_bound(a,a+n,44);
  cout<<"The Upper Bound of 44 is "<<(ub-a)<<endl;

  //So to find the frequency of an element in a sorted array simply do upper_bound-lower_bound
  int frequency = ub-lb;
  cout<<"The frequency of 44 is "<<frequency<<endl;

  //In case if the element is not present then the lower_bound will return the first element > key
  lb = lower_bound(a,a+n,56);
  cout<<"The Lower Bound of 56 is "<<(lb-a)<<endl;

  ub = upper_bound(a,a+n,56);
  cout<<"The upper bound of 56 is "<<(ub-a)<<endl;


  return 0;
}

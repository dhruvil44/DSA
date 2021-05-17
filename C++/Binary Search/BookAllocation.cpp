//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;

bool check(int books[], int n, int students, int x) {

    int studentsUsed=1;
    int pages=0;

    for(int i=0;i<n;i++) {
      if(pages+books[i]>x) {
        studentsUsed++;
        pages=books[i];

        if(studentsUsed>students) {
          return false;
        }
      } else{
        pages+=books[i];
      }
    }

    return true;
}

int main() {

  int n;
  cin>>n;

  int books[n];
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>books[i];
    sum+=books[i];
  }

  int students;
  cin>>students;

  //Logic
  sort(books,books+n);

  int ans=INT_MAX;
  int start=books[n-1];
  int end=sum;

  while(start<=end) {
    int mid=(start+end)/2;

    bool isPossibleToRead = check(books,n,students,mid);

    if(isPossibleToRead) {
      end=mid-1;
      ans=min(ans,mid);
    }

    else{
      start=mid+1;
    }
  }

  cout<<ans<<endl;
  return 0;
}

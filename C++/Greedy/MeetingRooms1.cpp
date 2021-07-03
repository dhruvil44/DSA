//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

//Given n meetings with their start and end times.
//Determine whether you are able to attend all the meetings or not.

bool isPossibleToAttendAllMeetings(vector<vector<int> >intervals) {

  sort(intervals.begin(),intervals.end());

  int prev_beg = intervals[0][0];
  int prev_end = intervals[0][1];

  for(int i=1;i<intervals.size();i++) {
    if(intervals[i][0]<prev_end) {
      return false;
    }

    prev_beg = intervals[i][0];
    prev_end = intervals[i][1];
  }

  return true;

}

int main() {


  vector<vector<int> >intervals = {{0,30},{15,20},{5,10}};

  vector<vector<int> >intervals1 = {{4,5},{1,3},{10,12},{12,15}};

  cout<<isPossibleToAttendAllMeetings(intervals)<<endl;

  cout<<isPossibleToAttendAllMeetings(intervals1)<<endl;



  return 0;
}

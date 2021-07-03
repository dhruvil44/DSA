//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


//Given N meetings with their start and end times.
//Determine the minimum number of rooms required for the meeting so that no meeting clash.

/*
https://www.lintcode.com/problem/919/
*/

/*
https://www.youtube.com/watch?v=tNhiD4SaumY
A very good explanation
*/


int min_num_of_rooms(vector<vector<int> > intervals) {

  int ans=1;

  //In the min heap we will keep track of minimum end time of any meeting.
  priority_queue<int,vector<int>, greater<int> >pq;

  //sorting by the start time
  sort(intervals.begin(),intervals.end());

  int prev_beg = intervals[0][0];
  int prev_end = intervals[0][1];
  pq.push(prev_end);

  for(int i=1;i<intervals.size();i++) {

    //if overlapping with the meetin having maximum end time
    if(intervals[i][0]<prev_end) {

      //checking if the minimum end time meeting is finished
      //it means that if the minimum end time of a meeting till now is greater than we need one more room
      //else we can start our meeting after the minimum end time meeting
      if(pq.top()>intervals[i][0]) {
        ans++;
      }
      else{
        pq.pop();
      }

      if(intervals[i][1]>prev_end) {
        prev_beg = intervals[i][0];
        prev_end = intervals[i][1];
      }

    }

    //if not overlapping
    else{
      prev_beg = intervals[i][0];
      prev_end = intervals[i][1];
      pq.pop();
    }

    pq.push(intervals[i][1]);
  }

  return ans;

}

int main() {

  vector<vector<int> >intervals = {{0,30},{5,10},{15,20}};

  vector<vector<int> >intervals1 = {{2,11},{15,29},{4,15},{1,18},{18,23},{5,13}};

  cout<<min_num_of_rooms(intervals)<<endl;
  cout<<min_num_of_rooms(intervals1)<<endl;

  return 0;
}

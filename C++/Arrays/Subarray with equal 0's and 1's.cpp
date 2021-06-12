/*Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Example 1:

Input:
N = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    long long int countSubarrWithEqualZeroAndOne(int arr[], int N)
    {
long long int z=0,o=0,ans=0,sum=0;
map < long long , long long > mp ;
for ( int i = 0 ; i < N ; i++ )
{
if (arr [i] == 0 )
arr[i] = -1 ;
sum += arr[i] ;
mp[sum]++ ;
}
for(auto itr=mp.begin();itr!= mp.end();itr++ )
{
if( itr->second > 1 )
ans = ans + ( itr->second * (itr->second-1) / 2) ;
}
return (ans+mp[0]) ;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  

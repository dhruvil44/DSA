/*Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
Given an array, your task is to find the index of first Equilibrium point in the array.

Input Format:
The first line of input takes an integer T denoting the no of test cases, then T test cases follow. The first line of each test case is an integer N denoting The size of the array. Then in the next line are N space-separated values of the array. 

Output Format:
For each test case, the output will be the equilibrium index of the array. If no such index exists output will be -1.

User Task :
Your task is to complete the function (findEquilibrium) below which returns the index of the first Equilibrium point in the array. The function takes two arguments. The first argument is the array A[ ] and the second argument is the size of the array A.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1<=T<=100
1<=N<=105
-1000<=A[]<=1000

Example(To be used only for expected output):
Input
2
4
1 2 0 3
4
1 1 1 1

Output
2
-1 */
#include <iostream>
using namespace std;
int findEquilibrium(int [], int );
 
int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<findEquilibrium (a,n)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends


/* You are required to complete this method*/
int findEquilibrium(int arr[], int n)
{
  //Your code here
  int rightSum = 0;
    for(int i = 0; i < n; i++)
    {
        rightSum += arr[i];
    }
    
    int leftSum = 0;
    for(int i = 0; i < n; i++)
    {
        rightSum -= arr[i];
        
        if(rightSum == leftSum)
        {
            return i;
        }
        
        leftSum  += arr[i];
    }
    
    return -1;
}

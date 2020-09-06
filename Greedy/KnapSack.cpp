//Author: Dhruvil Patel

#include<bits/stdc++.h>

using namespace std;
//Greedy Method is only applicable when the objects are divisible(for ex:-Vegetables)


//returns the total optimal value that can be filled in the knapsack
float knapsack(int capacity,int val[],int weight[],int n)
{

  //This is the ratio of val/weight
  float ratio[n];
  for(int i=0;i<n;i++)
  {
    ratio[i]=val[i]*1.0/weight[i];
  }

  //sorting according to the ratio
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(ratio[i]<ratio[j])
      {
        float temp=ratio[i];
        ratio[i]=ratio[j];
        ratio[j]=temp;

        int temp1=val[i];
        val[i]=val[j];
        val[j]=temp1;

        int temp2=weight[i];
        weight[i]=weight[j];
        weight[j]=temp2;
      }
    }
  }

  for(int i=0;i<n;i++)
  {
    cout<<ratio[i]<<" ";
  }
  cout<<endl;

  float ans=0.0;
  int tempweight=0;
  int i;
  for(i=0;i<n;i++)
    {
      tempweight+=weight[i];
      ans+=1.0*val[i];
      if(tempweight>=capacity)
        {
          break;
        }

    }


    if(tempweight>capacity)
    {
      ans-=1.0*val[i];
      tempweight=tempweight-weight[i];

      ans+=1.0*((capacity-tempweight)*val[i])/weight[i];
      tempweight=capacity;
    }

return ans;

}

int main()
{

cout<<"Enter the number of elemets"<<endl;
int n;
cin>>n;

int val[n];
int weight[n];
for(int i=0;i<n;i++)
{
  cout<<"Enter the value of "<<i+1<<" element"<<endl;
  cin>>val[i];

  cout<<"Enter the weight of "<<i+1<<" element"<<endl;
  cin>>weight[i];
}

int capacity;
cout<<"Enter the capacity of Knapsack"<<endl;
cin>>capacity;

cout<<knapsack(capacity,val,weight,n);


  return 0;
}

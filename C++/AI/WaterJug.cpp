//Author: Dhruvil Patel

//water Jug Problem solution


#include<bits/stdc++.h>

using namespace std;

//function to calculate gcd (complexity->log(max(a,b)))
long long int gcd(long long int a , long long int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);


}

//function to solve water jug
void waterJugSolver(int n, int x, int y){
    //initially both A and B are empty
    int filledInA=0;
    int filledInB=0;

    //continue the loop until any one of the jug gets the water = n litres
    while(filledInA!=n && filledInB!=n){
        //if A is empty
        if(filledInA==0){
            //fill A to its full capacity
            filledInA=x;
            cout<<filledInA<<" "<<filledInB<<endl;
        }

        //if B is full
        else if(filledInB==y){
            //empty B
            filledInB=0;
            cout<<filledInA<<" "<<filledInB<<endl;
        }

        else{
            //getting the minimum of water in A and remaining capacity of B
            int t = min(filledInA , y-filledInB);

            //filling the minimum water in B
            filledInB+=t;

            //emptying the minimum water from A
            filledInA-=t;
            cout<<filledInA<<" "<<filledInB<<endl;
        }
    }
}

int main()
{
  //The litres of water we want to measure
    int n;
    cout<<"Enter litres of water to be measured"<<endl;
    cin>>n;

    //A Jug
    int x;
    cout<<"Enter capacity of Jug A"<<endl;
    cin>>x;

    //B Jug
    int y;
    cout<<"Enter capacity of Jug B"<<endl;
    cin>>y;

    //We cant measure n if its value is higher than the capacity of both the jugs
    if(n<x || n<y)
    {
        //condition whehter we can measure n litres or Not
        if(n%gcd(x,y)==0)
        {
          //calling the solver function
            waterJugSolver(n,x,y);
        }
        else{
            cout<<"NOT POSSIBLE";
        }
    }

    else{
        cout<<"NOT POSSIBLE";
    }


    return 0;
}

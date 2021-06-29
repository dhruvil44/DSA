//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;


int main() {

  //Total num of transactions taken place and the total number of people in the group
  int no_of_transactions,people;

  cin>>no_of_transactions>>people;

  map<string,int> net_amount;

  while(no_of_transactions--) {
    string x,y;  //Person x has to give amount to Person y
    int amount;

    cin>>x>>y>>amount;

    if(net_amount.find(x)==net_amount.end()) {
      net_amount[x]=0;
    }

    if(net_amount.find(y)==net_amount.end()) {
      net_amount[y]=0;
    }
    //Finding the net gain or loss for all the people in the group
    net_amount[x]-=amount;
    net_amount[y]+=amount;
  }


  multiset<pair<int,string> >ms;

  for(auto p: net_amount) {
    if(p.second!=0) {
      ms.insert({p.second,p.first});
    }
  }


  while(!ms.empty()) {


    auto low = ms.begin();    //The first element
    auto high = prev(ms.end()); //This means the last element

    auto p1 = *(low);
    auto p2 = *(high);

    int debit_amt = p1.first;
    string debtor = p1.second;

    int credit_amt = p2.first;
    string creditor = p2.second;

    ms.erase(low);
    ms.erase(high);

    int settlement_amt = min(-debit_amt,credit_amt);

    debit_amt+=settlement_amt;
    credit_amt-=settlement_amt;

    cout<<debtor<<" has to pay "<<settlement_amt<<" to "<<creditor<<endl;

    if(debit_amt!=0) {
      ms.insert({debit_amt,debtor});
    }


    if(credit_amt!=0) {
      ms.insert({credit_amt,creditor});
    }

  }

  return 0;
}

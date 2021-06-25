//Author: Dhruvil Patel

#include<bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin>>s;

	stack<char> st;

	for(auto x: s) {
		if(x=='(') {
			st.push(x);
		}

		if(x=='{') {
			st.push(x);
		}

		if(x=='[') {
			st.push(x);
		}

		if(x==')') {
			if(!st.empty() and st.top()=='(') {
				st.pop();
			}
			else{
				cout<<"No\n";
				return 0;
			}
		}

		if(x=='}') {
			if(!st.empty() and st.top()=='{') {
				st.pop();
			}
			else{
				cout<<"No\n";
				return 0;
			}
		}

		if(x=='[') {
			if(!st.empty() and st.top()==']') {
				st.pop();
			}

			else{
				cout<<"No\n";
				return 0;
			}
		}
	}

	if(st.empty()) {
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}

	return 0;
}

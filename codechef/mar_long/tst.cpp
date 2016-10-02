#include<bits/stdc++.h>
using namespace std;

vector <vector <string> > a_;

vector <string> b_;

int main(){

	string s;
	s.resize(10);
	s[0]='b';
	s[1]='a';
	b_.push_back(s);
	a_.push_back(b_	);
	//s[1]='\0';
	cout<<a_[0][0][0]<<endl;


	return 0;
}
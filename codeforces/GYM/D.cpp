#include<bits/stdc++.h>

using namespace std;


#define cout fout
#define cin fin


string s;


int main(){
	ifstream fin("strange.in");
	ofstream fout("strange.out");
	cin>>s;

	if(s.size()==1&&s[0]=='1'){
		cout<<"2"<<endl;
	}else{
		cout<<s<<endl;
	}



	return 0;
}
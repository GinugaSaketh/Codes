#include<bits/stdc++.h>

using namespace std;

string s;


int main(){
	
	int t;
	cin>>t;
	int  i;

	for(i=0;i<t;i++){
		cin>>s;
		int j,a=0,b=0;
		if(s.size()==1){
			cout<<"Yes"<<endl;
			continue;
		}
		for(j=0;j<s.size();j++){
			if(s[j]=='1'){
				a++;
			}else{
				b++;
			}
		}

		if(min(a,b)==1){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}


	}


	return 0;
}
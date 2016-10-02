#include<bits/stdc++.h>

using namespace std;

string s;

int main(){
	
	int t;
	cin>>t;
	int i,j;

	for(j=0;j<t;j++){
		cin>>s;
		int flag=1;
		int n=s.size();
		for(i=0;i<n/2;i++){
			if(s[i]==s[n-i-1]&&s[i]=='.'){
				s[i]='a';
				s[n-i-1]='a';
			}else if(s[i]=='.'||s[n-i-1]=='.'){
				if(s[i]=='.'){
					s[i]=s[n-i-1];
				}else{
					s[n-i-1]=s[i];
				}
			}else if(s[i]!=s[n-i-1]){
				cout<<"-1"<<endl;
				flag=0;
				break;
			}
		}
		//cout<<s<<endl;
		if(n%2==1){
			if(s[n/2]=='.'){
				s[n/2]='a';
			}
		}


		if(flag==1){
			cout<<s<<endl;
		}
		//cout<<"svavad"<<endl;

	}

	return 0;
}
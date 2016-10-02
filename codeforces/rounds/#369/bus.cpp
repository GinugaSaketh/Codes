#include<bits/stdc++.h>

using namespace std;


string s[1005];

int main(){

	int n;
	cin>>n;

	int i,flag=0;

	for(i=0;i<n;i++){
		cin>>s[i];
	}

	for(i=0;i<n;i++){
		if(s[i][0]=='O'&&s[i][1]=='O'){
			s[i][0]='+';
			s[i][1]='+';
			flag=1;
			break;
		}else if(s[i][3]=='O'&&s[i][4]=='O'){
			s[i][3]='+';
			s[i][4]='+';
			flag=1;
			break;
		}
	}

	if(flag==0){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		for(i=0;i<n;i++){
			cout<<s[i]<<endl;
		}

	}
	




	return 0;	
}
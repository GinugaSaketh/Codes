#include<bits/stdc++.h>

using namespace std;

string s;




int main(){

	cin>>s;

	int i;

	char c='0';

	for(i=0;i<s.size();i++){
		if(s[i]>c){
			c=s[i];
		}
	}
	int j;


	cout<<c<<endl;
	
	for(j=0;j<c;j++){
		

		int flag=0;
		for(i=0;i<s.size();i++){
		if(s[i]=='0'){
			if(flag==1){
				cout<<"0";
			}
		}else{
			flag=1;
			s[i]--;
			cout<<"1";
		}
		}cout<<" ";
	}cout<<endl;







	return 0;
}
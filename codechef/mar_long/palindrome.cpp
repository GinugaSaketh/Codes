#include<iostream>

using namespace std;




int main(){
	
	int t;
	cin>>t;
	int i;

	while(t--){
	int ab[26];
	for(i=0;i<26;i++){
		ab[i]=0;
	}

	string s,s1;

	cin>>s;
	int flag=0;
	for(i=0;i<s.size();i++){
		ab[s[i]-'a']++;
	}
	cin>>s1;
	for(i=0;i<s1.size();i++){
		if(ab[s1[i]-'a']>0){
		flag=1;break;
		}
	}

	if(flag==1){
	cout<<"Yes"<<endl;
	}else{
	cout<<"No"<<endl;
	}




	}
	return 0;
}
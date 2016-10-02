#include<bits/stdc++.h>

using namespace std;

string s;

int a[100005];


int main(){

	cin>>s;

	int i;

	for(i=0;i<s.size()-1;i++){
		if(s[i]==s[i+1]){
			a[i]=1;
		}else{
			a[i]=0;
		}
	}


	for(i=1;i<s.size()-1;i++){
		a[i]+=a[i-1];
		//cout<<a[i]<<endl;
	}

	int m,l,r;

	cin>>m;
	for(i=0;i<m;i++){
		cin>>l>>r;
		//cout<<l<<" "<<r<<" "<<a[l-1]<<" "<<a[r-2]<<endl;

		int net=a[r-2]-a[l-2];

		cout<<net<<endl;

	}








	return 0;
}
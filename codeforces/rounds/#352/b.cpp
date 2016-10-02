#include<iostream>
#include<string>
using namespace std;

string s;
int a[30]; 

int main(){
	int n;

	int i;
	cin>>n;
	cin>>s;

	if(n>26){
		cout<<"-1"<<endl;
		return 0;
	}
	for(i=0;i<30;i++){
		a[i]=0;
	}
	int net=0;
	for(i=0;i<n;i++){
		int x=s[i]-'a'+1;
		if(a[x]==1){
			net++;
		}else{
			a[x]=1;
		}
	}
/*
	int m=0;
	for(i=1;i<=26;i++){
		m+=a[i];
	}
	int diff=n-m;
	cout<<diff<<endl;

*/
	cout<<net<<endl;




	return 0;
}
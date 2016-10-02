#include<bits/stdc++.h>

using namespace std;

int a[105];
int b[105];

int s,n,i,j;

int main(){
	cin>>n;
	s=0;
	for(i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	s/=n;
	s*=2;
	for(i=0;i<n;i++){
		b[i]=0;
	}


	for(i=0;i<n;i++){
		
		cout<<(b[i].second)<<" "<<(b[n-i-1].second)<<endl;


	}



	return 0;
}
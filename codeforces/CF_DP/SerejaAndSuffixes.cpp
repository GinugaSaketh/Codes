#include<bits/stdc++.h>

using namespace std;


int a[100005];

int b[100005];

int c[100005];

int main(){
	int n,m;
	cin>>n>>m;
	int i;



	for(i=0;i<100005;i++){
		a[i]=0;
	}


	for(i=1;i<=n;i++){
		cin>>b[i];
	}

	c[n]=1;
	a[b[n]]=1;

	for(i=n-1;i>=0;i--){
		if(a[b[i]]==0){
			a[b[i]]=1;
			c[i]=c[i+1]+1;
		}else{
			c[i]=c[i+1];
		}
	}
	int l;

	for(i=0;i<m;i++){
		cin>>l;
		cout<<c[l]<<endl;


	}






	return 0;
}
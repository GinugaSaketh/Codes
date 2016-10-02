#include<bits/stdc++.h>

using namespace std;

long long a[50005][7];

long long b[50005];

int main(){

	int m,n;
	cin>>m>>n;
	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}

	for(i=0;i<=n;i++){
		b[i]=0;
	}


	for(j=1;j<=n;j++){
		b[1]+=a[1][j];

		for(i=2;i<=m;i++){
			b[i]=max(b[i]+a[i][j],b[i-1]+a[i][j]);
		}
	}

	for(i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}cout<<endl;


	return 0;
}
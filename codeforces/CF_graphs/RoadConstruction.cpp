#include<iostream>

using namespace std;

int a[1005];


int main(){
	int n,m;
	cin>>n>>m;
	int i,b,c,j;

	for(i=1;i<=n;i++){
		a[i]=0;
	}

	for(i=0;i<m;i++){
		cin>>b>>c;
		a[b]=1;
		a[c]=1;
	}

	for(i=1;i<=n;i++){
		if(a[i]==0){
			break;
		}
	}
	n--;
	cout<<n<<endl;

	for(j=1;j<=n+1;j++){
		if(i==j)continue;
		cout<<i<<" "<<j<<endl;
	}


	return 0;
}
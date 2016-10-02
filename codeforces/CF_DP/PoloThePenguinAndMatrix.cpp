#include<bits/stdc++.h>

using namespace std;

int a[105][105];

int b[10005];
int c[10005];



int main(){	
	int n,m,d;

	cin>>n>>m>>d;

	int i,j;

	for(i=0;i<1005;i++){
		b[i]=0;
	}

	int mi=10005;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]<mi){
				mi=a[i][j];
			}
		}
	}

	int flag=0;
	//cout<<mi<<endl;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			a[i][j]-=mi;

			if(a[i][j]%d!=0){
				//cout<<a[i][j]<<endl;
				flag=1;
				break;
			}else{
			a[i][j]/=d;

			//cout<<a[i][j]<<endl;
			b[a[i][j]]++;

			}

		}
		if(flag==1){
			break;
		}
	}

	if(flag==1){
		cout<<"-1"<<endl;
		return 0;
	}

	c[0]=0;
	for(i=1;i<=10000;i++){
		c[i]=b[i-1]+c[i-1];
	}

	int net=0;

	for(i=0;i<=10000;i++){
		net+=i*(b[i]);
		//cout<<net<<" ";
	}//cout<<endl;

	mi=net;
	int in=0;

	for(i=1;i<=10000;i++){
		net+=c[i];
		net-=n*m-c[i];

		if(net<mi){
			in=i;	
			mi=net;
		}

	}

	//cout<<in<<endl;
	cout<<mi<<endl;

	return 0;
}
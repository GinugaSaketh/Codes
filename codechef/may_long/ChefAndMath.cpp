#include<iostream>
#include<vector>

using namespace std;


long long f[100];


//f[0]->f[n-1]
long long dp(long long x,long long k,int n){
	if(x<0){
		return 0;
	}

	if(x==0&&k==0){
		return 1;
	}
	if(k==0&&x!=0){
		return 0;
	}
	
	if(k!=0){
		if(x==0||n==0){
			return 0;
		}else{
			int y=dp(x,k,n-1);
			if(x<=k*f[n-1]&&x>=f[n-1]){
				y+=dp(x-f[n-1],k-1,n);
			}

			return y; 
		}

	}




}




int main(){

	int i;
	f[0]=1;
	f[1]=2;
	for(i=2;i<=43;i++){
		f[i]=f[i-1]+f[i-2];
	}

	//cout<<f[43]<<endl;


	int q;

	cin>>q;
	long long k;
	long long x;
	for(i=0;i<q;i++){
		cin>>x>>k;

		//dp[x][k][n]

		long long net=dp(x,k,43);

		cout<<net<<endl;

	}





	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n,m;

vector<int> a,b;


int a[128];

int main(){

	cin>>n>>m;

	if(n<m){
		int t=n;
		n=m;
		m=t;
	}

	int k;

	for(k=0;k<10;k++){
		dp[i][0][0]=0;
		dp[i][1][0]=0;
		dp[i][0][1]=0;
		dp[i][1][1]=0;
	}


	int p=n,q=n;


	while(p!=0){
		a.push_back(p%7);
		p/=7;
	}

	while(q!=0){
		b.push_back(q%7);
		q/=7;
	}


	if(a.size()+b.size()>7){
		cout<<"0"<<endl;
	}else{


		 



		}




		}






	}






	return 0;
}
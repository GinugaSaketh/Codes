#include<bits/stdc++.h>

using namespace std;


int a[1000005];


vector dp[1<<8];


vector <pair<int,int> > p;


int main(){

	int n,k;

	cin>>n>>k;

	int c;
	int i,j;
	for(i=0;i<1000005;i++){
		a[i]=0;
		b[i]=1;
	}


	long long net=1;
	for(i=0;i<n;i++){
		cin>>c;
		a[c]=1;
		net*=c;


	}

	if(k==1){
		cout<<"Yes"<<endl;
		return 0;
	}

	p.push_back(make_pair(0,0));

	for(i=2;i*i<=k;i++){


		if(k%i==0){
			int t=1;
			while(k%i==0){
				t*=i;
				k/=i;
			}

			p.push_back(make_pair(i,t));

		}

	}


	s=p.size()-1;


	//dp[(1<<s)-1]


	dp[0]=1;
	//int c[20];

	/*for(i=1;i<(1<<s);i++){

		for()

	}
	*/

	if(c%k==0){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}











}
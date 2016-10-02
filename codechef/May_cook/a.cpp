#include<bits/stdc++.h>

using namespace std;


int a[100005];

int main(){

	int n;
	cin>>n;
	int i;

	int net=n;

	int odd=0;

	int one=0;

	for(i=0;i<n;i++){
		cin>>a[i];
		
		if(a[i]==1){
			a[i]=-1;
			one++;
			continue;
		}

		a[i]-=2;
		
		
		//net+=a[i];


	}

	int sum=0;

	//extra one
	for(i=0;i<n;i++){
		
		if(a[i]==-1)continue;

		//cout<<a[i]<<endl;
		
		sum+=a[i];


	}
	//cout<<odd<<" "<<one<<endl;

	if(one>=sum){
		net+=0;
	}else{


		sum-=one;

		net+=(sum+1)/2;
	}

	cout<<net<<endl;




	return 0;
}
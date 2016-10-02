#include<bits/stdc++.h>

using namespace std;

int a[105];

int b[10];

int main(){

	int i;

	for(i=0;i<=100;i++){
		a[i]=0;
	}

	int sum=0;

	for(i=1;i<=5;i++){
		cin>>b[i];
		a[b[i]]++;
		sum+=b[i];
	}

	int net=0;


	for(i=1;i<6;i++){
		if(a[b[i]]==2){
			net=max(net,2*b[i]);
		}

		if(a[b[i]]>=3){
			net=max(net,3*b[i]);
		}


	}


	sum-=net;

	cout<<sum<<endl;




	return 0;
}
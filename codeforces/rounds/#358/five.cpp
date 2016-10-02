#include<iostream>

using namespace std;

long long a[10];
long long b[10];

int  main(){
	int n,m;

	cin>>n>>m;
	int i;

	if(n%5==0){
		long long x=n/5;

		a[0]=a[1]=a[2]=a[3]=a[4]=x;

	}else{

		long long x=n/5;

		long long y=n%5;

		a[0]=a[1]=a[2]=a[3]=a[4]=x;

		for(i=1;i<=y;i++){
			a[i]++;
		}

	}	


	if(m%5==0){
		
		long long x=m/5;

		b[0]=b[1]=b[2]=b[3]=b[4]=x;

	}else{

		long long x=m/5;

		long long y=m%5;

		b[0]=b[1]=b[2]=b[3]=b[4]=x;

		//cout<<y<<endl;

		for(i=1;i<=y;i++){
			b[i]++;
		}

	}	
/*
	for(i=0;i<=4;i++){
		cout<<a[i]<<" ";
	}cout<<endl;	


	for(i=0;i<=4;i++){
		cout<<b[i]<<" ";
	}cout<<endl;*/	

	long long net=0;
	net+=a[0]*b[0];
	net+=a[1]*b[4];
	net+=a[2]*b[3];
	net+=a[3]*b[2];
	net+=a[4]*b[1];

	cout<<net<<endl;




	return 0;
}
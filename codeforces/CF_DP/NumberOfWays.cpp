#include<bits/stdc++.h>

using namespace std;


int a[500005];

long long sum[500005];


int main(){
	int n;
	cin>>n;	
	int i;
	long long total=0;
	for(i=1;i<=n;i++){
	
		scanf("%d",&a[i]);
		total+=a[i];
	}



	if(total%3==0){

		for(i=0;i<=n;i++){
			sum[i]=0;
		}


		long long s=0;
		for(i=n;i>=1;i--){
			s+=a[i];
			if(s==total/3){
				if(i==n){
					sum[i]=1;
				}else{
					sum[i]=sum[i+1]+1;
				}
			}else{
				if(i==n){
					sum[i]=0;
				}else{
					sum[i]=sum[i+1];
				}
			}
		}

		s=0;
		long long net=0;
		for(i=1;i<n-1;i++){
			s+=a[i];
			if(s==total/3){
				net+=sum[i+2];
			}
		}

		cout<<net<<endl;


	}else{

		cout<<"0"<<endl;


	}









	return 0;
}
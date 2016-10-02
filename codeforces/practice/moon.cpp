#include<bits/stdc++.h>

using namespace std;

int a[100];


int main(){
	int n,i;

	cin>>n;

	for(i=1;i<=n;i++){
		cin>>a[i];
	}


	if(n==1){
		if(a[1]==0){
			cout<<"UP"<<endl;
		}else if(a[1]==15){
			cout<<"DOWN"<<endl;
		}else{
			cout<<"-1"<<endl;
		}
		return 0;
	}

	if(a[n]==0){
		cout<<"UP"<<endl;
	}else if(a[n]==15){
		cout<<"DOWN"<<endl;
	}else{
		if(a[n]>a[n-1]){
			cout<<"UP"<<endl;
		}else{
			cout<<"DOWN"<<endl;
		}


	}


	return 0;
}
#include<iostream>

using namespace std;

int a[1005];


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i;
		cin>>n;
		for(i=0;i<1001;i++){
			a[i]=0;
		}

		int flag=1;
		int x;
		for(i=0;i<n;i++){
			cin>>x;
			if(a[x]==0){
				a[x]=1;
			}else if(a[x]==1){
				flag=0;
				
			}
			
		}
		if(flag==1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}


	return 0;
}
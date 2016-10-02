#include<iostream>

using namespace std;
int a[100005];
int b[100005];
int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int i,j;

		int si;

		for(i=0;i<n;i++){
			cin>>a[i];
		}

		b[n-1]=1;

		int s1;
		if(a[n-1]>0){
			si=1;
		}else{
			if(a[n-1]<0){
				si=-1;
			
			}else{
				si=0;
			}
		}
		for(i=n-2;i>=0;i--){
			if(si==1&&a[i]<0){
				b[i]=b[i+1]+1;
				si=-1;
				continue;
			}
			if(si==-1&&a[i]>0){
				
				b[i]=b[i+1]+1;
					
				si=1;
				continue;
			}
			if(a[i]>0){
				si=1;
			}else if(a[i]<0){
				si=-1;
			}else{
				si=0;
			}
			b[i]=1;
		}

		for(i=0;i<n;i++){
			cout<<b[i]<<" ";
		}cout<<endl;


	}



	return 0;
}
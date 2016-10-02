#include<bits/stdc++.h>

using namespace std;

int a[105];

int main(){
	int n;

	cin>>n;
	int x;
	int i,j,k;
	for(i=0;i<n;i++){
		cin>>a[i];
	}	

	


		for(j=n;j>0;j--){
			
			int m=-1;
			int in=-1;

			for(k=0;k<j;k++){
				if(m<=a[k]){
					m=a[k];
					in=k;
				}
			}
				if(in==j-1){
					continue;
				}else{
					for(;in<j-1;in++){
						cout<<in+1<<" "<<in+2<<endl;
						int t=a[in];
						a[in]=a[in+1];
						a[in+1]=t;
					}



				}

			
		}



	



	return 0;
}
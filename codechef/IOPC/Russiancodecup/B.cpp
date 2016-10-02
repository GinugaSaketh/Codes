#include<iostream>
#include<cstdio>

using namespace std;

int a[100005];
int b[100005];

long long h;

int main(){
	int t;
	cin>>t;

	while(t--){
		int i;
		int n;
		cin>>n>>h;

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}

		for(i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		int net=0;
		for(i=1;i<=n;i++){
			int j=i;
			int j_=-1;
			long long sum=0;
			int found=0;
			while(j<=n&&sum<=h){
				sum+=a[j];
				if(b[j]==1){
					found=1;
					j_=j;
				}
				j++;
			}
			//cout<<j<<endl;
			if(found==0){
				a[j-1]=1;
			//	cout<<"YES"<<endl;
				net++;
				i=j;
			}else{
				i=j_;
			}
		}

		if(a[1]!=1){
			net++;
		}

		if(n!=1&&a[n-1]!=1){
			net++;
		}

		cout<<net<<endl;


	}






	return 0;
}
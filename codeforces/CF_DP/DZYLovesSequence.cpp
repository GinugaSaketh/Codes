#include<bits/stdc++.h>

using namespace std;


int a[100005];

int l[100005];
int r[100005];

int p[100005],q[100005];
	

int main(){
	int n,i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}

	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}

	if(n==2){
		cout<<"2"<<endl;
		return 0;
	}


	/*for(i=0;i<n;i++){
		l[i]=r[i]=1;
		for(j=i-1;j>=0;j--){
			if(a[j]<a[j+1]){
				l[i]++;
			}else{
				break;
			}
		}
		for(j=i+1;j<n;j++){
			if(a[j]>a[j-1]){
				r[i]++;
			}else{
				break;
			}
		}

	}*/

	k=0;

	for(i=0;i<n;i++){
		//cout<<k<<endl;
		while(a[k+1]>a[k]&&k+1<n){
			k++;
		}
		//cout<<k<<" dc "<<i<<endl;

		for(j=i;j<=k;j++){
			p[j]=k-j+1;
		}
		i=k;
		k++;
	}

	/*for(i=0;i<n;i++){
		cout<<p[i]<<" "<<r[i]<<endl;
	}*/

	k=n-1;

	for(i=n-1;i>=0;i--){

		while(a[k-1]<a[k]&&k-1>=0){
			k--;
		}

		for(j=i;j>=k;j--){
			q[j]=j-k+1;
		}
		i=k;
		k--;
	}

	/*for(i=0;i<n;i++){
		cout<<q[i]<<" "<<l[i]<<endl;
	}*/








	int ans=1;

	/*
	for(i=0;i<n;i++){
		cout<<l[i]<<" "<<r[i]<<endl;
	}*/

	ans=max(ans,1+p[0]);
	ans=max(ans,1+q[n-1]);

	for(i=1;i<n-1;i++){
		if(a[i-1]+1<a[i+1]){
			ans=max(ans,q[i-1]+1+p[i+1]);
			//cout<<ans<<endl;
		}
		ans=max(ans,1+q[i]);
	    ans=max(ans,1+p[i]);
	}

	if(ans==100001){
		ans--;
	}


	if(ans>n){
		ans=n;
	}

	cout<<ans<<endl;


	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;

int c[500005];
int n,k,i;

int bin_min(int l,int r){
	
	if(l==r){
		return l;
	}

	int mid=((l+r)/2)+1;

	int j;
	long long s=0;
	for(j=1;j<=n;j++){
		s+=max(0,mid-c[j]);
	}
	if(s<=k){
		return bin_min(mid,r);
	}else{
		return bin_min(l,mid-1);
	}
}


int bin_max(int l,int r){
	//cout<<l<<" "<<r<<endl;
	if(l==r){
		return l;
	}
	int mid=(l+r)/2;
	int j;
	long long s=0;
	for(j=1;j<=n;j++){
		s+=max(0,c[j]-mid);
	}
	if(s<=k){
		return bin_max(l,mid);
	}else{
		return bin_max(mid+1,r);
	}


}



int main(){
/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	only cin,cout!!
*/
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%d",&c[i]);
		//cin>>c[i];
	}

	int mi=bin_min(0,(int)(1e9+5));
	int ma=bin_max(0,(int)(1e9+5));

	if(mi>=ma){
		long long s=0;
		for(i=1;i<=n;i++){
			s+=c[i];
		}
		if(s%n==0){
			cout<<"0"<<endl;
		}else{
			cout<<"1"<<endl;
		}
	}else{
		ma-=mi;
		cout<<ma<<endl;
	}





	return 0;
}
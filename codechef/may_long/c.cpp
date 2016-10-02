#include<iostream>


using namespace std;

long long h[100005];
long long r[100005];
long long n,w,l;

long long bin(long long lo,long long hi){
	if(lo==hi){
		return lo;
	}
	long long mid=(lo+hi)/2LL;
	long long sum=0;
	int i;

	for(i=0;i<n;i++){
		if(mid*r[i]>=(l-h[i])){
			sum+=h[i]+mid*r[i];
		}
		if(sum>=w){
			break;
		}
	}
	if(sum>=w){
		return bin(lo,mid);
	}else{
		return bin(mid+1,hi);
	}


}

int main(){
	
	cin>>n>>w>>l;
	int i;
	long long max=-1;
	for(i=0;i<n;i++){
		cin>>h[i]>>r[i];
		if(r[i]>max){
			max=r[i];
		}
		
	}

	long long x=(long long )(1e18);
	x/=max;






	long long net=bin(0,x);

	cout<<net<<endl;







	return 0;
}
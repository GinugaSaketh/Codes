#include<bits/stdc++.h>

using namespace std;

vector <long long> a,b;

int main(){
	int n;
	int i;
	cin>>n;
	long long x;

	for(i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
		b.push_back(x);
	}

	sort(b.begin(),b.end());

	for(i=1;i<n;i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}




	int m;
	cin>>m;

	int t,l,r;


	for(i=0;i<m;i++){
		long long net=0;
		cin>>t>>l>>r;
		if(t==1){
			if(l>1){
				net=a[r-1]-a[l-2];
			}else{
				net=a[r-1];
			}
		}else{
			if(l>1){
				net=b[r-1]-b[l-2];
			}else{
				net=b[r-1];
			}
		}
		cout<<net<<endl;
	}









	return 0;
}
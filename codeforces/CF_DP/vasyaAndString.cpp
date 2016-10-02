#include<bits/stdc++.h>

using namespace std;

string s;

int a[100005];
int b[100005];

int main(){
	int n,k;
	cin>>n>>k;
	int i;
	cin>>s;




	for(i=0;i<s.size();i++){
		if(s[i]=='a'){
			a[i]=1;
			b[i]=0;
		}else{
			a[i]=0;
			b[i]=1;
		}
	}

	for(i=1;i<n;i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}

	int l=0,r=0;

	int mi=0;

	int net=1;

	int x,y;

	while(r<n){
		if(l!=0){
			x=a[r]-a[l-1];
			y=b[r]-b[l-1];
		}else{
			x=a[r];
			y=b[r];
		}

		mi=min(x,y);

		if(mi<=k){
			if(net<r-l+1){
				net=r-l+1;
			}
			r++;
		}else{
			l++;
		}
	}

	cout<<net<<endl;



	return 0;
}
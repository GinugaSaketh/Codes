#include<iostream>

typedef long long ll;

using namespace std;

ll a[100005];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		int i;
		for(i=0;i<n;i++){
			cin>>a[i];
		}

		int j;
		i=0,j=n-1;
		int net=0;

		ll l=a[i];
		ll r=a[j];
		while(i<j){
			if(l==r){
				i++;
				j--;
				l=a[i];
				r=a[j];
				continue;
			}else if(l<r){
				i++;
				net++;
				l+=a[i];
				continue;

			}else if(l>r){
				j--;
				net++;
				r+=a[j];
				continue;
			}
		}
		cout<<net<<endl;



	}

	return 0;
} 
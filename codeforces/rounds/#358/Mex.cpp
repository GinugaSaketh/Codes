#include<bits/stdc++.h>

using namespace std;

int a[100005];

int main(){
	int n;

	cin>>n;

	int i;

	for(i=0;i<n;i++){
		cin>>a[i];
	}

	sort(a,a+n);


	int net=1;

	int k=1;

	for(i=0;i<n;i++){
		if(a[i]>=k){
			//cout<<k<<endl;
			k++;
			net++;
			

		}
		
		
	}


	cout<<net<<endl;






	return 0;
}
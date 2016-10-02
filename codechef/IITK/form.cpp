#include<bits/stdc++.h>

using namespace std;

vector <int> a;


int main(){
	int t;
	cin>>t;

	int i,j,k;
	int n,x;
	for(k=0;k<t;k++){
		cin>>n;
		a.resize(0);
		
		for(i=1;i<=n;i++){
			cin>>x;
			a.push_back(x);
		}

		sort(a.begin(),a.end());
		int net=-1;

		for(j=a.size()-1;j>=2;j--){

			if(a[j]<a[j-1]+a[j-2]){
				net=j;
				break;
			}

		}


		if(net==-1){
			cout<<"-1"<<endl;
		}else{
			cout<<a[j-2]<<" "<<a[j-1]<<" "<<a[j]<<endl;
		}



	}






	return 0;
}
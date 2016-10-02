#include<bits/stdc++.h>

using namespace std;

vector <int >a,b;


int main(){

	int n;
	cin>>n;

	int i,t,w;

	for(i=0;i<n;i++){
		cin>>t>>w;
		if(t==1){
			a.push_back(w);
		}else{
			b.push_back(w);
		}
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	for(i=1;i<a.size();i++){
		a[i]+=a[i-1];
	}

	for(i=1;i<b.size();i++){
		b[i]+=b[i-1];
	}
	int j;
	int net=10000;
	int v;
	
	for(i=0;i<a.size();i++){
		w=a[i];
		v=a.size()-i-1+2*b.size();

		if(v>=w){
			net=min(net,v);
		}
	}

	for(i=0;i<b.size();i++){
		w=b[i];
		v=b.size()-i-1;

		v*=2;
		v+=a.size();

		

		if(v>=w){
			net=min(net,v);
		}
	}

	for(i=0;i<a.size();i++){

		for(j=0;j<b.size();j++){
			v=a.size()-i-1+2*(b.size()-j-1);
			w=a[i]+b[j];

			if(v>=w){
				net=min(net,v);
			}

		}



	}
	int x=a.size();
	x+=2*b.size();

	net=min(net,x);

	cout<<net<<endl;


	return 0;
}
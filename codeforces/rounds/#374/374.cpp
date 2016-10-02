#include<bits/stdc++.h>

using namespace std;

int a[105];
int net;
 

int main(){
	net=0;
	int i;
	int n;
	cin>>n;
	char c;
	int l=-1;
	for(i=0;i<n;i++){
		cin>>c;
		if(c=='B'){
			if(l==-1){
				l=1;
				net++;
			}else{
				l++;
			}
		}else{
			if(l!=-1)a[net]=l;
			l=-1;
		}
	}

	if(c=='B'){
		a[net]=l;
	}



	cout<<net<<endl;

	for(i=1;i<=net;i++){
		cout<<a[i]<<" ";
	}if(net>0)cout<<endl;





	return 0;
}
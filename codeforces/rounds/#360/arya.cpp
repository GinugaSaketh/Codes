#include<bits/stdc++.h>

using namespace std;

int a[105];

string s;

int main(){

	int n,d;
	cin>>n>>d;
	int i,j;
	int net=0;
	int l=0;
	int flag=0;

	for(i=0;i<d;i++){
		cin>>s;
		flag=0;
		for(j=0;j<n;j++){
			if(s[j]=='0'){
				flag=1;
				break;
			}
		}

		if(flag==1){
			net=max(net,i-l+1);
			
			continue;
		}else{
		
			net=max(net,i-l);
			l=i+1;
		}
	}

	cout<<net<<endl;





	return 0;
}
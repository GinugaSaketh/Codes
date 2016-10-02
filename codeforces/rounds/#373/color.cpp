//n==1 and n==2
#include<bits/stdc++.h>

using namespace std;

char c[100005];

int mo(int x){
	if(x<0)x=-x;

	return x;
}


int main(){
	
	int n,i;
	cin>>n;	
	for(i=1;i<=n;i++){
		cin>>c[i];
	}

	int odd=0;
	int even=0;

	for(i=1;i<=n;i++){
		if(i%2==0){
			if(c[i]!='r'){
				even++;
			}
		}else{
			if(c[i]!='b'){
				odd++;
			}
		}
	}

	int net=(min(odd,even)+mo(odd-even));


	int fo=(n+1)/2;

	odd=fo-odd;
	fo=n-fo;
	even=fo-even;


	net=min(net,(min(odd,even)+mo(odd-even)));

	cout<<net<<endl;


	return 0;
}
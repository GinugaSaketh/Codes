#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#include<stack>

using namespace std;

char str[205];


int main(){
	int n;
	cin>>n;
	int i,j,k;
	for(i=0;i<n;i++){
		cin>>str[i];
	}
	int net;
	int u=0,d=0,l=0,r=0;
	for(i=0;i<n;i++){
		
		for(j=i;j<n;j++){
			u=0;d=0;l=0;r=0;
			for(k=i;k<=j;k++){
				if(str[k]=='U'){
					u++;
				}
				if(str[k]=='D'){
					d++;
				}if(str[k]=='L'){
					l++;
				}
				if(str[k]=='R'){
					r++;
				}
			}
			if(d==u&&r==l){
			net+=1;
		}
		}
		//cout<<d<<" "<<u<<" "<<r<<" "<<l<<endl;
		

	}



	cout<<net<<endl;


	return 0;
}
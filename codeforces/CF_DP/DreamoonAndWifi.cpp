#include<bits/stdc++.h>

using namespace std;

int s,l;
int net=0;


void rec(int sum,int n){
	if(n==l){
		if(sum==s){
			net++;
		}
		return ;
	}

	rec(sum+1,n+1);
	rec(sum-1,n+1);

}




int main(){
	string p,q;

	cin>>p;
	cin>>q;
	l=0;
	s=0;
	int i;
	int flag=0;

	for(i=0;i<p.size();i++){

		if(q[i]=='?'){
			l++;
			if(p[i]=='+'){
				s++;
			}else{
				s--;
			}

		}else{
			if(p[i]!=q[i]){
				if(q[i]=='-'){
					s+=2;
				}else{
					s-=2;
				}

			}


		}

	}


	

	int sum=0;

	rec(sum,0);

	long double ans=1.0*net;

	for(i=0;i<l;i++){
		ans/=2.0;

	}

	cout<<setprecision(20)<<ans<<endl;

	return 0;
}
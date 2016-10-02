#include<bits/stdc++.h>

using namespace std;



long long c[100005];



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int i;

	for(i=1;i<=n;i++){
		cin>>c[i];
	}

	string a,b;
	a="";

	long long p=0,q=0;

	long long tp=-1,tq=-1;
	int j;
	for(j=1;j<=n;j++){
		cin>>b;
		tp=tq=-1;


		if(a<=b){
			tp=p;
		}

		reverse(b.begin(),b.end());

		if(a<=b){
			if(p==-1){
				tq=-1;
			}else{
				tq=c[j]+p;
			}
		}

		reverse(a.begin(),a.end());

		if(a<=b){
			if(tq==-1){
				if(q!=-1)
				tq=c[j]+q;
			}else{
				if(q!=-1){
					tq=min(c[j]+q,tq);
				}
			}
		}

		reverse(b.begin(),b.end());
		if(a<=b){
			if(q!=-1){
				if(tp==-1){
					tp=q;
				}else{
					tp=min(tp,q);
				}
			}
		}

		p=tp;
		q=tq;
		a=b;
	}

	if(p==-1&&q==-1){
		cout<<"-1"<<endl;
	}else if(p==-1){
		cout<<q<<endl;
	}else if(q==-1){
		cout<<p<<endl;
	}else{
		cout<<min(p,q)<<endl;
	}












	return 0;
}
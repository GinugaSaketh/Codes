#include<bits/stdc++.h>

using namespace std;

long long a[100005];
long long e[100005];


int main(){
	
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			e[i]=a[i];
		}
		long long net=a[1];
		if(n==2){
			net=min(net,a[2]);
			cout<<net<<endl;
			cout<<"a"<<endl;
			continue;
		}
		if(n==3){
			net=min(net,a[2]);
			net=min(net,a[3]);
			cout<<net<<endl;
			cout<<"b"<<endl;
			continue;
		}
		long long l=a[n];
		//n>=4
		long long x=a[1];
		for(i=n;i>=2;i--){
			a[i]-=a[i-1];
		}


		int flag=2;
		for(i=n;i>=4;i--){
			if(a[i]!=a[i-1]){
				//cout<<a[i]<<" "<<a[i-1]<<endl;
				flag=0;
				break;
			}
		}
		//cout<<flag<<endl;
		if(flag==2&&a[2]!=a[3]){
			flag=1;
		}
		if(flag==2){
			net=min(a[i],l);
			cout<<net<<endl;
			cout<<"c"<<endl;
			continue;
		}
		long long s=0;
		for(i=2;i<=n;i++){
			s+=a[i];
		}
		long long d;
		if(s%(n-2)!=0){
			if(flag==1){
				cout<<net<<endl;
			}else{
				int f1=1;
				for(i=2;i<n-1;i++){
					if(a[i]!=a[i+1]){
						f1=0;
						break;
					}
				}
				if(f1==1){
					cout<<e[n]<<endl;
				}else{
					cout<<"-1"<<endl;
				}


				//cout<<"-1"<<endl;
			}
			cout<<"d"<<endl;
			continue;
		}else{
			d=s/(n-2);
		}
		int f=1;
		int c=-1,b=-1;
		for(i=2;i<=n;i++){
			if(a[i]!=d){
				if(c==-1){
					c=i;
				}else if(b==-1){
					b=i;
				}else{
					f=0;
				}
			}
		}
		if(f==0){
			if(flag==1){
				cout<<net<<endl;
			}else{
				cout<<"-1"<<endl;
			}
		  	cout<<"e"<<endl;
			continue;
		}else if((c+1==b&&a[c]+a[b]==d)){
			if(flag==1)net=min(net,e[c]);
			else net=e[c];
			cout<<net<<endl;
			cout<<"f"<<endl;
			continue;
		}else{
			if(flag==1){
				cout<<net<<endl;
			}else{
				cout<<"-1"<<endl;
			}
			cout<<"g"<<endl;
		}






	}







	return 0;
}
#include<iostream>
#include<cstring>

using namespace std;

char e[10005];


int main(){
	int t;

	cin>>t;
	int i,j;


	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int n=a+b+c+d+1;
		if(a>=1&&d>=1){
			if(b+c==0){
				cout<<"impossible"<<endl;
				
				continue;
			}
			
		}
		if(c==b&&b==0){
			if(a>=1){
				for(i=0;i<n;i++){
					cout<<"0";
				}cout<<endl;
				continue;
			}
			if(d>=1){
				for(i=0;i<n;i++){
					cout<<"1";
				}cout<<endl;
				continue;
			}

		}
		int x=b-c;
		if(x<0){
			x=-x;
		}

		if(x>1){
			cout<<"impossible"<<endl;
			continue;
		}
		e[1]='1';
		for(i=2;i<=d+1;i++){
			e[i]='1';
		}
		for(i=d+2;i<=a+d+2;i++){
			e[i]='0';
		}
		int y=1;
		for(i=a+d+3;i<=n;i++){
			if(y==1){
				e[i]='1';
				y=0;
			}else{
				e[i]='0';
				y=1;
			}
		}
		if(c>=b){
			for(i=1;i<=n;i++){
				cout<<e[i];
			}cout<<endl;
		}else{
			for(i=n;i>=1;i--){
				cout<<e[i];
			}cout<<endl;
		}
	}



	return 0;
}
#include<iostream>
#include<cmath>


using namespace std;

long long n,x,q;

long long h,h1;



long long tp[62];

int main(){
	int t;
	cin>>t;
	/*n=11;
	long long height=(long long )log2((long double)n);
	cout<<height<<endl;
	n=1;
	height=(long long )log2((long double)n);
	cout<<height<<endl;
	*/
	int i;

	tp[0]=1;
	for(i=1;i<=61;i++){
		tp[i]=tp[i-1]*2;
	}

	while(t--){
		cin>>n;

		cin>>q;
		h=(long long )log2((long double)n);
		while(q--){
			cin>>x;
			h1=(long long )log2((long double)x);
			long long l=x;
			
			h1=h-h1;
			l=l*tp[h1];

			long long leaves;
			if(l>n){
				leaves=tp[h1-1];
			}else{
				if(n>l+tp[h1]-1){
					leaves=tp[h1];
				}else{
					leaves=n-l+1;
					leaves+=(l+tp[h1]-1-n)/2;

				}

			}
			cout<<leaves<<endl;

		}


	}



	return 0;
}
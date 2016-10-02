#include<iostream>

using namespace std;

int main(){

	int a,b,c,n;

	cin>>n>>a>>b>>c;
	int t;

	
	int a_=n/a;
	int b_=n/b;
	

	int i,j,k;

	int net=0;
	int flag=0;

	if(a==1){
		cout<<n<<endl;
		return 0;
	}


	for(i=a_;i>=0;i--){
		
		for(j=b_;j>=0;j--){
				
				int r=n-i*a-j*b;	

				if(r>=0&&r%c==0){
					k=r/c;

					net=max(net,i+j+k);
				}




		}
		
	}


	cout<<net<<endl;



	return 0;
}
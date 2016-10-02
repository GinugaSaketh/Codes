#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int i;
		int r=0,b=0,g=0;
		char c;
		for(i=0;i<n;i++){
			cin>>c;
			if(c=='R'){
				r++;
			}if(c=='B'){
				b++;
			}if(c=='G'){
				g++;
			}
		}

		int mx=r;
		if(b>mx)mx=b;
		if(g>mx)mx=g;

		n-=mx;
		cout<<n<<endl;




	}

	return 0;
}
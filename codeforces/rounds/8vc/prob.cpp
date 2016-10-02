#incldue<iostream>

using namespace std;

int main(){
	int b=0,r=0,g=0;
	int n;
	cin>>n;
	char c;
	int i;

	for(i=0;i<n;i++){
		cin>>c;
		if(c=='B'){
			b++;
		}if(c=='R'){
			r++;
		}
		if(c=='G'){
			g++;
		}
	}
	

	return 0;
}
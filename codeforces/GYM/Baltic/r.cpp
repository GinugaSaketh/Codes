#include<iostream>
#include<cstring>


using namespace std;

string a,b;

string c;

int main(){
	
	int n,x,m,i;
	cin>>n>>x;
	cin>>a;

	cin>>m;
	
	cin>>b;

	c="";

	c+=a[x-1];
	for(i=0;i<m;i++){
		if(b[i]=='L'){
			x--;

		}
		if(b[i]=='R'){
			
			x++;
		}
		
		c+=a[x-1];
	}

	cout<<c<<endl;





	return 0;
}
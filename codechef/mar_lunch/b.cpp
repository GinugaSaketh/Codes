#include <iostream>

using namespace std;


int main(){
	int t;

	cin>>t;

	while(t--){
		int h,m;

		
		cin>>h>>m;
		h--;
		m--;
		int i,x,y;
		int b[15][2];		
		if(h<10){
			for(i=0;i<=h;i++){
				b[i][0]=1;
			}
			for(i=h+1;i<=9;i++){
				b[i][0]=0;
			}
		}else{
			x=h/10;
			y=h%10;
			b[0][0]=1;
			if(x<=y){
				for(i=1;i<=x;i++){
				b[i][0]=2;
			}
			for(i=x+1;i<=9;i++){
				b[i][0]=1;
			}	
			}else{
				for(i=1;i<x;i++){
				b[i][0]=2;
			}
			for(i=x;i<=9;i++){
				b[i][0]=1;
			}
			}
		}
		if(m<10){
			for(i=0;i<=m;i++){
				b[i][1]=1;
			}
			for(i=m+1;i<=9;i++){
				b[i][1]=0;
			}
		}else{
			x=m/10;
			y=m%10;
			b[0][1]=1;
			if(x<=y){
				for(i=1;i<=x;i++){
				b[i][1]=2;
			}
			for(i=x+1;i<=9;i++){
				b[i][1]=1;
			}	
			}else{
				for(i=1;i<x;i++){
				b[i][1]=2;
			}
			for(i=x;i<=9;i++){
				b[i][1]=1;
			}
			}
		}
		b[0][0]=1;
		b[0][1]=1;
		int net=0;
		for(i=0;i<=9;i++){
			net+=(b[i][0]*b[i][1]);
			//cout<<b[i][0]<<" "<<b[i][1]<<endl;
		}
		cout<<net<<endl;
	}



	return 0;
}
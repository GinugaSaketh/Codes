#include<iostream>
#include<map>


using namespace std;

long long n,m;

map<long long ,long long> a;

//map <long long ,long long  > b; 

long long b[2000005][2];
	

int main(){
	cin>>n;
	long long x,y;
	long long i;
	for(i=0;i<n;i++){
		cin>>x;
		a[x]++;
	}


	cin>>m;
	x=-1;y=-1;
	long long in=1;


	for(i=0;i<m;i++){
		cin>>b[i][0];
	}
	for(i=0;i<m;i++){
		cin>>b[i][1];
	}


	for(i=0;i<m;i++){
		//cin>>b[0]>>b[1];
		if(x==-1&&y==-1){
			x=b[i][0];
			y=b[i][1];
			in=i;
			

		}else{
			
				if(a[x]<a[b[i][0]]){
					x=b[i][0];
					y=b[i][1];
					in=i;
				}else  {
					if(a[x]==a[b[i][0]]&&a[y]<a[b[i][1]]){
					x=b[i][0];
					y=b[i][1];
					in=i;
					}
				}
			
		}

	}
	in++;

	cout<<in<<endl;







	return 0;
}

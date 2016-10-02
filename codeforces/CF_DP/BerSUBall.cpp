//TO Do-Maximum bipartite matching 




#include<bits/stdc++.h>

using namespace std;

vector <int > b,g;
int i,j;



int abs(int x){
	if(x>0){
		return x;
	}else{
		return -x;
	}
}



int main(){

	int n;
	int m;
	cin>>n;
	b.resize(n);


	for(i=0;i<n;i++){
		cin>>b[i];
	}
	cin>>m;
	g.resize(m);
	for(i=0;i<m;i++){
		cin>>g[i];
	}


	sort(b.begin(),b.end());
	sort(g.begin(),g.end());

	int net=0;

	for(i=n-1;i>=0;i--){
		for(j=m-1;j>=0;j--){
			if(abs(b[i]-g[j])<=1){
				
				//cout<<b[i]<<" "<<g[j]<<endl;
				net++;
				g[j]=-100;
				break;
			}
		}
	}


	cout<<net<<endl;








	return 0;
}
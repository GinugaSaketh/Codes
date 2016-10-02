#include<bits/stdc++.h>

using namespace std;

vector <int> p;


int pf[5000005];

int x[5000005];


int main(){
	int t;

	scanf("%d",&t);
	int i;
	int a,b;
	for(i=0;i<5000005;i++){
	//	pd[i]=-1;
		pf[i]=1;
		//x[i]=1;
	}
	pf[0]=0;
	pf[1]=0;

	int j;
	for(i=2;i<5000005;i++){
		if(pf[i]==1){
			p.push_back(i);
			//pf[i]=1;
			for(j=2;i*j<5000005;j++){
				pf[i*j]=0;
			}
		}
	}

	for(i=2;i<=5000000;i++){
		if(pf[i]==1){
			continue;
		}

		for(j=0;j<p.size();j++){
			if(i%p[j]==0){
				break;
			}
		}
		pf[i]=pf[i/p[j]]+1;
	}	

	for(i=2;i<=5000000;i++){
		pf[i]+=pf[i-1];
	}


	//cout<<p.size()<<endl;

	int net;

	for(i=0;i<t;i++){
		scanf("%d%d",&a,&b);

		net=pf[a]-pf[b];


		printf("%d\n",net);

	}



	return 0;
}
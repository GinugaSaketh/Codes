#include<bits/stdc++.h>


using namespace std;



int a[100005];


int v[105][105];



int main(){

	int n;
	int p,q;
	int i,j;
	scanf("%d%d",&n,&q);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<105;i++){
		for(j=0;j<105;j++){
			v[i][j]=0;
		}
	}

	for(i=0;i<n;i++){

		for(j=1;j<=100;j++){
			v[j][i%j]+=a[i];
		}
	}






	while(q--){
		int x,y;

		scanf("%d%d",&y,&x);

		if(x<=100){
			//cout<<v[x][y]<<endl;
			printf("%d\n",v[x][y]);
		}else{
			int net=0;

			for(i=y;i<n;i+=x){
				net+=a[i];


			}
			printf("%d\n",net);
			//cout<<net<<endl;
		}



	}






	return 0;
}
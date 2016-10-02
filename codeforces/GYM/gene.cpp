#include<bits/stdc++.h>

using namespace std;

int a[100005];

int b[100005][2];

int  main(){
	
	int i,l,r,t;
	
	int te;
	//cin>>te;

	scanf("%d",&te);

	while(te--){
		l=1;
		t=0;
	int n;
	//cin>>n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		//cin>>b[i][0];
		scanf("%d",&b[i][0]);
	}
	for(i=1;i<=n;i++){
		//cin>>b[i][1];
		scanf("%d",&b[i][1]);
	}

	for(i=1;i<=n;i++){
		a[i]=0;
	}


	for(i=1;i<=n;i++){
		a[b[i][0]]++;
		if(a[b[i][0]]==2)t++;

		a[b[i][1]]++;
		if(a[b[i][1]]==2)t++;

		if(i-l+1==t){
			//cout<<l<<"-"<<i<<" "; 
			printf("%d-%d ",l,i);
			t=0;
			l=i+1;
		}

	}
	printf("\n");



	}




	return 0;
}
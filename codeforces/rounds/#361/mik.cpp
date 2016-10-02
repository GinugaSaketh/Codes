#include<bits/stdc++.h>

using namespace std;

int a[200005];

int d[200005];


queue <int> q;


int main(){
	
	int n;
	cin>>n;
	int i;
	for(i=0;i<=n;i++){
		d[i]=-1;
	}

	for(i=1;i<=n;i++){
		cin>>a[i];
	}

	d[1]=0;
	q.push(1);

	while(q.size()!=0){
		int u=q.front();
		q.pop();
		int v=u+1;

		if(v<=n&&d[v]==-1){
			d[v]=d[u]+1;
			q.push(v);
		}
		v=u-1;
		if(v>=1&&d[v]==-1){
			d[v]=d[u]+1;
			q.push(v);
		}
		v=a[u];
		if(v>=1&&d[v]==-1){
			d[v]=d[u]+1;
			q.push(v);
		}
	}

	for(i=1;i<=n;i++){
		cout<<d[i]<<" ";
	}cout<<endl;



	return 0;
}
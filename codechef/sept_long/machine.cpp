#include<bits/stdc++.h>

using namespace std;

vector<int> p;
int n,m;
int b[1005];
int a[100005];

int tree[(int)(4e5+5)][2];

int lp(int b){
	if(b==1)return 1;
	int i;
	for(i=0;i<p.size();i++){
		if(b%p[i]==0){
			return p[i]; 
		}
	}
	return b;

}


int full(int a,int b,int c){
	if(a==c-b+1){
		return 1;
	}else{
		return 0;
	}
}




void build (int v,int left, int right){

	if(left==right){
		tree[v][0]=lp(a[left]);
		if(a[left]==1){
			tree[v][1]=1;
		}else {
			tree[v][1]=0;
		}
		return;
	}

	int mid=(left+right)/2;

	int leftnode=2*v;
	int rightnode =2*v+1;

	build(leftnode,left,mid);
	build(rightnode,mid+1,right);

	tree[v][0]=max(tree[leftnode][0],tree[rightnode][0]);
	tree[v][1]=tree[leftnode][1]+tree[rightnode][1];

}


int query(int v,int left ,int right,int l,int r){

	if(left==l&&right==r){
		//cout<<l<<" "<<tree[v][0]<<endl;
		return tree[v][0];
	}
	int mid=(left+right)/2;
	if(r<=mid){
		return query(2*v,left,mid,l,r);
	}
	if(l>mid){
		return query(2*v+1,mid+1,right,l,r);
	}
	int t=max(query(2*v,left,mid,l,mid),query(2*v+1,mid+1,right,mid+1,r));
	return t;
}


void build1(int v,int left,int right){
	if(full(tree[v][1],left,right)){
		return;
	}
	if(left==right){
		a[left]/=lp(a[left]);
		tree[v][0]=lp(a[left]);
		
		if(a[left]==1){
			tree[v][1]=1;
		}else {
			tree[v][1]=0;
		}
		return;
	}

	int mid=(left+right)/2;

	int leftnode=2*v;
	int rightnode =2*v+1;

	build1(leftnode,left,mid);
	build1(rightnode,mid+1,right);

	tree[v][0]=max(tree[leftnode][0],tree[rightnode][0]);
	tree[v][1]=tree[leftnode][1]+tree[rightnode][1];

}

void update(int v,int left,int right,int l,int r){


	if(left==l&&right==r){
		if(!full(tree[v][1],l,r)){
			build1(v,left,right);
		}
		return;
	}
	int mid=(left+right)/2;

	if(r<=mid){
		update(2*v,left,mid,l,r);
		tree[v][0]=max(tree[2*v][0],tree[2*v+1][0]);
		tree[v][1]=tree[2*v][1]+tree[2*v+1][1];
		return ;
	}
	if(l>mid){
		update(2*v+1,mid+1,right,l,r);
		tree[v][0]=max(tree[2*v][0],tree[2*v+1][0]);
		tree[v][1]=tree[2*v][1]+tree[2*v+1][1];
		//cout<<v<<" v "<<tree[v][0]<<endl;
		return;
	}

	update(2*v,left,mid,l,mid);
	update(2*v+1,mid+1,right,mid+1,r);

	tree[v][0]=max(tree[2*v][0],tree[2*v+1][0]);
	tree[v][1]=tree[2*v][1]+tree[2*v+1][1];

	

}






int main(){

	int i,j;

	for(i=0;i<1005;i++){
		b[i]=0;
	}

	for(i=2;i<=1000;i++){
		if(b[i]==0){
			p.push_back(i);
			for(j=2;i*j<=1000;i++){
				b[i*j]=1;
			}
		}
	}



	int t;
	cin>>t;

	int tp,p,q,net;

	while(t--){
		
		cin>>n>>m;

		for(i=1;i<=n;i++){
			cin>>a[i];
		}

		build(1,1,n);
		for(j=0;j<m;j++){
			cin>>tp>>p>>q;

			if(tp==0){
				update(1,1,n,p,q);
			}else{
				/*cout<<"$  ";
				for(i=1;i<=n;i++){
					cout<<a[i]<<" ";
				}cout<<endl;
				*/
				net=query(1,1,n,p,q);
				cout<<net<<" ";
			}
		}cout<<endl;
	}





	return 0;
}
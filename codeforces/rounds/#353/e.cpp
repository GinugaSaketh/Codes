#include<iostream>

using namespace std;

long long a[100005];

long long dp[100005];


long long tree[(long long)(4e5)+5];


void build(long long v,long long left ,long long right){
	if(left==right){
		//tree[v]=make_matrix(a[left]);
		//cout<<tree[v].m[0][0]<<endl;
		tree[v]=left;

		return ;
		
	}
	long long mid=(left+right)/2;
	long long leftnode=2*v;
	long long rightnode=2*v+1;
	build(leftnode,left,mid);
	build(rightnode,mid+1,right);
 
	if(a[tree[leftnode]]>a[tree[rightnode]]){
		tree[v]=tree[leftnode];
	}else{
		tree[v]=tree[rightnode];
	}

	//tree[v]=max(tree[leftnode],tree[rightnode]);
 
} 
 

//l,r->for range
long long query(long long v,long long left,long long right,long long l,long long r){
	
	if(left==l&&right==r){
		return tree[v];
	}
 
	long long mid=(left+right)/2;
		//check = case
	if(r<=mid){
		return query(2*v,left,mid,l,r);
	}
	if(l>mid){
		return query(2*v+1,mid+1,right,l,r);
	}
 
	long long tmp1=query(2*v,left,mid,l,mid);
	long long tmp2=query(2*v+1,mid+1,right,mid+1,r);
	long long tmp3;
	if(a[tmp1]>a[tmp2]){
		tmp3=tmp1;
	}else{
		tmp3=tmp2;
	}

	//long long tmp3=max(tmp1,tmp2);
 
	return tmp3;
 
}
 



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	long long i;
	cin>>n;

	//let 0 indexed

	for(i=1;i<=n-1;i++){
		cin>>a[i];
		//a[i]-=1;
	}
	a[n]=0;
	dp[n]=0;

	build(1,1,n);


	
	///cout<<"done"<<endl;

	for(i=n-1;i>=1;i--){
		//long long m=range_max(i+1,ai);
		long long m=query(1,1,n,i+1,a[i]);

		dp[i]=dp[m]+m+n-i-a[i];
	}
	long long net=0;

	for(i=1;i<n;i++){
		net+=dp[i];
	}	

	cout<<net<<endl;






	return 0;
}

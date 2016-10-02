#include<iostream>

using namespace std;

typedef long long ll;

ll M=(ll)(1e9+7);

int n,m;
char c;
long long a[100005];


struct matrix {
	ll m[2][2];



	matrix operator * (matrix b){
		matrix c;

		c.m[0][0]=0;
		c.m[1][0]=0;
		c.m[0][1]=0;
		c.m[1][1]=0;



		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					c.m[i][j]=(c.m[i][j]+(1LL*m[i][k]*b.m[k][j])%M)%M;
				}
			}
		}
		return c;
	}
	matrix operator + (matrix b){
		matrix c;
		
		for(int i =0;i<2;i++){
			for(int j=0;j<2;j++){
				c.m[i][j]=(m[i][j]+b.m[i][j])%M;
			}
		}


	}

};

/////////////////////////////////////////
matrix fib;
matrix unit;

////////////////////////////////////////////




matrix modpow(matrix x,ll n){
	if(n==0){
		matrix t;
		t.m[0][0]=1;
		t.m[0][1]=0;
		t.m[1][0]=0;
		t.m[1][1]=1;
		return t;
	}
	if(n==1){
		return x;
	}

	matrix tmp=modpow(x,n/2LL);
	matrix net=tmp*tmp;

	if(n%2==1){
		net=net*tmp;
	}

	return net;

}

matrix make_matrix(ll n){

	matrix tm=modpow(fib,n);
	tm=tm+unit;
	return tm;


}


matrix tree[(ll)(4e5)+5];

void build(int v,int left ,int right){
	if(left==right){
		tree[v]=make_matrix(a[left]);
		return ;
	}
	int mid=(left+right)/2;
	int leftnode=2*v;
	int rightnode=2*v+1;
	build(leftnode,left,mid);
	build(rightnode,mid+1,right);

	tree[v]=tree[leftnode]*tree[rightnode];

} 


//l,r->for range
matrix query(int v,int left,int right,int l,int r){
	if(left==l&&right==r){
		return tree[v];
	}

	int mid=(left+right)/2;
		//check = case
	if(r<=mid){
		return query(2*v,left,mid,l,r);
	}
	if(l>mid){
		return query(2*v+1,mid+1,right,l,r);
	}

	matrix tmp1=query(2*v,left,mid,l,mid);
	matrix tmp2=query(2*v+1,mid+1,right,mid+1,r);
	matrix tmp3=tmp1*tmp2;

	return tmp3;

}

void update (int v,int left ,int right,int pos){
	if(left==right&&right==pos){
		matrix tp=make_matrix(a[pos]);
		tree[v]=tp;
		return ;
	}
	int mid=(left+right)/2;
	if(pos<=mid){
		update(2*v,left,mid,pos);
	}else{
		update(2*v+1,mid+1,right,pos);
	}

	tree[v]=tree[2*v]*tree[2*v+1];

}



ll F_sum;



int main(){
	fib.m[0][0]=1;
	fib.m[1][0]=1;
	fib.m[0][1]=1;
	fib.m[1][1]=0

	unit.m[0][0]=1;
	unit.m[0][1]=0;
	unit.m[1][0]=0;
	unit.m[1][1]=1;


	int p,q;
	
	cin>>n>>m;

	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	build(1,1,n);




	for(i=0;i<m;i++){
		cin>>c;
		cin>>p>>q;
		if(c=='C'){
			a[p]=q;
			update(1,1,n,p);
		}
		if(c=='Q'){
			matrix ab=query(1,1,n,p,q);
			F_sum=(ab.m[0][0])+(ab.m[0][1]);
			cout<<F_sum<<endl;
		}

//		cout<<c<<"  "<<p<<"  "<<q;
		}


	return 0;
}
    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    //typedef long long ll;
     
    ll M=(ll)(1e9+7);

     
    int n,m;
    char c;
    long long a[100005];
     
     
    struct matrix {
    	ll m[2][2];
     
    	matrix()
    	{
    		memset(m,0,sizeof(m));
    	}
     
    	matrix operator * (matrix b){
    		matrix c;
     
    		/*c.m[0][0]=0;
    		c.m[1][0]=0;
    		c.m[0][1]=0;
    		c.m[1][1]=0;
            */
     
     
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
    		return c;
     
    	}
     
    };
     
    /////////////////////////////////////////
    matrix fib;
    matrix unit;
     
    ////////////////////////////////////////////
     
     
     
     
    matrix modpow(matrix x,ll n){
    	if(n<=0){
    		return unit;
    	}
    	if(n==1){
    		return x;
    	}
     
    	matrix tmp=modpow(x,n/2);
    	matrix net=tmp*tmp;
     
    	if(n%2==1){
    		net=net*x;
    	}
     
    	return net;
     
    }
     
    matrix make_matrix(ll n){
     
    //..	cout<<"n here "<<n<<" ";
    	matrix tm=modpow(fib,n);
    ///	cout<<tm.m[0][0]<<" ";
    	//tm=tm+unit;
    //	cout<<tm.m[0][0]<<endl;
    	return tm;
     
     
    }
     
     
    matrix tree[(ll)(4e5)+5];
    matrix tree1[(ll)(4e5)+5];
     
    void build(int v,int left ,int right){
    	if(left==right){
    		tree[v]=make_matrix(a[left]-1);
    		//cout<<tree[v].m[0][0]<<endl;
    		
            tree1[v]=unit;
            return ;
    		
    	}
    	int mid=(left+right)/2;
    	int leftnode=2*v;
    	int rightnode=2*v+1;
    	build(leftnode,left,mid);
    	build(rightnode,mid+1,right);
     
    	tree[v]=tree[leftnode]+tree[rightnode];
        tree1[v]=unit;
    } 
     
   
    //l,r->for range
    matrix query(int v,int left,int right,int l,int r){
    	if(left==l&&right==r){
    		
            return tree[v]*tree1[v];
    	}
     
    	int mid=(left+right)/2;
    		//check = case
    	if(r<=mid){
    		return query(2*v,left,mid,l,r)*tree1[v];
    	}
    	if(l>mid){

    		return query(2*v+1,mid+1,right,l,r)*tree1[v];
    	}
     
    	matrix tmp1=query(2*v,left,mid,l,mid);
    	matrix tmp2=query(2*v+1,mid+1,right,mid+1,r);
    	matrix tmp3=tmp1+tmp2;
        tmp3=tmp3*tree1[v];
    	return tmp3;
     
    }
matrix up;

    matrix update(int v,int left,int right,int l,int r){
        if(left==l&&right==r){
            
            tree1[v]=tree1[v]*up;
            return unit;    
            //return tree[v]*tree1[v];
        }
     
        int mid=(left+right)/2;
            //check = case
        if(r<=mid){
            return query(2*v,left,mid,l,r);
        }else if(l>mid){

            return query(2*v+1,mid+1,right,l,r);
        }else{
            return query(2*v,left,mid,l,mid)+query(2*v+1,mid+1,right,mid+1,r);
        }
     /*
        matrix tmp1=query(2*v,left,mid,l,mid);
        matrix tmp2=query(2*v+1,mid+1,right,mid+1,r);
        matrix tmp3=tmp1*tmp2;
        tmp3*=tree1[v];
        return tmp3;*/
     
    }
     


  /*  void update (int v,int left ,int right,int pos){
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
     
    */ 
     
    ll F_sum;
     
     
     
    int main(){
    	fib.m[0][0]=1;
    	fib.m[1][0]=1;
    	fib.m[0][1]=1;
    	fib.m[1][1]=0;
     
    	unit.m[0][0]=1;
    	unit.m[0][1]=0;
    	unit.m[1][0]=0;
    	unit.m[1][1]=1;
     
    //	matrix test=modpow(unit,10);
    //	for(int i=0;i<2;i++)
    //	{
    //		for(int j=0;j<2;j++)
    //			cout<<test.m[i][j]<<" ";
    //		cout<<endl;
    //	}
    //	test=modpow(fib,3);
    //	for(int i=0;i<2;i++)
    //	{
    //		for(int j=0;j<2;j++)
    //			cout<<test.m[i][j]<<" ";
    //		cout<<endl;
    //	}
     
    	/*int p,q;
    	
    	cin>>n>>m;
     
    	int i;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    	}
    	build(1,1,n);
     
     
     
     
    	for(i=0;i<m;i++){
    		//cin>>c;
    		cin>>c>>p>>q;
    		if(c=='C'){
    			a[p]=q;
    			update(1,1,n,p);
    		}
    		if(c=='Q'){
    			matrix ab=query(1,1,n,p,q);
    			F_sum=((0*ab.m[0][0])+(ab.m[0][1]))%M;
    			cout<<F_sum<<endl;
    		}
     
    	//cout<<c<<"  "<<p<<"  "<<q;
    		}
     
     */


        cin>>n>>m;
     
        int i;
        for(i=1;i<=n;i++){
            cin>>a[i];
        }
        build(1,1,n);
        int tp,l_,r_,x_;
        for(int j=1;j<=m;j++){
            cin>>tp>>l_>>r_;

            if(tp==1){
                cin>>x_;
            }
            if(tp==1){
                up=make_matrix(x_);
                update(1,1,n,l_,r_);
            }else{

                matrix ab=query(1,1,n,l_,r_);

                F_sum=((1*ab.m[0][0])+(0*ab.m[0][1]))%M;
                cout<<F_sum<<endl;


            }


        }











    	return 0;
    } 
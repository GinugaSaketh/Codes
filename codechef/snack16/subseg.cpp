#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct node{
    vector< ll> a;
    vector <ll > b;
    vector <ll > pa;
    vector <ll > pb;
};

 
ll A[100005],B[100005];
ll x;
ll c,d;


node tree[(int)(4e5)+5];

void build(int v,int left ,int right){
    if(left==right){
    	//index of array left

        tree[v].a.push_back(A[left]);
        tree[v].b.push_back(B[left]);

        tree[v].pa.push_back(A[left]);
        tree[v].pb.push_back(B[left]);
    	return ;
    }    	
    int mid=(left+right)/2;
    int leftnode=2*v;
    int rightnode=2*v+1;
    build(leftnode,left,mid);
    build(rightnode,mid+1,right);
    
    
    //combine tree[leftnode] and tree[rightnode]

    int i=0,j=0;
    while(i<tree[leftnode].a.size()&&j<tree[rightnode].a.size()){
        //descending order

        if((tree[leftnode].a)[i]==0&&(tree[leftnode].b)[i]==0){
            tree[v].a.push_back((tree[leftnode].a)[i]);
            tree[v].b.push_back((tree[leftnode].b)[i]);
            i++;
            continue;
        }


        if((tree[rightnode].a)[j]==0&&(tree[rightnode].b)[j]==0){
            tree[v].a.push_back((tree[rightnode].a)[j]);
            tree[v].b.push_back((tree[rightnode].b)[j]);
            j++;
            continue;
        }
        if(((tree[leftnode].a)[i])*((tree[rightnode].b)[j])<((tree[leftnode].b)[i])*((tree[rightnode].a)[j])){
            //(tree[v].ab).push_back((tree[rightnode].ab)[j]);
            (tree[v].a).push_back((tree[rightnode].a)[j]);
            (tree[v].b).push_back((tree[rightnode].b)[j]);
            j++;
        }else{
         
            //tree[v].ab.push_back((tree[leftnode].ab)[i]);
            tree[v].a.push_back((tree[leftnode].a)[i]);
            tree[v].b.push_back((tree[leftnode].b)[i]);
            i++;
        }
    }

    while(i<tree[leftnode].a.size()){
            //tree[v].ab.push_back((tree[leftnode].ab)[i]);
            tree[v].a.push_back((tree[leftnode].a)[i]);
            tree[v].b.push_back((tree[leftnode].b)[i]);
            i++;
    }

    while(j<tree[rightnode].a.size()){
        //tree[v].ab.push_back((tree[rightnode].ab)[j]);
        tree[v].a.push_back((tree[rightnode].a)[j]);
        tree[v].b.push_back((tree[rightnode].b)[j]);
        j++;
    }


    x=0;

   // cout<<left<<" qwertys "<<right<<endl;

    for(i=0;i<tree[v].a.size();i++){
        
        x+=(tree[v].a)[i];
       // cout<<(tree[v].a)[i]<<" ";
        (tree[v].pa).push_back(x);
    }//cout<<endl;

    x=0;

    for(i=0;i<tree[v].b.size();i++){
        x+=(tree[v].b)[i];
       // cout<<(tree[v].b)[i]<<" ";
        (tree[v].pb).push_back(x);
    }//cout<<endl;

} 
    
  //l,r->for range   
ll query(int v,int left,int right,int l,int r){
    if(left==l&&right==r){
    	int p=0;
        int q=tree[v].a.size()-1;

        while(p<q){
            int mid=(p+q+1)/2;

            if(((tree[v].a)[mid])*c-d*((tree[v].b)[mid])<=0){
                q=mid-1;
                //p=mid+1;
            }else{
                p=mid;
                //q=mid;
            }
        }
        if(((tree[v].a)[p])*c-d*((tree[v].b)[p])<0){
            p--;
        }

       /* int i;
        //p--;
        //cout<<tree[v].a.size()<<endl;
        for(i=0;i<tree[v].a.size();i++){
            //cout<<"YES"<<endl;
            if(((tree[v].a)[i])*c-d*((tree[v].b)[i])>0){
                continue;
            }else{
                break;
            }   
        }
        p=i-1;*/
        //cout<<p<<endl;
        if(p<0){
            return 0;
        }else{
            ll net=c*((tree[v].pa)[p])-d*((tree[v].pb)[p]);

            return net;
        } 
    }     
    int mid=(left+right)/2;
    	//check = case
    if(r<=mid){
    	return query(2*v,left,mid,l,r);
    }
    if(l>mid){
    	return query(2*v+1,mid+1,right,l,r);
    }
     
    ll tmp1=query(2*v,left,mid,l,mid);
    ll tmp2=query(2*v+1,mid+1,right,mid+1,r);
    ll tmp3=tmp1+tmp2;
     
    return tmp3;
     
}


int main(){

    int i,n,q;
    int l,r;



    scanf("%d",&n);

    for(i=1;i<=n;i++){
        scanf("%lld",&A[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&B[i]);
    }

    build(1,1,n);
    cout<<"YES"<<endl;

    scanf("%d",&q);
   

    for(i=0;i<q;i++){
        scanf("%d%d%lld%lld",&l,&r,&c,&d);

        ll ne=query(1,1,n,l,r);

        printf("%lld\n",ne);

        fflush(stdout);



    }

	
    return 0;
} 
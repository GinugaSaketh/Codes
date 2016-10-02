#include<bits/stdc++.h>

using namespace std;

pair <int,int> tree[(int)(8e5+5)];
int a[200005];
int b[200005];


void build(int v,int left,int right){
	if(left==right){
		tree[v].first=a[left];
		tree[v].second=b[left];
		return;
	}
	int mid=(left+right)/2;
	int leftnode=2*v;
	int rightnode=2*v+1;
	build(leftnode,left,mid);
	build(rightnode,mid+1,right);

	tree[v].first=max(tree[leftnode].first,tree[rightnode].first);
	tree[v].second=min(tree[leftnode].second,tree[rightnode].second);
}


// range l->r
pair<int,int> query(int v,int left,int right,int l,int r){

	//cout<<left<<" "<<right<<endl;
	if(left==l&&right==r){
		return tree[v];
	}
	int mid=(left+right)/2;

	if(r<=mid){
		return query(2*v,left,mid,l,r);
	}

	if(l>mid){
		return query(2*v+1,mid+1,right,l,r);
	}

	pair <int,int> p=query(2*v,left,mid,l,mid);
	pair <int,int> q=query(2*v+1,mid+1,right,mid+1,r);
	pair <int,int> r_;
	r_.first=max(p.first,q.first);
	r_.second=min(p.second,q.second);
	return r_;
}




int main(){
	
	int n;
	cin>>n;
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}

	build(1,1,n);
	pair<int,int > c;




	long long net=0;

	int mi,mx;
	
	int l,r;
	for(i=1;i<=n;i++){
		mi=-1;

		l=i,r=n;

		while(l<=r){
			//cout<<i<<" "<<l<<" d "<<r<<endl;
			if(l==r){

				c=query(1,1,n,i,l);

				if(c.first==c.second){

					if(mi==-1){
						mi=l;
					}else{
						mi=min(mi,l);
					}

				}

				break;

			}

			int mid=(l+r)/2;

			c=query(1,1,n,i,mid);

			if(c.first==c.second){
				if(mi==-1){
					mi=mid;
				}else{
					mi=min(mi,mid);
				}
				r=mid-1;
			}else if(c.first>c.second){
				r=mid-1;
			}else if(c.first<c.second){
				l=mid+1;
			}
		}

		if(mi!=-1){
			mx=-1;
			l=i,r=n;

			while(l<=r){
				if(l==r){
					c=query(1,1,n,i,l);

					if(c.first==c.second){
						//cout<<c.second<<endl;
						if(mx==-1){
							mx=l;
						}else{
							mx=max(mx,l);
						}
					}
					break;
				}

				int mid=(l+r)/2;
				c=query(1,1,n,i,mid);

				if(c.first==c.second){
					//cout<<c.second<<endl;
					if(mx==-1){
						mx=mid;
					}else{
						mx=max(mx,mid);
					}
					l=mid+1;
				}else if(c.first>c.second){
					r=mid-1;
				}else if(c.first<c.second){
					l=mid+1;
				}
			}

			//cout<<i<<" "<<mi<<" "<<mx<<endl;


			net+=mx-mi+1;
		}
	}


	cout<<net<<endl;


	return 0;
}
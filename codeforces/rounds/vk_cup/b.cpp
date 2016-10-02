#include<iostream>

using namespace std;


int a[1000005];


int b[1000005];

int main(){
	int n,m;
	cin>>n>>m;
	int i,j;

	for(i=0;i<1000005;i++){
		a[i]=0;
	}
	int x,y,q;
	int flag=0;

	for(i=0;i<m;i++){
		cin>>x>>y;
		if(x<y){
			q=x;
			x=y;
			y=q;
		}

		if(flag==0){
			
				if(a[x]==2||a[y]==1){
					flag=1;
				}else{
					a[x]=1;
					a[y]=2;
				}
			
		}

	}
	if(m==0){
		n--;
		cout<<n<<endl;
		return 0;
	}
/*
	for(i=0;i<=n;i++){
		cout<<a[i]<<" ";

	}cout<<endl;*/

	if(flag==1){
		cout<<"0"<<endl;
	}else{
		int f=0;
		int mi1=-1,mx2=-1;
		for(i=1;i<=n;i++){
			if(a[i]==2){
				mx2=i;
			}
			if(f==0){
				if(a[i]==1){
					mi1=i;
					f=1;
				}
			}
		}
		if(mi1<=mx2){
			cout<<"0"<<endl;
		}else{
			int w=mi1-mx2;
			/*long long net=1;
			b[0]=1;

			for(i=0;i<w;i++){
				int carry=0;
				for(j=0;j<1000005;j++){
					if(b[j]==0){
						b[j]=carry;
						break;
					}
					
					b[j]=(2*b[j])+carry;
					

					carry=b[j]/10;
					//cout<<b[j]<<endl;
					//cout<<carry<<endl;
					if(b[j]>=10){
						b[j]-=10;
					}

					
				}				

				//net*=2LL;
			}

			//out<<b[0]<<" "<<b[1]<<endl;

			//cout<<net<<endl;
			for(i=0;i<1000005;i++){
				if(b[i]==0){
					break;
				}
			}
			for(j=i-1;j>=0;j--){
				cout<<b[j];
			}cout<<endl;*/
			cout<<w<<endl;
		}




	}

	return 0;
}
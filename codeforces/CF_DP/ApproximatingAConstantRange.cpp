#include<iostream>

using namespace std;

int a[100005];
int b[100005];

int main(){
	
	int n,i,j;

	cin>>n;


	for(i=0;i<n;i++){
		cin>>a[i];
	}
	

	b[0]=0;
	for(i=1;i<n;i++){
		if(a[i]-a[i-1]==0){
			b[i]=0;
		}
		if(a[i]-a[i-1]==1){
			b[i]=1;
		}
		if(a[i]-a[i-1]==-1){
			b[i]=2;
		}
		if(a[i]-a[i-1]>1||a[i]-a[i-1]<-1){
			b[i]=3;
		}
	}

	int net=1;

	for(i=0;i<n;i++){
		//cout<<i<<endl;

		int flag=0;
		int mf=0;
		int prev=i+1;
		for(j=i+1;j<n;j++){
			//cout<<j<<" qaz "<<b[j]<<" "<<flag<<endl;
			if(b[j]==0){
				//if(flag==0)
					//prev=j;
				continue;
			}

			if(b[j]==1){
				if(mf==2&&flag==0){
					//cout<<i<<" "<<j<<"  aaaa"<<endl;
					net=max(net,j-i);
					i=prev-1;
					break;
				}
				if(flag==0){
					if(mf==0)mf=1;

					flag=1;
					prev=j;
				}else if(flag==1){
					//cout<<i<<" "<<j<<"   1111"<<endl;
					net=max(net,j-i);
					i=prev-1;
					break;
				}else if(flag==2){
					flag=0;
				}


				continue;
			}

			if(b[j]==2){
				if(mf==1&&flag==0){
					//cout<<i<<" "<<j<<"  bbbb"<<endl;
					net=max(net,j-i);
					i=prev-1;
					break;
				}

				if(flag==0){
					if(mf==0)mf=2;
					flag=2;
					prev=j;
				}else if(flag==2){
					//cout<<i<<" "<<j<<" 22222"<<endl;
					net=max(net,j-i);
					i=prev-1;
					break;
				}else if(flag==1){
					//cout<<"feqadc"<<endl;
					flag=0;
				}
			}

			if(b[i]==3){
				//cout<<i<<" "<<j<<" 33333"<<endl;

				net=max(net,j-i);
				i=prev-1;
				break;
			}

		}

		if(j==n){
			//cout<<i<<" "<<j<<" last"<<endl;
			net=max(net,j-i);
			break;
		}


	}



	cout<<net<<endl;




	return 0;
}
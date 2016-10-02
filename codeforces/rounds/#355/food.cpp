#include<bits/stdc++.h>

using namespace std;


long long ab[1000005];
long long pre=0;
int n,h,k;


int bin(int l,int r,int i){
	//cout<<l<<" "<<r<<endl;
	if(l==r){
		return l;
	}

	int mid=(l+r)/2;


	if(pre+ab[i]-mid*(k)<=h){
		return bin(l,mid,i);
	}else{

		return bin(mid+1,r,i);
	}

}





int main(){
	


	scanf("%d%d%d",&n,&h,&k);

	int i;



	long long net=0;



	

	for(i=0;i<n;i++){
		scanf("%I64d",&ab[i]);
	}

	int r_=h/k;
	r_+=5;
	int l_=1;


	for(i=0;i<n;i++){

		//cout<<i<<" "<<pre<<" "<<net<<endl;

		//
			if(pre+ab[i]>h){
			    /*pre-=k;
				net++;
				if(pre<0)pre=0;

				i--;
				continue;
				*/
				int x=bin(l_,r_,i);

				net+=x;

				pre-=x*k;

				if(pre<0)pre=0;

				pre+=ab[i];


			}else{

				pre+=ab[i];

			}

	}


	if(pre>0){
		int y=pre/k;

		if(pre%k==0){
			net+=y;
		}else{
			net+=y+1;
		}

	}




	printf("%I64d\n",net);




	return 0;
}
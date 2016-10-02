#include<iostream>
#include<stack>
#include<algorithm>




using namespace std;

long long mod=1e9+7;

long long a[100005];
long long b[100005];
long long l[100005];
long long r[100005];
long long sum[100005];
long long l1[100005];
long long r1[100005];
long long sum1[100005];


int main(){
	long long n;
	long long i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=i;
	}

	for(i=1;i<=n;i++){
		cin>>b[i];
		b[i]+=i;
	}
	
	pair <long long,long long > temp;
	stack <pair<long long ,long long > > st;
	stack <pair<long long,long long > > stl;
	for(i=1;i<=n;i++){
		//current index i


		if(st.empty()==true){
			l[i]=i;
		}else{
			while(st.empty()==false){
				temp=st.top();
				//cout<<temp.first<<" $$ "<<endl;
				if(temp.first<a[i]){
					st.pop();
				}else{
					break;
				}
	
			}
			if(st.empty()==true){
				l[i]=i;
			}else{
				
				l[i]=i-temp.second;
			}
		}
		temp.first=a[i];
		temp.second=i;
		st.push(temp);
	} 
	
	for(i=n;i>=1;i--){
		//current index i
		if(stl.empty()==true){
			r[i]=n-i+1;
		}else{
			while(stl.empty()==false){
				temp=stl.top();
				//cout<<temp.first<<" $$ "<<endl;
				if(temp.first<a[i]){
					stl.pop();
				}else{
					break;
				}

			}
			if(stl.empty()==true){
				r[i]=n-i+1;
			}else{
				temp=stl.top();
				r[i]=temp.second-i;
			}
		}
		temp.first=a[i];
		temp.second=i;
		stl.push(temp);
	} 

/*	for(i=1;i<=n;i++){
	cout<<l[i]<<" "<<r[i]<<endl;
	}
*/
////////////////////////////////////////////////////////////////////	
	
	stack <pair<long long ,long long > > st1;
	stack <pair<long long,long long > > stl1;
	for(i=1;i<=n;i++){
		//current index i


		if(st1.empty()==true){
			l1[i]=i;
		}else{
			while(st1.empty()==false){
				temp=st1.top();
				//cout<<temp.first<<" $$ "<<endl;
				if(temp.first<b[i]){
					st1.pop();
				}else{
					break;
				}
	
			}
			if(st1.empty()==true){
				l1[i]=i;
			}else{
				
				l1[i]=i-temp.second;
			}
		}
		temp.first=b[i];
		temp.second=i;
		st1.push(temp);
	} 
	
	for(i=n;i>=1;i--){
		//current index i
		if(stl1.empty()==true){
			r1[i]=n-i+1;
		}else{
			while(stl1.empty()==false){
				temp=stl1.top();
				//cout<<temp.first<<" $$ "<<endl;
				if(temp.first<b[i]){
					stl1.pop();
				}else{
					break;
				}

			}
			if(stl1.empty()==true){
				r1[i]=n-i+1;
			}else{
				temp=stl.top();
				r1[i]=temp.second-i;
			}
		}
		temp.first=a[i];
		temp.second=i;
		stl.push(temp);
	} 
/////////////////////////////////////////////



	

	for(i=1;i<=n;i++){
		sum[i]=0;
	}	

	for(i=1;i<=n;i++){
		//cout<<"////////"<<i<<endl;
		for(j=1;j<=n;j++){
			if(l[i]+r[i]<j){
				break;
			}
			long long lef=i+1-j;
			long long righ=i+j-1;
			if(r[i]<j){
				righ=i+r[i]-1;
			}
			if(l[j]<j){
				lef=i+1-l[i];
				//if (i==2)cout<<"RDVZDFvz"<<endl;
			}
			if(righ>n){
				righ=n;
			}
			if(lef<1){
				lef=1;
			}

			//cout<<righ<<"$$ "<<lef<<endl;
			//cout<<righ-lef-j+2<<"dsAFsc"<<endl;
			//ans->
			
			righ=righ-lef+2-j;
			long long tp=righ*a[i];
			tp%=mod;
			sum[j]+=tp;
			sum[j]%=mod;

		}



	}


	for(i=1;i<=n;i++){
		cout<<sum[i]<<" ";
	}cout<<endl;
	

	/*for(i=1;i<=n;i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;*/
	///////////////////////////////////////////////////////////////////////////////////
	for(i=1;i<=n;i++){
		sum1[i]=0;
	}	

	for(i=1;i<=n;i++){
		//cout<<"////////"<<i<<endl;
		for(j=1;j<=n;j++){
			if(l1[i]+r1[i]<j){
				break;
			}
			long long lef1=i+1-j;
			long long righ1=i+j-1;
			if(r1[i]<j){
				righ1=i+r1[i]-1;
			}
			if(l1[j]<j){
				lef1=i+1-l1[i];
				//if (i==2)cout<<"RDVZDFvz"<<endl;
			}
			if(righ1>n){
				righ1=n;
			}
			if(lef1<1){
				lef1=1;
			}

			//ans->
			
			righ1=righ1-lef1+2-j;
			long long tp1=righ1*b[i];
			tp1%=mod;
			sum1[j]+=tp1;
			sum1[j]%=mod;

		}

	}

	for(i=1;i<=n;i++){
		cout<<sum1[i]<<" ";
	}cout<<endl;
	

	////////////////////////////////////////////////////////////////
	long long net=1;
	for(i=1;i<=n;i++){
		net=1;
		net*=sum[i];
		net%=mod;
		net*=sum1[i];
		net%=mod;
		cout<<net<<" ";




	}

	cout<<endl;





	return 0;
}
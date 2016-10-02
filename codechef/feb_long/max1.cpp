    #include<iostream>
    #include<stack>
    #include<algorithm>
    
    using namespace std;
     
    long long mod=1e9+7;
     
    long long a[100005], b[100005], l[100005],r[100005],sum[100005],l1[100005];
    long long r1[100005],sum1[100005],as[100005][3],bs[100005][3];
     
     
     
    int main(){
     
    	long long i,j,n,k;
    	cin>>n;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    		//a[i]+=i;
    	}
     
    	for(i=1;i<=n;i++){
    		//cin>>b[i];
    		//b[i]+=i;
            b[i]=0;
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
    				if(temp.first<=a[i]){
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
     
    	for(i=1;i<=n;i++){
    	cout<<l[i]<<" "<<r[i]<<endl;
    	}
    
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
    				
    				if(temp.first<=b[i]){
    					stl1.pop();
    				}else{
    					break;
    				}
     
    			}
    			if(stl1.empty()==true){
    				
    				r1[i]=n-i+1;
    			}else{
    				
    				temp=stl1.top();
    				r1[i]=temp.second-i;
    			}
    		}
    		temp.first=b[i];
    		temp.second=i;
    		stl1.push(temp);
    		
    	} 
    /////////////////////////////////////////////
    
     
    	for(i=0;i<=n+1;i++){
    		sum[i]=0;
    		sum1[i]=0;
    		as[i][0]=as[i][1]=as[i][2]=bs[i][0]=bs[i][1]=bs[i][2]=0;
     
    	}		
     
    	long long tr;
    	for(i=1;i<=n;i++){
    		
     
    		as[1][0]+=a[i];
    		as[1][0]%=mod;
    		if(l[i]>r[i]){
    			tr=l[i];
    			l[i]=r[i];
    			r[i]=tr;
    		}
     
    		as[l[i]][0]-=a[i];
    		as[l[i]][0]%=mod;
    		as[l[i]][1]+=(a[i]*l[i])%mod;
            as[l[i]][1]%=mod;
    		as[r[i]+1][1]-=(a[i]*l[i])%mod;
            as[r[i]+1][1]%=mod;
    		as[r[i]][2]-=a[i];
            as[r[i]][2]%=mod;
    		as[r[i]+l[i]-1][2]+=a[i];
            as[r[i]+l[i]-1][2]%=mod;
    	}
     
    	for(i=1;i<=n+1;i++){
    		as[i][0]+=as[i-1][0];
    		as[i][0]%=mod;
    	}
    	for(i=n;i>=0;i--){
    		as[i][2]+=as[i+1][2];
    		as[i][2]%=mod;
    	}
    	for(i=1;i<=n+1;i++){
    		as[i][1]+=as[i-1][1];
    		as[i][1]%=mod;
    		//cout<<as[i][1]<<"daaaaa  "<<endl;
    	}
    	
    	for(i=0;i<=n+1;i++){
    		as[l[i]][0]-=((l[i]-1)*a[i])%mod;
    		as[l[i]][0]%=mod;
    		as[r[i]][2]-=((l[i]-1)*a[i])%mod;
    		as[r[i]][2]%=mod;
    	}
    	for(i=1;i<=n+1;i++){
    		as[i][0]+=as[i-1][0];
    		as[i][0]%=mod;
    	}
    	for(i=n;i>=0;i--){
    		as[i][2]+=as[i+1][2];
    		as[i][2]%=mod;
    	}
     
    	for(i=1;i<=n;i++){
    		sum[i]+=as[i][0]+as[i][1]+as[i][2];
    		cout<<sum[i]<<"  ";
    	}cout<<endl;
    ///////////////////////////////////////////////////////////////////////
    	for(i=1;i<=n;i++){
    		
     
    		bs[1][0]+=b[i];
            bs[1][0]%=mod;
    		
    		if(l1[i]>r1[i]){
    			tr=l1[i];
    			l1[i]=r1[i];
    			r1[i]=tr;
    		}
     
    		bs[l1[i]][0]-=b[i];
    		bs[l1[i]][0]%-mod;
    		bs[l1[i]][1]+=(b[i]*l1[i])%mod;
    		bs[l1[i]][1]%=mod;
    		bs[r1[i]+1][1]-=(b[i]*l1[i])%mod;
            bs[r1[i]+1][1]%=mod;
     
    		bs[r1[i]][2]-=b[i];
            bs[r1[i]][2]%=mod;
    		bs[r1[i]+l1[i]-1][2]+=b[i];
            bs[r1[i]+l1[i]-1][2]%=mod;
    	}
     
    	for(i=1;i<=n+1;i++){
    		bs[i][0]+=bs[i-1][0];
    		bs[i][0]%=mod;
    	}
    	for(i=n;i>=0;i--){
    		bs[i][2]+=bs[i+1][2];
    		bs[i][2]%=mod;
    	}
    	for(i=1;i<=n+1;i++){
    		bs[i][1]+=bs[i-1][1];
    		bs[i][1]%=mod;
    		//cout<<as[i][1]<<"daaaaa  "<<endl;
    	}
    	
    	for(i=0;i<=n+1;i++){
    		bs[l1[i]][0]-=(l1[i]-1)*b[i];
    		bs[l1[i]][0]%=mod;
    		bs[r1[i]][2]-=(l1[i]-1)*b[i];
    		bs[r1[i]][2]%=mod;
    	}
    	for(i=1;i<=n+1;i++){
    		bs[i][0]+=bs[i-1][0];
    		bs[i][0]%=mod;
    	}
    	for(i=n;i>=0;i--){
    		bs[i][2]+=bs[i+1][2];
    		bs[i][2]%=mod;
    	}
     
    	for(i=1;i<=n;i++){
    		sum1[i]+=bs[i][0]+bs[i][1]+bs[i][2];
    		//cout<<sum1[i]<<"   ";
    	}//cout<<endl;
     
     
     
     
     
     
     
    /////////////////////////////////////////////////////////////////
     
     
     
     
    	long long net=1;
    	for(i=1;i<=n;i++){
    		net=1;
    		net*=sum[i];
    		net%=mod;
    		net*=sum1[i];
    		net%=mod;
    	//	cout<<net<<" ";
    	}
     
    	cout<<endl;
     
     
     
     
     
    	return 0;
    } 
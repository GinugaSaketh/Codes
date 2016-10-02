#include<iostream>

using namespace std;

int gcd(int a,int b){
	if(b==0){
		return a;
	}

	int x=a%b;
	a=b;
	b=x;
	return gcd(a,b);

}


int main(){
	
   int a,b;
   cin>>a>>b;

   long long n=a-b;

   if(n<0){
   	n=-n;
   }


   if(a<b){
   	int p=a;
   	a=b;
   	b=p;
   }
   long long x,a_,b_;

   long long t;

   long long i=1;

   long long j;
   
   long long net=1LL;
   long long mi=(long long)(1e18+5);


   while(i*i<=n)
    {
        if(n%i==0){

        	//cout<<i<<" ";
        	//cout<<d<<endl;
        	x=b/i;
        	x++;
        	b_=i*x;
       		a_=a+b_-b;
       		//cout<<a_<<" "<<a<<" "<<x<<endl;
        	x=gcd(a_,b_);    
        	t=a_*b_;
       		t/=x;

       		//cout<<t<<endl;

       		if(t<mi){
       			//cout<<t<<endl;
       			//cout<<a_<<" "<<a<<endl;
       			net=a_-a;
       			mi=t;

       		}else if(t==mi){
       			if(net>a_-a){
       				net=a_-a;
       			}
       		}
       		


       		i=n/i;
       		//cout<<i<<" ";

       		x=b/i;
        	x++;
        	b_=i*x;
       		a_=a+b_-b;
       		//cout<<a_<<" "<<a<<" "<<x<<endl;
        	x=gcd(a_,b_);    
        	t=a_*b_;
       		t/=x;

       		//cout<<t<<endl;

       		if(t<mi){
       			//cout<<t<<endl;
       			//cout<<a_<<" "<<a<<endl;
       			net=a_-a;
       			mi=t;

       		}else if(t==mi){
       			if(net>a_-a){
       				net=a_-a;
       			}
       		}
       		i=n/i;




       	}


        i++; 
    }

   
    cout<<net<<endl;







	return 0;
}
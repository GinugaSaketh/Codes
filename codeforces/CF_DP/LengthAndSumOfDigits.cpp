#include<iostream>

using namespace std;

int a[105];
int b[105];


int main(){
	int m,s;

	cin>>m>>s;

	int s1=s;

	int i,j;
	int k=0;

	if(s==0&&m==1){
		cout<<"0 0"<<endl;
		return 0;
    }

    if(s==0){
    	cout<<"-1 -1"<<endl;
    	return 0;
    }

    if(9*m<s){
    	cout<<"-1 -1"<<endl;
    	return 0;
    }


    int flag=0;


	for(i=0;i<m;i++){
		for(j=9;j>=0;j--){
			if(s1>=j){
				s1-=j;
				if(s1==0&&flag==0){
					k=i;
					flag=1;
				}
				a[i]=j;
				break;
			}
		}

	}

	//cout<<k<<endl;

	s1=s;


	for(i=0;i<m;i++){
		if(i==0){
			for(j=1;j<=9;j++){
				int r=s1-j;
				if(9*(m-i-1)>=r){
					b[i]=j;
					s1=r;
					break;
				}
			}

		}else{

		for(j=0;j<=9;j++){
			int r=s1-j;
			if(9*(m-i-1)>=r){
				b[i]=j;
				s1=r;
				break;
			}
		}		
		}



	}



	for(i=0;i<m;i++){
		cout<<b[i];
	}cout<<" ";

	for(i=0;i<m;i++){
		cout<<a[i];
	}cout<<endl;





	return 0;
}	
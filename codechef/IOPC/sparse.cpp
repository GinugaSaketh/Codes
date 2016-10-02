#include<iostream>

using namespace std;



int gcd(int a,int b){
	if(a<b){
		int tmp=a;
		a=b;
		b=tmp;

	}


	while(b>0){
		int tmp=a;
		a=b;
		b=tmp%b;

	}
	return a;


}

int st[200][9];
int t[9];



//array->a,len->n
void bld(){
	int p;

	for(p=0;p<8;p++){
		for(i=1;i<=n;i++){
			if(i+t[p]-1<=n){
				if(t[p]==1){
					st[i][0]=a[i];
				}else{
					st[i][p]=gcd(st[i][p-1],st[i+t[p-1]][p-1]);
				}
			}
		}
	}

}







int main(){
	int i;
	t[0]=1;
	for(i=1;i<9;i++){
		t[i]=2*t[i-1];
	}


	return 0;

}
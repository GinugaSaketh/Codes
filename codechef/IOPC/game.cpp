#include <iostream>

using namespace std;


int mat[16][16][5];



int main(){
	int k=5;int k1=10;
	int i,j;
	int l;
	for(j=0;j<16;j++){
		for(i=0;i<16;i++){
			if(i==0&&j==0){
				mat[i][j][0]=0;
				continue;
			}
			mat[i][j][0]=0;
			for(l=1;l<=4;l++){
				if(j-l<0)break;

				if(mat[i][j-l][0]==0){
					mat[i][j][0]=1;
					break;
				}

			}

			for(l=1;l<=4;l++){
				if(i-l<0)break;
				if(mat[i-l][j][0]==0){
					mat[i][j][0]=1;
					break;
				}
			}
		}
	}






	for(k=1;k<5;k++){
		for(j=0;j<16;j++){
			for(i=0;i<16;i++){
				mat[i][j][k]=0;
				for(l=1;l<=5;l++){
				if(j-l<0)break;

				if(mat[i][j-l][k]==0){
					mat[i][j][k]=1;
					break;
				}

			}

			for(l=1;l<=10;l++){
				if(i-l<0)break;
				if(mat[i-l][j][k]==0){
					mat[i][j][k]=1;
					break;
				}
			}
			for(l=1;l<=4;l++){
				if(k-l<0)break;
				if(mat[i][j][k-l]==0){
					mat[i][j][k]=1;
					break;
				}
			}

			}
		}
	}

for(k=0;k<5;k++){


	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cout<<mat[i][j][k]<<" ";
		}cout<<endl;
	}
	cout<<endl;
}
	return  0;
}
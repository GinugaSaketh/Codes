#include<iostream>

using namespace std;

int main(){
	int a[5]={1,5,10,15,20};
	int x=(lower_bound(a,a+1,10)-(a+1));
	cout<<x<<endl;
	return 0;
}
#include<iostream>
using namespace std;


int main(){

	int n,val;
	cin>>n;

	for(int i=1;i<=n;i++){
		val = (i&1);
		
		for(int j=1;j<=i;j++){
			cout<<val<<" ";
			val = 1 - val;
		}
		cout<<endl;
	}
	return 0;
}
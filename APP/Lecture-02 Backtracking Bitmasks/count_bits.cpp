#include<iostream>
using namespace std;

int countBits(int n){
	int ans = 0;
	for( ;n>0; n=n>>1){
		ans = ans + (n&1);
	}
	return ans;
}

int countBitsHack(int n){

	int ans=0;
	for( ;n>0; n = n&(n-1)){
		ans++;
	}
	return ans;
}
int countBitsHack2(int n){

	int ans = 0;
	while(n>0){
		ans++;

		int p = n & (-n);
		n = n - p;
	}
	return ans;
}

int main(){

	int n;
	cin>>n;
	cout<<countBitsHack2(n)<<endl;

	return 0;
}
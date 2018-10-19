#include<iostream>
using namespace std;


int main(){

	//Count the no of sets bits in n
	int n;
	int ans = 0;
	cin>>n;
	while(n>0){
		ans = ans +(n&1);
		n = n>>1;
	}
	cout<<ans;

return 0;
}
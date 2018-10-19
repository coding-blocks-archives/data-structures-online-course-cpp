#include<iostream>
using namespace std;

int fib(int n){
	
	if(n==0||n==1){
		return n;
	}	
	int f1 = fib(n-1);
	int f2 = fib(n-2);
	int ans = f1+f2;
	return ans;
}

int main(){
	cout<<fib(4)<<endl;
	return 0;
}
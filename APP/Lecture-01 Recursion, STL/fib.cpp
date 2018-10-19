#include<iostream>
using namespace std;
/*Three steps
1. Figure the base case
2. Assume the problem can be solved for f(k)
3. Using the assumption, write f(k+1) using reoccurence relation
*/
int fib(int n){
	if(n==0||n==1){
		return n;
	}
	return fib(n-1)+fib(n-2);
}

int main(){

	cout<<fib(4)<<endl;
	return 0;
}
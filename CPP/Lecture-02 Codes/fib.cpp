#include<iostream>
using namespace std;
//Print fibonacci numbers till n

int main(){
	int a = 0;
	int b = 1;
	int c = a + b;

	int n;
	cin>>n;

	cout<<a<<" "<<b<<" ";

	while(c<=n){
		cout<<c<<" ";

		a = b;
		b = c; 
		c = a + b;
	}




return 0;
}
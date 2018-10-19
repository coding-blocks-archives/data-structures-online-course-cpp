#include<iostream>
using namespace std;
//Print prime or not

int main(){
	
	int n;
	cin>>n;

	int i=2;
	while(i*i <= n){
		if(n%i==0){
			cout<<"Not Prime";
			return 0;
		}
		i = i + 1;
	}
	cout<<"Prime";
return 5;
}
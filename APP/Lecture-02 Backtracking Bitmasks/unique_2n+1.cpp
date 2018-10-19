#include<iostream>
using namespace std;


int main(){
	int a[] = {5,4,3,6,3,5,4};
	int n = sizeof(a)/sizeof(int);

	int ans = 0;
	for(int i=0;i<7;i++){
		ans = ans ^ a[i];
	}

	cout<<ans <<endl;



	return 0;
}
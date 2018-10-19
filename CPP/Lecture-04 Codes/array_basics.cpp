#include<iostream>
using namespace std;
	


int main(){

	int a[10];
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	//Simply Print Reverse
	for(int i=0;i<n;i++){
		cout<<a[n-i-1]<<endl;
	}

	return 0;
}
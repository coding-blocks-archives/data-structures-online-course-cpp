#include<iostream>
using namespace std;


int main(){

	int a;
	cin>>a;

	// Right Shift
	while(a>0){
		cout<<a<<endl;
		a = a>>1;
	}

	//Left Shift
	a = 3;
	while(a<50){
		cout<<a<<endl;
		a = a<<2;
	}

	return 0;
}
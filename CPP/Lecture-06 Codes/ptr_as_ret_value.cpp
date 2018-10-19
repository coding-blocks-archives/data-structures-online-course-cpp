#include<iostream>
using namespace std;

int *createArr(){

	int a[ ] = {1,2,3};
	cout<< a <<endl;
	for(int i=0;i<3;i++){
		cout<<a[i];
	}
	return a;
}

int main(){
	int *b = createArr();
	cout<<"In main";
	
	cout<<b <<endl;

	for(int i=0;i<3;i++){
		cout<<b[i];
	}

	return 0;
}
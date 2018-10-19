#include<iostream>
using namespace std;


int* createArr(){
	int *a = new int[10];
	a[0] = a[1] = a[2] = 5;
	
	for(int i=0;i<3;i++){
		cout<<a[i]<<" ";
	}
	cout<<"address of a"<<a<<endl;
	return a;
}

int main(){
	
	int *p = createArr();
	cout<<"Address of p is "<<p<<endl;

	for(int i=0;i<3;i++){
		cout<<p[i]<<" ";
	}

	return 0;
}
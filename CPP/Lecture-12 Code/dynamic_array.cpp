#include<iostream>
using namespace std;

int *createArray(){
	int *a = new int[10];
	for(int i=0;i<10;i++){
		a[i] = i;
	}
	return a;
}

int main(){
	int *b = createArray();
	
	for(int i=0;i<10;i++){
		cout<<b[i]<<" ";
	}
	delete [] b;


	return 0;
}
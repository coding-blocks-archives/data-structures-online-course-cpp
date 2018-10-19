#include<iostream>
using namespace std;


int main(){

	int n;
	n = 100;

	for(int i=0;i<n;i++){
		int *a = new int[i];
		cout<< a <<endl;
		delete [] a;
	}

	return 0;
}
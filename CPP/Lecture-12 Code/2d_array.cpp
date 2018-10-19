#include<iostream>
using namespace std;



int main(){

	
	int r,c;
	cin>>r>>c;

	//Dynamically Create a 2D Array
	int **a;
	a = new int*[r];

	for(int i=0;i<r;i++){
		a[i] = new int[c];
	}
	//cout<<a[i][j];


	//Delete
	for(int i=0;i<r;i++){
		delete [] a[i];
	}
	delete [] a;



	return 0;
}
#include<iostream>
using namespace std;


int main(){

	int x = 10;
	cout<< x <<endl;
	cout<< &x <<endl;

	//Suppose you want store the address of variable x
	//So you create a pointer variable.
	int * xptr;
	xptr = &x;
	cout<<xptr <<endl;

	/*
	int a[] = {1,2,3,4};
	//same output for all 3 statements
	cout<<a <<endl; // array name means the address of array
	cout<< &a <<endl; // same address of array
	cout<< &a[0] <<endl; // address of 0th cell is same as address of array
	*/a

}
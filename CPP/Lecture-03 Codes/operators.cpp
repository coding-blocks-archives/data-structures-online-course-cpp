#include<iostream>
using namespace std;


int main(){

	int a = 10;
	a = a + 1;

	cout<< a++ <<endl; //post increment
	cout<< a <<endl; 
	cout<< ++a <<endl ; // pre increment
	cout<< a <<endl;

	return 0;
}
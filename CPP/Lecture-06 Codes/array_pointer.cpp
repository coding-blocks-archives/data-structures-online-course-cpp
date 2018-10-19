#include<iostream>
using namespace std;


int main(){

	int a[5] = {1,2,3,4};
	cout<< a <<endl; //add
	cout<< &a <<endl;//add
	cout<< *a <<endl;//1

	cout<< *(a+2)<<endl; //3

	cout<< *(a+5)<<endl;

}
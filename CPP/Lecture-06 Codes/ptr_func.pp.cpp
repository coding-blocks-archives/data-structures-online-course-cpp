#include<iostream>
using namespace std;
//void fun(int *&p) - by reference
void fun(int *p){
	cout<< p <<endl;
	*p = 20;
	cout<< *p <<endl;

}

int main(){

	int x = 10;
	int *ptr = &x;
	cout<<x<<endl;

}
#include<iostream>
using namespace std;


void increment(int &z){
	z++;
}

int main(){
	int x = 10;
	int &y = x;

	y++;
	cout<< x <<endl;
	cout<< y <<endl;

	increment(y);
	cout<<x<<endl;
	cout<<y<<endl;

	return 0;
}
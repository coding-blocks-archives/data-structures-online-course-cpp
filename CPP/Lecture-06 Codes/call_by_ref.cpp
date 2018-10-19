#include<iostream>
using namespace std;

//Parameter is copy of x having name x but with a different scope
void increment(int &x){
	x = x + 10;
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void swap2(int &a, int &b){
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap3(int &a, int &b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
int main(){
	int x = 5;
	increment(x);
	cout<<x<<endl;
	int a,b;
	a = 10;
	b = 12;
	swap(a,b);
	cout<<a<<endl<<b<<endl;


}
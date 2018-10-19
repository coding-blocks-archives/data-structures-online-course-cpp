#include<iostream>
using namespace std;

void sayHi(){
	cout<<"Hi,everyone !";
	return;
}

int square(int no){
	return no*no;
}

void area(int l,int b){
	cout<<"Area of rect is "<<l*b<<endl;
}


int main(){
		
	sayHi(); //Function call
	cout<< square(5) <<endl;
	int a=5,b=3;
	area(a,b);

	return 0;
}
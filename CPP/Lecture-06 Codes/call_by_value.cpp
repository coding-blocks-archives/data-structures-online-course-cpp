#include<iostream>
using namespace std;

//Parameter is copy of x having name x but with a different scope
void increment(int x){
	x = x + 10;
	return;
}

int main(){
	int x = 5;
	increment(x);
	cout<<x<<endl;

}
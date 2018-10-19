#include<iostream>
using namespace std;

int power(int a,int b){
	if(b==0){
		return 1;
	}
	return a*power(a,b-1);
	
}
//Exponentiation - Log2(n)
int fastPower(int a,int b){
	if(b==0){
		return 1;
	}

	int smallAns = fastPower(a,b/2);
	smallAns *= smallAns;

	if(b&1){
		return a*smallAns;
	}
	return smallAns;

}

int main(){
	cout<<fastPower(3,5)<<endl;
	return 0;
}
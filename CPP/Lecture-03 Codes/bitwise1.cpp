#include<iostream>
using namespace std;


int main(){

	int n;
	cin>>n;

	//Ternary Operator ? :
	 //n>0? cout<<"Postive" : cout<<"Negative";

	cout<<(n&1)<<endl;
	(n&1)?cout<<"Odd":cout<<"Even";


	return 0;
}
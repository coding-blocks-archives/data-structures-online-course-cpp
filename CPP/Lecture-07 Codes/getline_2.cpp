#include<iostream>
using namespace std;


int main(){
	//Read one integer and one sentence
	int a;
	char b[100];

	cin>>a;
	cin.get();
	//cin.ignore();
	//cin.getline(array,size,delim)
	cin.getline(b,100,'.');


	cout<<a <<endl;
	cout<<b<<endl;



}
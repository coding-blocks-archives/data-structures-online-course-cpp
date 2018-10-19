#include<iostream>
using namespace std;


int main(){

	//It might or might not contain garbage, so it better to terminate our list with null
	char a[][8] = {{'a','b','c','e','\0'},{'d','e','f','h',
'\0'}};

	//cout<<a[0][0]<<endl;
	cout<<a[0]<<endl;
	cout<<a[1]<<endl;

	//Another Way to create a list of string is 
	char words[10][100] = {
		"Apple",
		"Mango",
		"Banana Shake"
	};

	cout<<words[0]<<endl;
	cout<<words[1] <<endl;
	cout<<words[2]<<endl;

	//Take Input the third row
	cin.getline(words[3],100);
	cout<<words[3]<<endl;


	return 0;
}
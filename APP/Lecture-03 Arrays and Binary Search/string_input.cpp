#include<iostream>
using namespace std;


int main(){
	int n;
	char arr[100];

	cin>>n;
	char ch = cin.get(); // Reads a single character including space and \n
	cin.getline(arr,100); // doenst work for string class

	cout<<n;
	cout<<arr<<endl;

	string s;
	cin>>s;
	cout<<s<<endl;

	cin.get();
	string line;
	getline(cin,line); //reads a line as string

	cout<<line<<endl;



}
#include<iostream>
#include<cstring>
using namespace std;

int main(){

	char str[100];
	//cin>>str;
	cin.getline(str,100,'.');


	cout<<str<<endl;

	char str2[] = "Hello";
	cout<<sizeof(str2)<<endl;

	cout<<sizeof(str)<<endl;

	char stringlist[100][10] = {"Hello","World","Coding","Blocks"};
	string s[] = {"Hello","World","Coding","Blocks"};
	//sort(s,s+4);


	return 0;
}
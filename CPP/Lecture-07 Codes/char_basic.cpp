#include<iostream>
using namespace std;

int main(){
	char a[] = {'a','b','\0'};
	cout<<a<<endl;

	char b[] = "Hello World";
	cout<<b <<endl;

	//Input 
	char word[100];
	cin>>word;
	cout<<word<<endl;

	//Sentence Read
	cin.getline(word,100);
	cout<<word<<endl;




return 0;	
}
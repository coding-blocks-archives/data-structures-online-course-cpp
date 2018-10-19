#include<iostream>
using namespace std;



int main(){

	char ch;
	cin>>ch;

	switch(ch){
		case 'n':
		case 'N': cout<<"North";
					break;

		case 'w':
		case 'W': cout<<"West";
					break;
		
		case 'S': cout<<"South";
					break;

		case 'E': cout<<"East";
					break;

		default:  cout<<"invalid";
					break;
	}

	return 0;
}
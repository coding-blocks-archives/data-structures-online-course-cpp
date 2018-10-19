#include<iostream>
#define PI 3.14
///Macros are just shortcuts, they are not directly compiled
#define PRINT cout<<
#define COLON ;
using namespace std;


int main(){

	int a = 10;
	PRINT "Value of a";

	const int area_of_house = 2500;
	//area_of_house = area_of_house + 20;


	cout<< sizeof(a) <<endl;

	cout<< sizeof(char) <<endl;

	long long int x;

	cout<< sizeof(x);

	char ch = 'a';
	//string s = "hello";

	cout<<"Value of pi is"<<PI<<endl;

	return 0;
}
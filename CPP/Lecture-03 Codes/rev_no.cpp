#include<iostream>
using namespace std;



int main(){
	int no;
	cin>>no;

	for( ;no>0;no=no/10){
		cout<<no%10;
	}

	return 0;
}
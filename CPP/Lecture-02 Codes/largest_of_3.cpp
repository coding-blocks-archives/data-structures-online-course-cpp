#include<iostream>
using namespace std;

/*To find largest 
of 3 numbers*/

int main(){

	int a,b,c;
	cout<<"Enter 3 numbers :";
	cin>>a >> b >> c;

	if(a>b && a>c){
		cout<<a<<" is greatest";
	}
	else if(b>a && b>c){
		cout<<b<<" is greatest";
	}
	else{
		cout<<c<<" is greatest";
	}


return 0;
}

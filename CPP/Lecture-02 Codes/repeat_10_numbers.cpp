#include<iostream>
using namespace std;

//Even nos from 2 to N.

int main(){
	int n;
	cin>>n;

	int i = 2; //Init Condition
	while(i<=n){ //Termination Cond
		 cout<< i <<",";
		 i = i + 2;
	}

return 0;
}
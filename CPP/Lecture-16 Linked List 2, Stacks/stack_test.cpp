#include<iostream>
#include<iostream>
#include "stack.h"
using namespace std;

int main(){

	Stack<int> s;
	for(int i=1;i<=5;i++){
		s.push(i);
	}	

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}



}
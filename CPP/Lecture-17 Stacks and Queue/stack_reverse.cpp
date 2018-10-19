#include<iostream>
#include<stack>
using namespace std;

void pushBottom(stack<int> &s,int topElement){
	if(s.empty()){
		s.push(topElement);
		return ;
	}
	//EK element nikalo
	int data =s.top();
	s.pop();
	pushBottom(s,topElement);
	s.push(data);
}

void reverseStack(stack<int> &s){
	//Base Case
	if(s.empty()){
		return;
	}
	//Otherwise !
	int topElement = s.top();
	s.pop();
	reverseStack(s);
	pushBottom(s,topElement);
}

int main(){


	stack<int> s;
	for(int i=1;i<=5;i++){
		s.push(i);
	}
	//rev 
	reverseStack(s); 	

	//Print 
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}
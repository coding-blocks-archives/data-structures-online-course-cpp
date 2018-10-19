#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(stack<int> s){
		
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	cout<<endl;
}
void pushToBottom(stack<int> &s,int top){
		//Base case
			if(s.empty()){
				s.push(top);
				return;
			}
		//Rec Case
			int data = s.top();
			s.pop();
			pushToBottom(s,top);
			s.push(data);
}
void reverseStack(stack<int> &s){
	//base case
	if(s.empty()){
		return;
	}
	int top = s.top();
	s.pop();
	reverseStack(s);
	pushToBottom(s,top);
}

int main(){

	stack<int> s;
	
	for(int i=1;i<=5;i++){
		s.push(i);
	}
	//While the stack is not empty
	print(s);

	reverseStack(s);

	print(s);

	return 0;
}
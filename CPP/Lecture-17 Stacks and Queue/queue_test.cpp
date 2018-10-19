#include<iostream>
#include "queue.h"
using namespace std;



int main(){
	Queue q(20);

	for(int i=1;i<=8;i++){
		q.push(i);
	}
	q.pop();
	q.push(10);
	q.push(11);

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}
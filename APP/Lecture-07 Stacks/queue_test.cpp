#include<iostream>
#include "queue.h"
using namespace std;



int main(){

	Queue q;

	for(int i=1;i<=10;i++){
		q.push(i);
	}
	q.pop();
	q.pop();
	q.push(20);

	while(!q.isEmpty()){
		cout<<q.getFront();
		q.pop();
	}

return 0;
}
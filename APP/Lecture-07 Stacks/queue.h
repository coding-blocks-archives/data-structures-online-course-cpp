#ifndef QUEUE_H
#define QUEUE_H

class Queue{
	int front;
	int rear;
	int cs;
	int ms;
	int *a;

public:
	Queue(int ds=5){
		front = 0;
		cs = 0;
		ms  = ds;
		rear = ms - 1;
		a = new int[ms];
	}
	void push(const int data){
		if(cs<ms){
			rear = (rear+1)%ms;
			a[rear] = data;
			cs++;
		}
	}
	bool isEmpty() const{
		return cs == 0;
	}
	void pop(){
		if(!isEmpty()){
			front = (front+1)%ms;
			cs--;
		}
	}
	int getFront() const{
		return a[front];
	}

};

#endif
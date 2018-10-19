#include<iostream>
#include "heap.h"
using namespace std;


int main(){

	MinHeap h;

	h.push(5);
	h.push(7);
	h.push(8);
	h.push(9);
	h.push(2);
	h.push(1);
	h.push(3);

	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
	
}
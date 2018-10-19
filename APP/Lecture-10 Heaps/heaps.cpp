#include<iostream>
#include "heap.h"
using namespace std;


int main(){
	Heap h(false);

	int d;
	cin>>d;
	while(d!=-1){
		h.push(d);
		cin>>d;
	}

	//Pop
	while(!h.empty()){
		cout<<h.top()<<",";
		h.pop();
	}

	return 0;
}
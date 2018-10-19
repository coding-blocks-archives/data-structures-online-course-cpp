#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

class MeraComparator{

public:
	bool operator()(int a,int b){
		//cout<<"Comparing "<<a<<" and "<<b<<endl;
		return a>b;
	}

};


int main(){

	//MaxHeap
	priority_queue<int> hMax;

	//MinHeap
	priority_queue<int,vector<int>,greater<int> > hMin;

	//MeraHeap
	priority_queue<int,vector<int>, MeraComparator> h;

	//MeraComparator cmp;
	//cmp("Dog","Cat"); // Functional Object / Functor
	

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


	return 0;
}
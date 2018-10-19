#ifndef HEAP_H
#define HEAP_H

#include<vector>
using namespace std;

class Heap{

	bool minHeap;
	vector<int> v;
	bool compare(int a,int b){
		if(minHeap){
			return a>b?true:false;
		}
		else{
			return a>b?false:true;
		}
	}
	void heapify(int i){

		int left = 2*i;
		int right = 2*i + 1;

		int minIdx = i;
		if(left<v.size() && compare(v[i],v[left])){
			minIdx = left;
		}
		if(right<v.size() && compare(v[minIdx],v[right])){
			minIdx = right;
		}

		if(minIdx!=i){
			swap(v[i],v[minIdx]);
			heapify(minIdx);
		}
	}

public:
	Heap(bool b=true,int size=100){
		minHeap = b;
		v.push_back(-1);
		v.reserve(size);
	}

	void push(int data){
		v.push_back(data);
		int index = v.size() -1;
		while(index>1){
			int parent = index/2;
			
			if(compare(v[parent],v[index])){
				swap(v[parent],v[index]);
				index = parent;
			}
			else{
				break;
			}
		}

	}
	bool empty(){
		return v.size()==1;
	}
	
	int top() const{
		return v[1];
	}

	void pop(){

		int last = v.size() - 1;
		swap(v[last],v[1]);
		v.pop_back();

		//Heapify
		heapify(1);

	}



};





#endif 



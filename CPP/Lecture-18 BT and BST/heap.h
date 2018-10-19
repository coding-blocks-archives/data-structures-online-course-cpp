#include<iostream>
#include<vector>
using namespace std;


class MinHeap{
	vector<int> v;

	void heapify(int index){

		int left = 2*index;
		int right = left + 1;

		int min_index = index;

		if(left<v.size() && v[min_index]>v[left]){
				min_index = left;
		}
		if(right<v.size() && v[min_index]>v[right]){
		  		min_index = right;
		}
		if(index!=min_index){
			swap(v[index],v[min_index]);
			heapify(min_index);
		}
	}
public:
	
	MinHeap(){
		v.push_back(-1);	
	}
	void push(int data){
		v.push_back(data);

		int index = v.size() - 1;
		int parent = index/2;

		while(index > 1 && v[index]<v[parent] ){
			swap(v[index],v[parent]);
			index = parent;
			parent = parent/2;
		}
	}
	int top(){
		return v[1];
	}
	void pop(){
		int last = v.size() - 1;
		swap(v[1],v[last]);
		v.pop_back();
		heapify(1);
	}
	bool empty(){
		return v.size()==1;
	}
};
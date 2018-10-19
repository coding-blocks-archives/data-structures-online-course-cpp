#ifndef MYSTACK_H
#define MYSTACK_H

#include<vector>
using namespace std;

template<typename T>
class Stack{
	vector<T> v;
	T x;
public:
	void push(const T data){
		v.push_back(data);
	}
	void fun(const T d1){
		//x = d1;
	}
	void pop(){
		v.pop_back();
	}
	T top() const{
		int n = v.size();
		return v[n-1];
	}
	bool isEmpty() const{
		return v.size()==0;
	}
};

#endif
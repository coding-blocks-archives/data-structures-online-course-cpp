#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector{
	int cs;
	int ms;
	T *arr;

public:
	Vector(int ds=2){
		cs = 0;
		ms =ds;
		arr = new T[ms];
	}

	void push_back(T data){
		if(cs==ms){
			T *oldArr = arr;
			arr = new T[2*ms];
			ms = 2*ms;

			for(int i=0;i<cs;i++){
				arr[i]  = oldArr[i];
			}
			delete [] oldArr;
		}

		arr[cs] = data;
		cs++;
	}
	void pop_back(){
		if(cs>0){
			cs--;
		}	
	}
	int capacity(){
		return ms;
	}
	int size(){
		return cs;
	}
	//v[i]
	T operator[](int i){
		return arr[i];
	}
};

#endif
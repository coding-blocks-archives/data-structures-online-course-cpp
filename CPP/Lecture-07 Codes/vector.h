#include<iostream>
#include<cstring>
using namespace std;

class Vector{
	int *a;
	int cs;
	int ms;
public:
	Vector(int ds=4){
		cs = 0;
		ms = ds;
		a = new int[ms];
	}
	//Deep Copy Constructor
	Vector(Vector &v){
		a =  new int[v.ms];
		cs = 0;
		ms = v.ms;

		for(int i=0;i<v.cs;i++){
			push_back(v[i]);
		}


	}
	void push_back(int d){
		if(cs==ms){

			int *olda = a;

			a = new int[2*ms];
			ms = 2*ms;

			//Copy old elements
			for(int i=0;i<cs;i++){
				a[i] = olda[i];
			}
			delete [] olda;
		}

		a[cs] = d;
		cs++;
	}

	void pop_back(){
		if(cs>0){
			cs--;
		}
	}
	bool isEmpty(){
		return cs==0?true:false;
	}
	int front(){
		if(cs>0){
			return a[0];
		}
	}
	int back(){
		if(cs>0){
			return a[cs-1];
		}
	}
	int at(int i){
		return a[i];
	}
	int size(){
		return cs;
	}
	int getMaxSize(){
		return ms;
	}
	void operator[](string s){	
		cout<<"Hi "<<s<<endl;
	}
	//Return by reference
	int& operator[](int i){
		return a[i];
	}
	~Vector(){
		 cout<<"Destroying Vector";
		if(a!=NULL){
			delete [] a;
			a = NULL;
		}
	}

};


ostream& operator<<(ostream &os,Vector &v){

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<",";
	}
	cout<<endl;
	return os;
}

istream& operator>>(istream&is,Vector &v){

	int d;
	cin>>d;
	while(d!=-1){
		v.push_back(d);
		cin>>d;
	}
	return is;

}
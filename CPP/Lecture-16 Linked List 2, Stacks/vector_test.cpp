#include<iostream>
#include "vector.h"
#include "vector.h"
using namespace std;


int main(){

	

	Vector<char> a;

	for(int i=1;i<=5;i++){
		a.push_back(65+i);
	}
	a.pop_back();

	cout<<a.capacity()<<endl;

	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}

}
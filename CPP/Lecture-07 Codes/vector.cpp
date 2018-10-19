#include<iostream>
#include "vector.h"
using namespace std;


int main(){

	Vector v;

	for(int i=1;i<=5;i++){
		v.push_back(i*i);
	}

	for(int i=0;i<v.size();i++){
		//cout<<v.at(i)<<",";
		cout<< v[i] <<endl;
	}
	cout<<endl;
	cout<<v.getMaxSize()<<" is maxsize ";

	v["Coding Blocks"];

	Vector v2(v);
	//lets update v2
	for(int i=0;i<v2.size();i++){
		v2[i] = 2;
	}

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<","<<v2[i]<<endl;
	}

	//Print the Vectors
	cout<<"Printing ";
	cout<<v<<v2;

	Vector v3,v4;
	cin>>v3>>v4;
	cout<<v3<<v4;

	//Vector *dv = new Vector;

}



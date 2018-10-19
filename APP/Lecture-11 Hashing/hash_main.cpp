#include<iostream>
#include "hash_table.h"
using namespace std;


int main(){

	Hashtable<int> h(7);

	h.insert("Mango",100);
	h.insert("Banana",180);
	h.insert("Kiwi",120);
	h.insert("Guava",130);
	h.insert("Guava2",130);

	h["Pineapple"] = 102;
	h["Pineapple"] = 104;



	h.print();
	cout<<"Enter a fruit to search";
	string f;
	cin>>f;

	cout<<"Price of fruit is"<<h[f]<<endl;

	/*
	int *price = h.search(f);
	if(price!=NULL){
		cout<<"Price is "<<*price<<endl;
	}
	else{
		cout<<f<<" doesn't exist!"<<endl;
	}
	*/


}
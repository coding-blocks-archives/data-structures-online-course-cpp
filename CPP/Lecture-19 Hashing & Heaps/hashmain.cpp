#include<iostream>
#include "hashtable.h"
using namespace std;



int main(){

	hashtable<int> h(17);

	h.insert("Mango",199);
	h.insert("Guava",129);
	h.insert("Litchi",109);
	h.insert("Tarbooj",19);
	h.insert("Kiwi",149);

	h["pineapple"] = 80; //Insertion
	h["pineapple"] = 70; //Updation
	cout<<h["pineapple"]; //Search

	h.print();

	string fruit;
	cin>>fruit;
	int *price = h.search(fruit);
	if(price!=NULL){
		cout<<"Fruit costs "<<*price<<endl;
	}
	else{
		cout<<"Fruit not found"<<endl;
	}
	return 0;
}
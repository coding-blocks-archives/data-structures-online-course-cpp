#include<iostream>
#include<unordered_map>
using namespace std;

/*
class Fruit{

	price;
	color;
	sweetness;
	state;
	id;
	vendor;
}
*/

int main(){

	unordered_map<string,int> h;

	//unordered_map<string,Fruit> h2;
	

	//Insertion
	h["Mango"]  = 100;
	//Updation
	h["Mango"] = 80;
	//Print the value if  Mango Exists
 	if(h.count("Mango")!=0){
			cout<<h["Mango"]<<endl;
	}

	//Another Way to insert
	h.insert(make_pair("Kiwi",170));

	//Searching for a given fruit
	string f;
	cin>>f;
	if(h.count(f)){
		cout<<"Fruit costs"<<h[f]<<endl;
	}
	else{
		cout<<"Fruit doesn't exist";
	}
	//Deleting a Fruit(key)
	h.erase("Mango")

	//Print all the elements
	for(auto p:h){
		cout<<p.first<<" and "<<p.second<<endl;
	}

	return 0;
}
#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;



int main(){

	unordered_map<string,int> h;

	h.insert(make_pair("Mango",100));
	h["Banana"] = 90;

	h["Apple"] = 120;
	h.erase("Apple");

	pair<string,int> p;
	p.first = "Guava";
	p.second = 90;

	h.insert(p);

	//Count fn returns 0 or 1
	if(h.count("Guava")){
		cout<<h["Guava"]; //Price of guava
	}

	auto f = h.find("Mosami");
	if(f==h.end()){
		cout<<"Mosami doesn't exist"<<endl;;

	}
	else{
		cout<<f->first<<endl;
		cout<<f->second<<endl;
	}

	//cout<<"Load Factor "<<h.max_load_factor()<<endl;
	//For Each Loop
	for(auto fruit:h){
		cout<<fruit.first<<endl;
		cout<<fruit.second<<endl;
		cout<<endl;
	}




}


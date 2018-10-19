#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node<T> * next;

	node(string k, T val){
		key = k;
		this->value = val;
		next = NULL;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class Hashtable{

	node<T>** buckets;
	int ts;
	int cs;

	int hashFn(string key){

		int ans = 0;
		int L = key.length();
		int p = 1;

		for(int i=0;i<L;i++){
			ans += key[L-i-1]*p;
			p = p*37;
			p %= ts;
			ans %= ts;
		}
		return ans;
	}
	void rehash(){
		node<T>**oldBuckets = buckets;
		int oldTs = ts;
		ts = 2*ts;
		cs = 0;
		buckets = new node<T>*[ts];
		for(int i=0;i<ts;i++){
			buckets[i] = NULL;
		}

		for(int i=0;i<oldTs;i++){
			node<T>*temp = oldBuckets[i];
			if(temp!=NULL){
				while(temp!=NULL){
					insert(temp->key,temp->value);
					temp = temp->next;
				}
				delete oldBuckets[i];
			}
		}
		delete [] oldBuckets;
	}

public:
	Hashtable(int ds=7){
		ts = ds;
		cs = 0;
		buckets = new node<T>*[ts];

		for(int i=0;i<ts;i++){
			buckets[i] = NULL;
		}
	}

	void insert(string key,T value){
		int i = hashFn(key);

		node<T>* n = new node<T>(key,value);

		n->next = buckets[i];
		buckets[i] = n;
		cs++;

		float lf = cs/(1.0*ts);

		if(lf>0.7){
			//cout<<"Load factor is"<<lf<<endl;
			rehash();
		}	
	}
	T* search(string key){

		int i = hashFn(key);
		node<T> *temp   = buckets[i];
		while(temp!=NULL){
			if(temp->key == key){
				return &(temp->value);
			}
			temp = temp->next;
		}
		return NULL;
	}
	void erase(string key){
		int i = hashFn(key);
		//Linked List pe iterate remove node
		// HW


	}
	T& operator[](string key){
		T* temp = search(key);
		if(temp==NULL){
			T x;
			insert(key,x);
		}
		temp = search(key);
		return (*temp);
	}
	void print(){

		for(int i=0;i<ts;i++){
			node<T> *temp = buckets[i];
			cout<<"Bucket "<<i<<"->";
			while(temp!=NULL){
				cout<<temp->key<<",";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
};
#endif
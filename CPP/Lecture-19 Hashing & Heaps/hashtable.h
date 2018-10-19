#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node<T>*next;

	node(string k,T val){
		key = k;
		value = val;
		next = NULL;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class hashtable{
	
	int cs;
	int ts;
	node<T>** buckets;

	int hashFn(string key){

		int ans = 0;
		int p = 1;

		for(int i=0;i<key.size();i++){
			ans += key[i]*p;
			p = p*37;

			p %= ts;
			ans %= ts;

		}
		return ans;
	}
	void rehash(){
		node<T>** oldBuckets = buckets;
		int oldTs = ts;
		ts = ts*2; //Next Prime
		cs = 0;

		buckets = new node<T>*[ts];
		for(int i=0;i<ts;i++){
			buckets[i] = NULL;
		}

		//Iterate over old table, insert into new table
		for(int i=0;i<oldTs;i++){
			node<T>*temp = oldBuckets[i];

			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			if(oldBuckets[i]!=NULL){
				delete oldBuckets[i];
			}
		}
		delete [] oldBuckets;
	}
public:
	hashtable(int ds=7){
		cs = 0;
		ts = ds;
		buckets = new node<T>*[ts];

		for(int i=0;i<ts;i++){
			buckets[i] = NULL;
		}
	}

	void insert(string key, T value){
		int i = hashFn(key);

		node<T>* n = new node<T>(key,value);
		n->next = buckets[i];
		buckets[i] = n; 

		cs++;
		float lf = cs/(ts*1.0);
		
		if(lf>0.7){
			rehash();
		}
	}

	T* search(string key){

		int i = hashFn(key);
		node<T>*temp  = buckets[i];

		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value);
			}
			temp  = temp->next;
		}
		return NULL;
	}
	void erase(string key){
		//Deletion from LL , ith LL, where i the hashFn(key)
	}

	void print(){

		for(int i=0;i<ts;i++){
			cout<<"Bucket "<<i<<"->";

			node<T>*temp = buckets[i];
			while(temp!=NULL){
				cout<<temp->key<<"->";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	T& operator[](string key){
		//Insertion
		T* temp = search(key);
		if(temp==NULL){
			T garbage;
			insert(key,garbage);

			temp = search(key);
			return (*temp);
		}
		else{
			return (*temp);
		}
	}

};



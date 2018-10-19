#include<iostream>
#include<unordered_map>

using namespace std;

#define hashmap unordered_map<char,node*> 

class node{
public:
	char data;
	bool isTerminal;
	 hashmap m;

	public:
		node(char d){
			data = d;
			isTerminal = false;
		}
};


class trie{
	node*root;

public:
	trie(){
		root = new node('\0');
	}
	void addWord(char *word){

		node*temp = root;

		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			
			if(temp->m.count(ch)==0){
				node*child = new node(ch);
				temp->m[ch] = child;
				temp = child;
			}
			else{
				temp = temp->m[ch];
			}
		}
		temp->isTerminal = true;

	}
	bool search(char *word){
		node*temp = root;
		
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->m.count(ch)==0){
				return false;
			}
			else{
				temp = temp->m[ch];
			}
		}
		return temp->isTerminal;
	}

};


int main(){

	char ws[100][10] = {
		"apple","ape","code","coder","coding"
	};

	trie t;
	for(int i=0;i<5;i++){
		t.addWord(ws[i]);
	}
	char key[10];
	cin>>key;

	if(t.search(key)){
		cout<<key<<" found in trie";
	}
	else{
		cout<<"Not Found!";
	}

return 0;
}
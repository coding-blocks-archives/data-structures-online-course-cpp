#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

void printHeap(priority_queue<int,vector<int>,greater<int> > h){

	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}

}


int main(){

	priority_queue<int,vector<int>,greater<int> > h;

	int k=3;
	int cs = 0;

	while(1){
		int no;
		cin>>no;

		//Query
		if(no==-1){
			printHeap(h);
		}
		else{
			if(cs<k){
				h.push(no);
				cs++;
			}
			else if(cs==k){
				if(no>h.top()){
					h.pop();
					h.push(no);
				}
			}

		}
	}


	return 0;
}
#include<iostream>
#include<queue>
using namespace std;


int main(){

	//Min K elements from a running stream
	int k  = 4;
	int hs = k;

	priority_queue<int> h;

	int d;
	cin>>d;

	int cs = 0;
	while(d!=-1){
		if(cs<hs){
			h.push(d);
			cs++;
		}
		else{
			if(d < h.top()){
				h.pop();
				h.push(d);
			}
		}
		cin>>d;
	}

	//Pop
	while(!h.empty()){
		cout<<h.top()<<",";
		h.pop();
	}

	return 0;
}
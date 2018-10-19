#include<iostream>
#include<queue>
using namespace std;

class Compare{
	public:
		bool operator()(int a,int b){
			//ṭcout<<"Comparing "<<a<<" and "<<b<<endl;
			return a>b;
		}
};


int main(){

	priority_queue<int> hMax; //Max Heap
	priority_queue<int, vector<int> ,Compare > h; //Min Heap



	int d;
	cin>>d;
	while(d!=-1){
		h.push(d);
		cin>>d;
	}

	//Pop
	while(!h.empty()){
		cout<<h.top()<<",";
		h.pop();
	}

	//ṭCompare C;
	//C(5,3);



	return 0;
}
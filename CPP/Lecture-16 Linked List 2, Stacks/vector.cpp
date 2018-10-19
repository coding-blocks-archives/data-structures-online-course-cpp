#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(string a,string b){
	return a>b;
}

void update(vector<int> &v){

	//v[i] +=1;	
}

void print(vector<int> v){

	//v[i] +=1;	
}

int main(){

	vector<int> arr;

	for(int i=1;i<=5;i++){
		arr.push_back(100-i*i);
	}
	arr.pop_back();

	//Sort
	sort(arr.begin(),arr.end());

	//Print
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}

	string s[] = {"apple","kiwi","banana","mango","papaya"};
	vector<string> vs;

	for(int i=0;i<5;i++){
		vs.push_back(s[i]);
	}
	sort(vs.begin(),vs.end(),comp);

	cout<<"Max size"<<vs.capacity()<<endl;
	for(int i=0;i<vs.size();i++){
		cout<<vs[i]<<" ";
	}



}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	cout<<"Comparing "<<a<<"and "<<b<<endl;
	return a>b;
}

int main(){

	vector<int> v;

	for(int i=5;i<=10;i++){
		v.push_back(i*i);
	}
	v.push_back(10);

	// function as a argument
	sort(v.begin(),v.end(),cmp);

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<",";
	}
	
return 0;
}
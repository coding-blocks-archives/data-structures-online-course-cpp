#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


bool compare(string s1,string s2){

	return s1>s2;
}

int main(){
	
	string s0 = "Hello World";
	cout<<s0 <<endl;

	//Input
	
	//Create an array of strings
	string s[10] = {"banana","apple","mango","papaya","orange"};
	sort(s,s+5,compare);

	int n = 5;

	for(int i=0;i<5;i++){
		cout<<s[i]<<" ";
	} 

	cout<<"Enter the fruit to search"<<endl;
	string s2;
	getline(cin,s2); //This is lil different cin.getline(array,size), takes input a sentence in a string
	


	//Implement Linear Search
	int i;
	for(i=0;i<n;i++){
		//cout<<"Comparing "<<s2<<"and "<<s[i]<<endl;
		if(s2==s[i]){ //You can directly compare two strings
			cout<<"Found at index "<<i<<endl;
			break;
		}
	}
	if(i==n){
		cout<<"Not found!"<<endl;
	}





	return 0;
}
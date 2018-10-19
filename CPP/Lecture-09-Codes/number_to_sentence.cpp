#include<iostream>
#include<cstring>
using namespace std;


string words[] = {
	"zero","one","two","three","four","five",
	"six","seven","eight","nine"
};

void numberToString(int n){
	if(n==0){
		return;
	}
	//Rec Case
	numberToString(n/10);
	cout<<words[n%10]<<" ";
}

int main(){
	int n = 204889;
	numberToString(n);


	return 0;
}
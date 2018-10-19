#include<iostream>
using namespace std;

void filter(int n,char *input){

	int k=0;
	while(n>0){
		if(n&1){
			cout<<input[k];
		}
		k++;	
		n = n>>1;
	}
	cout<<endl;
}


int main(){

	char input[] ="abc";
	int len = 3;

	for(int i=0;i<(1<<len);i++){
		filter(i,input);
	}


	return 0;
}
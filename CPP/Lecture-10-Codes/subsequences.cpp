#include<iostream>
using namespace std;

void printSubsequence(char *in,char *out,int i,int j){
	if(in[i]=='\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	//Two case
	//1. Lelo
		out[j] = in[i];
		printSubsequence(in,out,i+1,j+1);
	//2. Chod do
		printSubsequence(in,out,i+1,j);
}

int main(){
	char input[] = "abc";
	char output[10];
	printSubsequence(input,output,0,0);



return 0;
}
#include<iostream>
#include<cstring>
using namespace std;

string keys[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void phoneKeypad(char *in,char *out,int i,int j){
	if(in[i]=='\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}

	//Rec Case
	int digit = in[i] - '0';
	//int len = keys[digit].length();

	for(int k=0;keys[digit][k]!='\0';k++){
		out[j] = keys[digit][k];
		phoneKeypad(in,out,i+1,j+1);
	}
}

int main(){

	char input[10];
	cin>>input;
	char output[10];
	phoneKeypad(input,output,0,0);



	return 0;
}
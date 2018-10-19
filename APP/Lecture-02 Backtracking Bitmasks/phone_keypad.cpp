#include<iostream>
#include<cstring>
using namespace std;


string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeyCombination(char *input,char *output,int i=0,int j=0){
	if(input[i]=='\0'){
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}

	///Rec Case
	int current_digit = input[i] - '0';
	if(current_digit==0||current_digit==1){
		printKeyCombination(input,output,i+1,j);
	}

	for(int k=0;k<keypad[current_digit].size();k++){
		output[j] = keypad[current_digit][k];
		printKeyCombination(input,output,i+1,j+1);
	}

}


int main(){

	char input[10];
	cin>>input;

	char output[10];
	printKeyCombination(input,output);


	return 0;
}
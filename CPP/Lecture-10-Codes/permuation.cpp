#include<iostream>
using namespace std;

void printPermuation(char *input,int i){
	if(input[i]=='\0'){
		cout<<input<<endl;
		return;
	}
	//Rec Case
	for(int j=i;input[j]!='\0';j++){
		swap(input[i],input[j]);
		printPermuation(input,i+1);
		//Backtrack to restore my original array
		swap(input[i],input[j]);
	}
}
int main(){
	char input[] = "abc";
	printPermuation(input,0);
return 0;
}
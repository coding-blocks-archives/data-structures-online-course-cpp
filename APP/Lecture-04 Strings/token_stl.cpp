#include<iostream>
#include<cstring>
using namespace std;

//char* strtok(char in[],char delims[]){}
//
char *myStrtok(char *input,char delim){

	static char * ptr;
	if(input!=NULL){
		ptr = input;
	}
	if(ptr==NULL){
		return NULL;
	}


	char* output = new char[strlen(ptr)+1];

	int i;
	for(i=0;ptr[i]!='\0';i++){
		if(ptr[i]==delim){
			output[i] = '\0';
			ptr = ptr + i + 1;
			return output;
		}
		output[i] = ptr[i];
	}

	output[i] = '\0';
	ptr = NULL;
	return output;
}


int main(){

	char in[]  = "Hello   this is a string tokenizer!";


	char *ans = myStrtok(in,' ');
	
	while(ans!=NULL){
		cout<<ans<<endl;
		ans = myStrtok(NULL,' ');
	}

	char *arr = "Hello world!";
	ans = myStrtok(arr,' ');


return 0;
}
#include<iostream>
#include<cstring>
using namespace std;

int len(char a[]){

	int i=0;
	for( ;a[i]!='\0';i++){

	}
	return i;
}

void append(char *a,char *b){
	int i = len(a);
	int j = 0;

	while(b[j]!='\0'){
		a[i++] = b[j++];
	}
	a[i] = '\0';
}



int main(){
	char a[100],b[100];
	cin.getline(a,100);
	cin.getline(b,100);
	append(a,b);
	cout<<a <<endl;

	strcpy(b,a);
	cout<<b <<endl;



	
	return 0;
}
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
	char current[100],largest[100];
	int clen=0;
	int largestLen = 0;

	int n;
	cin>>n;

	cin.ignore();

	for(int i=0;i<n;i++){
		cin.getline(current,100);
		clen = len(current);
		
		if(clen>largestLen){
			strcpy(largest,current);
			largestLen = clen;
		}
	}
	cout<<"Largest string is"<<largest<<endl;



	
	return 0;
}
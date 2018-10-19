#include<iostream>
using namespace std;

int len(char a[]){

	int i=0;
	for( ;a[i]!='\0';i++){

	}
	return i;
}

bool isPalin(char *a){
	int i = 0;
	int j = len(a) - 1;
	while(i<j){
		if(a[i]!=a[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;

}

int main(){
	char a[100];
	cin.getline(a,100);

	cout<<len(a)<<endl;
	if(isPalin(a)){
		cout<<"Palindrome!";
	}
	else{
		cout<<"Not a Palindrome!";
	}

	return 0;
}
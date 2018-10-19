#include<iostream>
#include<cstring>
using namespace std;



int main(){

	char a[10][100];

	//You want to take input n strings
	int n;
	cin>>n;
	cin.ignore(); //to ignore the enter after n

	for(int i=0;i<n;i++){
		cin.getline(a[i],100);  //Each row of the character will be filled
	}

	//Write Bubble Sort on 2-D array of string to sort it.

	char key[100];
	cout<<"Enter string to search";
	cin.getline(key,100);

	//You can also search it
	int i;
	for(i=0;i<n;i++){
			
		//To compare two arrays,use a loop or inbuild strcmp() function
		if(strcmp(key,a[i])==0){
			cout<<"Found at index "<<i<<endl;
			break;
		}

	}
	if(i==n){
		cout<<"Not found!";
	}
	return 0;
}
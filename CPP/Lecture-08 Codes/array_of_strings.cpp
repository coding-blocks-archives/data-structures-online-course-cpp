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



	//You can also print it
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}





	return 0;
}
#include<iostream>
using namespace std;

void readMatrix(int a[][10],int R,int C){

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>a[i][j];
		}
	}
}
void printMatrix(int a[][10],int R,int C){

	for(int i=0;i<R;i++){
		//For every row, we have iterate over every column
		for(int j=0;j<C;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl; //New line after every row
	}

}
//Stair Case Search
void stairCaseSearch(int a[][10],int R,int C,int key){

	//You can start from 0,C-1;
	int i = 0,j=C-1;

	while(i<R&&j>=0){

		if(a[i][j]==key){
			cout<<"Found at postion "<<i<<" and "<<j<<endl;
			return;
		}
		else if(a[i][j]>key){
			j--;
		}
		else{
			i++;
		}
	}

	cout<<"Element not found!";
	return;
}


int main(){
	
	int a[10][10];
	int R,C;

	cin>>R>>C;
	//Read the matrix
	readMatrix(a,R,C);

	//Print the Matrix
	printMatrix(a,R,C);

	//Wave print
	int key;
	cout<<"Enter the element to search :";
	cin>>key;
	stairCaseSearch(a,R,C,key);



	


	return 0;
}
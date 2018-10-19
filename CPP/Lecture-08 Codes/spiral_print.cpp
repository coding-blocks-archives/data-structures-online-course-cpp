#include<iostream>
using namespace std;

void initMatrix(int a[][10],int R,int C){
	int value=1;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			a[i][j] = value++;
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
void spiralPrint(int a[][10],int R,int C){

	int startRow = 0,endRow = R-1,startCol =0,endCol = C - 1;

	while(startRow<=endRow && startCol<=endCol){
		//Print start row first
		for(int j=startCol;j<=endCol;j++){
			cout<<a[startRow][j]<<" ";
		}
		startRow++;

		//Print endCol
		for(int i=startRow;i<=endRow;i++){
			cout<<a[i][endCol]<<" ";
		}
		endCol--;


		//Print endRow - Make sure it is printed if endRow > startRow
		if(endRow>startRow){
		for(int j=endCol;j>=startCol;j--){
			cout<<a[endRow][j]<<" ";
		}
		endRow--;
		}

		//Print startCol
		if(startCol<endCol){
		for(int i=endRow;i>=startRow;i--){
			cout<<a[i][startCol]<<" ";
		}
		startCol++;
		}
	}
}


int main(){
	
	int a[10][10];
	int R,C;

	cin>>R>>C;
	//Read the matrix
	initMatrix(a,R,C);

	//Print the Matrix
	printMatrix(a,R,C);

	//Spiral Print
	spiralPrint(a,R,C);


	


	return 0;
}
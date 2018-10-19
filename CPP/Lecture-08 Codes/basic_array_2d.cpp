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
//Wave Print

void wavePrint(int a[][10],int R,int C){

	//Iterate Over Columns
	for(int j=0;j<C;j++){
		//you can for odd and even column
		if(j&1){
			//Odd Column
			for(int i=R-1;i>=0;i--){
				cout<<a[i][j]<<" ";
			}

		}
		else{
			//Even Column
			for(int i=0;i<R;i++){
				cout<<a[i][j]<<" ";
			}
		}
	}
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
	wavePrint(a,R,C);

	


	return 0;
}
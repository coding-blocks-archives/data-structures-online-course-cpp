#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number){

	//Row and column mei check kro
	for(int x=0;x<n;x++){
		if(mat[x][j]==number||mat[i][x]==number){
			return false;
		}
	}
	//Subgrid
	n = sqrt(n);
	int sx = (i/n)*n;
	int sy = (j/n)*n;

	for(int x=sx;x<sx+n;x++){
		for(int y=sy;y<sy+n;y++){
			if(mat[x][y]==number){
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
	//Base Case
	if(i==n){
		//Print the matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	// Row ke end pe aagye
	if(j==n){
		return solveSudoku(mat,i+1,0,n);
	}
	//Blue Cell
	if(mat[i][j]!=0){
		return solveSudoku(mat,i,j+1,n);
	}
	//White Cell
	for(int number=1;number<=n;number++){
		if(canPlace(mat,i,j,n,number)){
			//Rakh do
			mat[i][j] = number;

			//Aage call kro
			bool baatBni = solveSudoku(mat,i,j+1,n);

			//Baat ban jae to 
			if(baatBni){
				return true;
			}
		}
	}	
	//Fir bhi baat nahi bne to Backtrack kro
	mat[i][j] = 0;
	return false;
}

int main(){



	int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

        solveSudoku(mat,0,0,9);


	return 0;
}
#include<iostream>
using namespace std;

bool isSafe(int board[][20],int n,int x,int y){

		for(int i=0;i<n;i++){
			if(board[i][y]==1){
				return false;
			}
		}
			//Left andRight diagonal
				int x1 = x;
				int y1 = y;
				while(x1>=0 && y1>=0){
					if(board[x1][y1]){
						return false;
					}
					x1--;
					y1--;
				}
				x1 = x;
				y1 = y;
				while(x1>=0 && y1<n){
					if(board[x1][y1]){
						return false;
					}
					x1--;
					y1++;
				}
				return true;
}

bool solveNQueen(int board[][20],int row,int n){

	//Base Case
	if(row==n){
		//Print the board
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}	
	//Rec Case
	//Try to place queen at every column in the current row

	for(int i=0;i<n;i++){
			if(isSafe(board,n,row,i)){
				board[row][i] = 1;
				bool nextQueenRakhPaye =solveNQueen(board,row+1,n);
				if(nextQueenRakhPaye){
					return true;
				}
				board[row][i] = 0;
			}

	}
	return false;
}

int main(){
	int n;
	int board[20][20]={0};
	cin>>n;
	solveNQueen(board,0,n);


}
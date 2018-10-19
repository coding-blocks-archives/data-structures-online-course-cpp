#include<iostream>
using namespace std;

bool solveMaze(char maze[][20],int sol[][20],int i,int j,int m,int n){
	//Base Case
	if(i==m && j==n){
		sol[i][j] = 1;

		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}
	//Rec Case
	//Assuming rat passes through current cell
	sol[i][j] = 1;

	//Try moving right
	if(j+1<=n && maze[i][j+1]!='X'){
		bool rightSeRastaHai = solveMaze(maze,sol,i,j+1,m,n);
		if(rightSeRastaHai){
			return true;
		}
	}


	//try moving down
	if(i+1<=m &&maze[i+1][j]!='X'){
		bool neecheSeRastaHai = solveMaze(maze,sol,i+1,j,m,n);
		if(neecheSeRastaHai){
			return true;
		}
	}
	sol[i][j] = 0;
	return false;
}
int main(){
	int sol[20][20] = {0};

	char maze[20][20] = {
		"0000",
		"0XX0",
		"0XXX",
		"0000",
		"X000"
	};
	solveMaze(maze,sol,0,0,4,3);
return 0;
}
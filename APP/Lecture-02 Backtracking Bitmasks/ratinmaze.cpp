#include<iostream>
using namespace std;

bool solveRatInMaze(char maze[][10],int soln[][10],int i,int j,int n,int m){
	//Base Case
	if(i==n&&j==m){

        soln[i][j] = 1;

		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	//Rec Case
	//Assume path exists through cell i,j
	soln[i][j] = 1;

	if(j<m && maze[i][j+1]!='X'){
			bool pathExists = solveRatInMaze(maze,soln,i,j+1,n,m);
			if(pathExists){
				return true;
			}
	}
	if(i<n && maze[i+1][j]!='X'){
		bool pathExists = solveRatInMaze(maze,soln,i+1,j,n,m);
		if(pathExists){
			return true;
		}

	}
	//Path doesnt exist through current cell
	soln[i][j] = 0;
	return false;
}


int main(){
	char maze[10][10] = {
		"00X00",
		"00XXX",
		"00000",
		"00X00",
		"X0000"
	};
	int n = 5;
	int m = 5;

	int soln[10][10] = {0};

	if(solveRatInMaze(maze,soln,0,0,n-1,m-1)==false){
		cout<<"No path exists!";
	}



	return 0;
}

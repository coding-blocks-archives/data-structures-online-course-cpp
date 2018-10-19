#include<iostream>
#define nn 1001
using namespace std;

bool v[nn][nn],sol[nn][nn];
char maze[nn][nn];
int n,m;
bool solveMaze(int i,int j){
    ///Base Case
    if(i==m && j==n){

        sol[i][j] = 1;

        ///Print the soln
        for(int x=0;x<=m;x++){
            for(int y=0;y<=n;y++){
                cout<<sol[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(v[i][j])
    	return false;
    v[i][j]=1;
    ///Recursive Case
    ///Assuming path exists from i,j
    sol[i][j] = 1;
    ///1. Go Right
        if(j+1<=n && !v[i][j+1]){
                bool pathMila = solveMaze(i,j+1);
                if(pathMila==true){
                    return true;
                }
        }
    /// 2. Go Down
        if(i+1<=m && !v[i+1][j]){
                bool pathMila = solveMaze(i+1,j);
                if(pathMila==true){
                    return true;
                }
        }

    /// Yahan aane se path nahin mila !
    ///Backtracking
    sol[i][j] = 0;
    return false;


}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>maze[i][j];
			if(maze[i][j]=='X')
				v[i][j]=1;
		}
	}
	m--;
	n--;
    int ans =solveMaze(0,0);
    if(ans==false){
        cout<<"-1";
    }
    return 0;
}
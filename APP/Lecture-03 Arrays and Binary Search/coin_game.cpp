#include<iostream>
using namespace std;


int mat[10][10] = {0};

int f(int *a,int i,int j){
	if(i>j){
		return 0;
	}

	if(mat[i][j]!=0){
		return mat[i][j];
	}

	int partial_ans = f(a,i+1,j-1);
	int firstCoin = a[i] + min(f(a,i+2,j),partial_ans);
	int lastCoin =  a[j]  + min(f(a,i,j-2),partial_ans);

	int ans = max(firstCoin,lastCoin);
	mat[i][j] = ans;


	return ans;
}

int main(){
	int a[] = {1,4,3,2,18,3};
	int n = 6;

	cout<<f(a,0,n-1)<<endl;


return 0;
}
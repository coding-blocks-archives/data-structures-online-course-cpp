#include<iostream>
using namespace std;

int dp[100][100] = {0};

//Top Down DP
int wines(int *a,int i,int j,int day){
	
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}

	int op1 = a[i]*day + wines(a,i+1,j,day+1);
	int op2 = a[j]*day + wines(a,i,j-1,day+1);
	return dp[i][j]= max(op1,op2);
}

int main(){

	int a[] = {2,3,5,1,4};



	cout<<wines(a,0,4,1)<<endl;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}
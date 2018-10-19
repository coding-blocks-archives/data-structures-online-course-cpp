#include<iostream>
using namespace std;

int ways(int i,int j){
	if(i==0&&j==0){
		return 1;
	}
	//Out of bounds
	if(i<0||j<0){
		return 0;
	}
	//Otherwise
	return ways(i-1,j) + ways(i,j-1);
}

int elephantWays(int i,int j){
	if(i==0&&j==0){
		return 1;
	}
	if(i<0 || j<0){
		return 0;
	}

	//Otherwise
	int ans = 0;
	for(int k=1;k<=i;k++){
		ans += elephantWays(i-k,j);
	}
	for(int k=1;k<=j;k++){
		ans += elephantWays(i,j-k);
	}
	return ans;
}
int ladderWays(int n){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}

	return ladderWays(n-1) + ladderWays(n-2) + ladderWays(n-3);

}

int main(){
	
	cout<<ways(2,2)<<endl;
	cout<<elephantWays(2,3)<<endl;
	cout<<ladderWays(4)<<endl;

	return 0;
}

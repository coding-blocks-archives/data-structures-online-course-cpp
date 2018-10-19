#include<iostream>
using namespace std;

void toh(int n,char src,char dest,char helper){
	if(n==0){
		return;
	}
	toh(n-1,src,helper,dest);
	cout<<"Legya "<<n<<" disk from "<<src<<" to "<<dest<<endl;
	toh(n-1,helper,dest,src);
}
int steps(int n){
	if(n==0){
		return 0;
	}
	int ans = 2*steps(n-1) + 1;
	return ans;
}

int main(){
	int n;
	cin>>n;
	toh(n,'A','C','B');
	cout<<steps(n)<<endl;
	return 0;
}
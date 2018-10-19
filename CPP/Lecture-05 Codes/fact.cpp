#include<iostream>
using namespace std;

int fact(int no){

	int ans = 1;
	for(int i=1;i<=no;i++){
		ans = ans*i;
	}
	return ans;
}

int nCr(int n,int r){
	return fact(n)/(fact(n-r)*fact(r));
}

void printPascal(int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<nCr(i,j)<<" ";
		}
		cout<<endl;

	}

}



int main(){
	
	cout<<fact(5)<<endl;
	cout<<nCr(5,2)<<endl;
	printPascal(7);

	return 0;
}
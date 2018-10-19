#include<iostream>
using namespace std;


bool isSorted(int *a,int n){
	if(n==1){
		return true;
	}x
	if(a[0]<a[1] && isSorted(a+1,n-1)){
		return true;
	}
	return false;
}

int main(){

	int a[] = {1,3,4,5,8};
	int n = 5;
	if(isSorted(a,n)){
		cout<<"Array is sorted!";
	}
	else{
		cout<<"Array is not sorted!";
	}



	return 0;
}
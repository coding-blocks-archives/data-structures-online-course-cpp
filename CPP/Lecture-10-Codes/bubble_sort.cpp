#include<iostream>
using namespace std;

void bubbleSort(int *a,int n){

	if(n==1||n==0){
		return;
	}

	for(int j=0;j<n-1;j++){
		if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
		}
	}
	bubbleSort(a,n-1);
}

void bubbleSort(int *a,int j,int n){

	if(n==1||n==0){
		return;
	}
	if(j==n-1){
		bubbleSort(a,0,n-1);
		return;
	}

	if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
	}
	bubbleSort(a,j+1,n);
}


int main(){
	int a[] = {1,2,4,3,7,6,8};
	int n = sizeof(a)/sizeof(int);

	bubbleSort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}





}



#include<iostream>
using namespace std;

void merge(int a[],int b[],int m,int n){
	int i = m-1;
	int j = n-1;
	int k = m+n-1;

	while(i>=0 && j>=0){
		if(a[i]>b[j]){
			a[k] = a[i];
			i--; k--;
		}
		else{
			a[k] = b[j];
			j--;
			k--;
		}
	}

	// j might not be zero
	while(j>=0){
		a[k] = b[j];
		k--; j--;
	}
}


int main(){
	int a[7] = {2,6,7,10};
	int m = 4;

	int b[3] = {0,1,9}; 
	int n = 3;

	merge(a,b,m,n);

	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}

return 0;
}
#include<iostream>
using namespace std;
int search2(int *a,int n,int i,int key){
	if(i==n){
		return -1;
	}

	//Recursive Case
	if(a[i]==key){
		return i;
	}
	int chotaIndex = search2(a,n,i+1,key);
	return chotaIndex;
}


int search(int *a,int n,int key){
	if(n==0){
		return -1;
	}

	//Recursive Case
	if(a[0]==key){
		return 0;
	}
	int chotaIndex = search(a+1,n-1,key);
	
	if(chotaIndex==-1){
		return -1;
	}
	return chotaIndex + 1;

}

int main(){
	int a[] = {1,2,4,3,7,6,8};
	int n = sizeof(a)/sizeof(int);

	cout<<search2(a,n,0,7)<<endl;





}



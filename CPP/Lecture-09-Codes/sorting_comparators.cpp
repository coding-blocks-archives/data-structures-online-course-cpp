#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	int a1 = 10;
	cout<<a1<<endl;	
	//return a<b;
}

void bubbleSort(int *a,int n){

	for(int i=0;i<n-1;i++){
		for(int j=0;j<=n-i-2;j++){
			if(compare(a[j],a[j+1])){
				swap(a[j],a[j+1]);
			}
		}
	}
}


void print(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
}

int main(){

	int a[] = {1,4,3,0,7,8};
	int n = 6;
	print(a,n);
	//bubbleSort(a,n);
	sort(a,a+n,compare);
	print(a,n);



}
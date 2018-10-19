#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

int a[1000000];

void bubbleSort(int *a,int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<=n-i-2;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

void generateArray(int *a,int n){

	for(int i=0;i<n;i++){
		a[i] = n - i;
	}
}

int main(){

	int tests=10,n;
	while(tests--){
		cin>>n;

		generateArray(a,n);
		clock_t start,end;
		start = clock();
		sort(a,a+n);
		end = clock();
		cout<<"Merge sort took "<<end-start<<endl;

		generateArray(a,n);	
		start = clock();
		bubbleSort(a,n);
		end = clock();
		cout<<"Bubble sort took "<<end-start<<endl;
	}



}
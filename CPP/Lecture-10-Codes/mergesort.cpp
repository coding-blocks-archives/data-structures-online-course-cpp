#include<iostream>
using namespace std;

void merge(int *x,int *y,int *a,int s,int e){
	int i = s;
	int mid = (s+e)/2;
	int j = mid+1;
	int k = s;

	while(i<=mid && j<=e){
		if(x[i]<y[j]){
			a[k] = x[i];
			k++; i++;
		}
		else{
			a[k++] = y[j++];
		}
	}
	//Either of one array is left
	while(i<=mid){
		a[k++] = x[i++];
	}
	while(j<=e){
		a[k++] = y[j++];
	}
}

void mergeSort(int *a,int s,int e){
	//Base Case s>e no element
	if(s>=e){
		return;
	}
	//Rec Case
	//1. Divide
		int mid = (s+e)/2;
		int x[100],y[100];

		for(int i=s;i<=mid;i++){
			x[i] = a[i];
		}
		for(int i=mid+1;i<=e;i++){
			y[i] = a[i];
		}
	//2. Sort
		mergeSort(x,s,mid);
		mergeSort(y,mid+1,e);
	//3. Merge
		merge(x,y,a,s,e);
}

int main(){
	int a[]  = {2,1,4,3,6,5};
	int s = 0, e = 5;
	mergeSort(a,s,e);

	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}
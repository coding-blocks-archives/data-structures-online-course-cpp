#include<iostream>
using namespace std;
	
int binarySearchPivot(int *a,int s,int e){
	
	int mid;
	while(s<=e){
		//Pivot 
		mid = (s+e)/2;

		if(mid>0 && mid<e && a[mid]>a[mid-1] && a[mid]>a[mid+1]){
			return mid;
		}
		else if(mid>0 && mid<e && a[mid]<a[mid-1]&&a[mid]<a[mid+1]){
			return mid-1;
		}

		if(a[mid]>a[s]){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	return -1;
}

int main(){
	int a[] = { 10,11,1,2,3,4,5,6};
	int n = sizeof(a)/sizeof(int);

	cout<<binarySearchPivot(a,0,n-1)<<endl;

	return 0;
}
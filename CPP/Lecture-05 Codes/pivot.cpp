#include<iostream>
using namespace std;

int findPivot(int a[],int n){

	int s = 0;
	int e = n - 1;

	while(s<=e){
		int mid = (s+e)/2;

		if(mid<e && a[mid]>a[mid+1]){
			return mid;
		}
		else if(mid>s&&a[mid]<a[mid-1]){
			return mid-1;
		}
		if(a[s]<a[mid]){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
}

int main(){


	int a[] = {5,6,7,1,2,3,4};
	int n = 7;
	cout<<findPivot(a,n)<<endl;
	return 0;
}
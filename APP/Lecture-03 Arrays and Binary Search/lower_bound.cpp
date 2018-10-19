#include<iostream>
using namespace std;
	
int binarySearch(int *a,int s,int e,int key){
	int mid;

	int ans = -1;

	while(s<=e){
		mid = (s+e)>>1;

		if(a[mid]==key){
			ans = mid;
			e = mid - 1; 
		}
		else if(a[mid]>key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}

	}

	return ans;


}

int main(){
	int a[] = {1,2,2,2,2,2,3,5,8,10,11};
	int n = sizeof(a)/sizeof(int);

	int key;
	cin>>key;

	cout<<"First index of key is "<<binarySearch(a,0,n-1,key);



	return 0;
}
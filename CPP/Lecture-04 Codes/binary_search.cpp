#include<iostream>
using namespace std;


int main(){

		int a[] = {1,2,3,5,7,8,10};
		int n = sizeof(a)/sizeof(int);

		cout<<"Enter the element to search";
		int key;
		cin>>key;

		//Binary Search
		int s = 0;
		int e = n-1;
		int mid;

		while(s<=e){
			mid = (s+e)/2;

			if(a[mid]==key){
				cout<<"Found at index"<<mid;
				break;
			}
			else if(a[mid]>key){
				e = mid - 1;
			}
			else{
				s = mid + 1;
			}

		}
		if(s>e){
			cout<<"Element not found!";
		}

return 0;
}
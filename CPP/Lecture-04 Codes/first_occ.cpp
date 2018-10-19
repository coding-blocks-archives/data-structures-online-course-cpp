#include<iostream>
using namespace std;


int main(){

		int a[] = {1,2,2,2,2,2,3,3,3,3,3,3,3,5,7,8,10};
		int n = sizeof(a)/sizeof(int);

		cout<<"Enter the element to search";
		int key;
		cin>>key;

		//Binary Search
		int s = 0;
		int e = n-1;
		int mid;
		int ans = -1;

		while(s<=e){
			mid = (s+e)/2;

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
		if(ans==-1){
			cout<<"Not found";
		}
		else{
				cout<<ans<<endl;
			}
return 0;
}
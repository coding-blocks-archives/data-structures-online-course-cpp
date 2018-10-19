#include<iostream>
using namespace std;


int main(){

		int a[] = {1,2,3,5,7,8,10};
		int n = sizeof(a)/sizeof(int);

		cout<<"Enter the element to search";
		int key;
		cin>>key;

		//Linear Search 
		int i=0;
		for( ;i<n;i++){
			if(a[i]==key){
				cout<<"Found at index "<<i<<endl;
				break;
			}
		}
		if(i==n){
				cout<<"Not found";
		}

return 0;
}
#include<iostream>
using namespace std;


int main(){

		int n;
		cin>>n;

		//Binary Search for sq root
		int ans = 0;

		int s = 1;
		int e = n;
		int mid;

		while(s<=e){
			mid = (s+e)/2;

			if(mid*mid==n){
				ans = mid;
				break;
			}
			else if(mid*mid>n){
				e = mid - 1;
			}
			else{
				ans = mid;
				s = mid + 1;
			}

		}
		cout<<ans<<endl;

return 0;
}
#include<iostream>
using namespace std;
	
int binarySearchRoot(int no){
	int mid;
	int s= 1;
	int e = no;


	int ans = 0;

	while(s<=e){
		mid = (s+e)>>1;

		if(mid*mid==no){
			return mid;
		}
		else if(mid*mid>no){
			e = mid - 1;
		}
		else{
			ans = mid;
			s = mid + 1;
		}

	}
	return ans;


}

int main(){
	int no;
	cin>>no;
	cout<<binarySearchRoot(no)<<endl;

	return 0;
}
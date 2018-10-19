#include<iostream>
using namespace std;


bool isValid(int books[],int n,int s,int current_ans){

	int student = 1;
	int currently_alloted = 0;

	for(int i=0;i<n;i++){

		if(currently_alloted+books[i]<=current_ans){
			currently_alloted += books[i];
		}
		else{
			student++;
			currently_alloted = books[i];
			if(student>s){
				return false;
			}
		}
	}
	return true;


}


int minPages(int books[],int n,int k){

	int s = 40;
	int e = 100; //sum of all pages loop
	int ans = 0;

	while(s<=e){
		int mid = (s+e)/2;

		if(isValid(books,n,k,mid)==true){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int main(){

	int books[] = {10,20,30,40};
	int n = 4;
	int s = 3;
	cout<<minPages(books,n,s)<<endl;







	return 0;
}
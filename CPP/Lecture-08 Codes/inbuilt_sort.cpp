#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	//cout<<"Comparing "<<a<<" and "<<b<<endl;
	return a>b; //Desending Order
}

int main(){

	int a[] = {1,5,4,3,2,6,8};
	int n = sizeof(a)/sizeof(int);

	//You want to them - Desending Order ?
	sort(a,a+n,compare);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

return 0;
}
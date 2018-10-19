#include<iostream>
using namespace std;

void fun(int *b,int n){

	cout<<sizeof(b);
	for(int i=0;i<n;i++){
		cout<< *(b+i) <<endl;
		cout<< b[i] <<endl;
	}
}

int main(){
	int a[10] = {1,2,3,4,5,5};
	cout<<sizeof(a);
	fun(a+5,10);

}
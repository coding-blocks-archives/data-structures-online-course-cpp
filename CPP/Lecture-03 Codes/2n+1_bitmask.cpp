#include<iostream>
using namespace std;

int main(){
	int n = 10;
	int a[] = {1,3,4,4,5,1,6,6,7,3};

	int XOR = 0;
	for(int i=0;i<n;i++){
		XOR ^= a[i];
	}
	cout<<XOR<<endl;
	int res = XOR;
	///Find out the postion of last set bit

	int pos=0;
	int last_bit = (XOR&1);
	while(last_bit!=1){
		XOR = XOR>>1;
		last_bit = (XOR&1);
		pos++;
	}

	int mask = 1<<pos;
	int set1 = 0;
	for(int i=0;i<n;i++){
		if((mask&a[i])==0){
			set1 = set1^a[i];
		}
	}
	cout<<"Unique Numbers :";
	cout<<set1<<endl;
	cout<<(res^set1)<<endl;


return 0;
}
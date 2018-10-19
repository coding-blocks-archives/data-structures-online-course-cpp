#include<iostream>
using namespace std;


int main(){

	float res=1;
	int n=0;

	float num = 365;
	int denom = 365;


	while(res>0.1){
		res *= (num/denom);
		num--;
		n++;
		cout<<"Count is "<<n<<" and prob is "<<res<<endl;
	}





}
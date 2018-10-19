#include<iostream>
using namespace std;



int main(){
	int no;
	cin>>no;
	int j;
	for(int i=2;i<=no;i++){

		for(j=2; j*j<=i;j++){
			if(i%j==0){
				break;
			}

		}
		//No is prime if for loop is complete - j*j >i
		if(j*j>i){
			cout<<i<<",";
		}
	}


	return 0;
}
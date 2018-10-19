#include<iostream>
using namespace std;



int main(){
	int no = 20;
	int i=1;

	while(i<=no){
		

		if(i%7==0){
			i++;
			continue;
		}
		cout<<i<<",";
		i++;
	}

	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char*a,int n){
	if(n==0){
		return 0;
	}
	int last_digit = a[n-1] - '0';
	return stringToInt(a,n-1)*10 + last_digit;

}

int main(){
	char a[] = "1245";
	int n = strlen(a);

	cout<<stringToInt(a,n)<<endl;


}



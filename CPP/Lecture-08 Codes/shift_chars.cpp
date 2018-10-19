#include<iostream>
#include<cstring>
using namespace std;

void rotate(char *a,int k){

	int i = strlen(a);
	while(i>=0){
		a[i+k] = a[i];
		i--;
	}

	i = strlen(a);
	int j = i - k;
	int s = 0;
	while(j<i){
		a[s] = a[j];
		s++;
		j++;
	}
	a[i-k] = '\0';
}

int main(){

	char a[100] = "Coding Blocks";
	int k = 3;

	rotate(a,k);

	cout<<a<<endl;




}

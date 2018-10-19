#include<iostream>

using namespace std;

//char* strtok(char in[],char delims[]){}

int* makeArray(){
	int a[] = { 1,2,3};
	cout<<a<<endl;
	for(int i=0;i<3;i++){
		cout<<a[i]<<" ";
	}


	return a;
}

int main(){

	int *p = makeArray();
	cout<<"IN main";
	cout<<p<<endl;
	for(int i=0;i<3;i++){
		cout<<p[i]<<" ";
	}

return 0;
}
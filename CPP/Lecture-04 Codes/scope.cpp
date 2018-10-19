#include<iostream>
#include<cstring>
using namespace std;

//Global Varialbe
int n = 5;


int main(){

	cout<<n <<endl;
	//Local Variable
	int n = 10;

	cout<<n<<endl;

	if(n>8){
        int pi = 3;
        cout<<pi<<endl;
        ::n = ::n + 2;
        cout<<"Global n"<< ::n<<endl;
        cout<<"Local n"<<n<<endl;

	}
	//cout<<pi<<endl;
	int i;
	for(i=0;i<10;i++){

	}
	cout<<i<<endl;

	return 0;
}


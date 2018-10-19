#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		char ch = 'A';
		for(int j=1;j<=n-i;j++){
			cout<<ch;
			ch++;
		}

		ch--;

		for(int j=1;j<=n-i;j++){
			cout<<ch;
			ch--;
		}

		cout<<endl;

	}

	return 0;
}
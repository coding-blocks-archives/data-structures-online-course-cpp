#include<iostream>
using namespace std;


int main(){

	int n;
	cin>>n;

	int i=1;
	int no;
	int ans =0;
	while(i<=n){
		cin>>no;
		ans = ans ^ no;
		i++;
	}
	cout<<ans <<endl;

return 0;
}
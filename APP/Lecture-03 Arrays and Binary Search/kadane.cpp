#include<iostream>
using namespace std;


int kadanes(int *a,int n){
	int cs,ms;
	cs = ms = 0;
	for(int i=0;i<n;i++){
		cs += a[i];
		if(cs < 0){ cs = 0; };
		ms = max(ms,cs);
	}
	return ms;

}

int main(){
	int a[] = {1,-2,3,4,6,-5,8,1,-4, 2};
	
	int n = sizeof(a)/sizeof(int);
	cout<<kadanes(a,n)<<endl;

return 0;
}
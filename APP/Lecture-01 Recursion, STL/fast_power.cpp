#include<iostream>
using namespace std;
/*Three steps
1. Figure the base case
2. Assume the problem can be solved for f(k)
3. Using the assumption, write f(k+1) using reoccurence relation
*/

/*Time Complexity : O(Log(N))
  Space Complexity : O(Log(N)) 
*/
int power(int a,int b){
	if(b==0){
		return 1;
	}
	int value = power(a,b/2);
	value = value*value;

	if(b&1){
		return a*value;
	}
	return value;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<power(a,b)<<endl;
	return 0;
}
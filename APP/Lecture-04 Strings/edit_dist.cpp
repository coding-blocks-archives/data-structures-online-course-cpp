#include<iostream>
#include<cstring>
using namespace std;

string s1("apma");
string s2("me");
int I = 3;
int R = 4;
int D = 5;

int f(int i,int j){
	if(i==-1){
		return (j+1)*I;
	}
	else if(j==-1){
		return (i+1)*D;
	}

	if(s1[i]==s2[j]){
		return f(i-1,j-1);
	}

	int op1 = R + f(i-1,j-1);
	int op2 = D + f(i-1,j);
	int op3 = I + f(i,j-1);

	return min(op1,min(op2,op3));

}

int main(){


	return 0;
}
#include<bits/stdc++.h>
using namespace std;

void replacePi(char s[],int i=0){
	if(s[i+1]=='\0'){
		return;
	}

	///Otherwise
	if(s[i]=='p'&&s[i+1]=='i'){
			///Shifting
			int j = i+1;
			while(s[j]){j++;}

			while(j>i){
				s[j+2]  = s[j];
				j--;
			}

			s[i] = '3';
			s[i+1] = '.';
			s[i+2] = '1';
			s[i+3] = '4';

			replacePi(s,i+4);

	}
	else{
		replacePi(s,i+1);
	}



}

int main(){

	char s[100] = "xpiyhipiwz";
	///Output x3.14yhi3.14wz

	cout<<s<<endl;
	replacePi(s);
	cout<<s<<endl;
	return 0;
}
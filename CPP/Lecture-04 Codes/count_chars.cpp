#include<iostream>
using namespace std;


int main(){

		char ch;
		int count = 0;


		//Spaces, Digits, Alphabets, Others
		int spaces,digits,alphabets,others;
		spaces = digits = alphabets = others = 0;

		//Init
		ch = cin.get();
		//Termination
		while(ch!='$'){
			
			if(ch ==' '||ch=='\n'){
				spaces++;
			}
			else if(ch>='0'&&ch<='9'){
				digits++;
			}
			else if((ch>='a'&&ch<='z')|| (ch>='A'&&ch<='Z')){
				alphabets++;
			}
			else{
				others++;
			}


			ch = cin.get(); //Update
		}

		cout<<"Alphabets"<<alphabets<<endl;
		cout<<"Digits "<<digits<<endl;
		cout<<"Spaces "<<spaces<<endl;
		cout<<"Others "<<others<<endl;		
}
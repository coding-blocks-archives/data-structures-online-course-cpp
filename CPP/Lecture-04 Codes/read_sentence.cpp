#include<iostream>
using namespace std;


int main(){

		char ch;
		int count = 0;


		//Spaces, Digits, Alphabets, Others

		//Init
		ch = cin.get();
		//Termination
		while(ch!='$'){
				count++;
		  ch = cin.get(); //Update
		}

		cout<<count<<endl;		
}
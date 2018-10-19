#include<iostream>
using namespace std;


int main(){

	char ch = cin.get();
	int x=0;
	int y =0;

	while(ch!='\n'){
		if(ch=='N'){
			y++;
		}
		else if(ch=='S'){
			y--;
		}
		else if(ch=='E'){
			x++;
		}
		else{
			x--;
		}
		ch = cin.get();
	}
	cout<<"Final Displacment is"<< x<<"and "<<y<<endl;
	if(x>=0 &&y>=0){
			for(int e=0;e<x;e++){
				cout<<"E";
			}
			for(int n=0;n<y;n++){
				cout<<"N";
			}

	}


	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;

class Car{
	int model_no;
	string color;
	string name;
	const int tyres;
	//Static Data Member
	static int count;
public:
	Car():tyres(4){
		count++;
	}
	Car(const int m,string c,string n,int t=4):model_no(m),color(c),name(n),tyres(t){
			count++;
	}
	static int getCount(){
		return count;
	}
	void print() const{
		model_no++;
		cout<<model_no<<endl;
		cout<<name<<endl;
	}	
};
int Car::count = 0;


int main(){
	Car A,B,C;
	cout<<Car::getCount()<<endl;




	return 0;
}
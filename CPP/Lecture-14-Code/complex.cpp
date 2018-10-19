#include<iostream>
using namespace std;

class Complex{
	
	int real;
	int img;
public:
	Complex(){
		real = 0;
		img = 0;
	}
	Complex(const int r,const int i):real(r),img(i){}



	Complex(const Complex &c){
		real = c.real;
		img = c.img;
	}
	void operator=(const Complex &c){
		real = c.real;
		img = c.img;
	}
	
	void setValues(const int r=0,const int i=0){
		real = r;
		img = i;
	}
	Complex& operator+(const Complex&c2){
		Complex *k = new Complex;
		(*k).real = real + c2.real;
		(*k).img = img + c2.img;
		return (*k);
	}
	void print()const{
		if(img>0){
			cout<<real<<" + "<<img<<"i"<<endl;
		}
		else{
			cout<<real<<" "<<img<<"i"<<endl;
		}
	}
	int operator[](const string s) const{
		if(s=="real"){
			return real;
		}
		else{
			return img;
		}
	}
	void operator!(){
		img *= -1;
	}

	~Complex(){
	}

};

ostream& operator<<(ostream&os,Complex&c){
	c.print();
	return os;
}
istream& operator>>(istream&is,Complex&c){
	int r,i;
	cin>>r>>i;
	c.setValues(r,i);
	return is;
}




int main(){


	Complex c1(5,3);
	Complex c2(2,4);

	c1.print();
	c2.print();
	Complex c3;
	c3 = c1 + c2;
	c3.print();
	!c3;
	cout<<c3<<endl;
	cout<<c3["real"]<<endl;

	Complex c4;
	cin>>c4;

	cout<<c4;


	return 0;
}
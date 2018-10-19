#include<iostream>
#include<cstring>
using namespace std;


class Student{
	int marks;
public:
	char *name;
	char clg[100];

	Student(){
		strcpy(clg,"Coding Blocks");
		name = NULL;
	}

	Student(char *n,int m){
		name = new char[strlen(n)+1];
		strcpy(name,n);
		marks = m;
		strcpy(clg,"Coding Blocks");
	}
	Student(const Student &x){
		cout<<"In copy constructor ..."<<endl;
		name = new char[strlen(x.name)+1];
		strcpy(name,x.name);
		marks = x.marks;
		strcpy(clg,x.clg);
	}
	//Deep Copy Assignment Operator
	void operator=(const Student &x){
		cout<<"In copy Assignment operator"<<endl;
		if(name!=NULL){
			delete [] name;
		}

		name = new char[strlen(x.name)+1];
		strcpy(name,x.name);
		marks = x.marks;
		strcpy(clg,x.clg);

	}
	void operator+(const Student &X){
		char *oldName = name;
		int l1 = strlen(name);
		int l2 = strlen(X.name);

		name = new char[l1+l2+1];
		strcpy(name,oldName);
		strcpy(name+l1,X.name);

		delete [] oldName;
		marks += X.marks;
	}
	int marksBta(){
		return marks;
	}
	void resetMarks(int m){
	    if(m>=10){
		    marks = m;
	    }
	}
	void print(){
		cout<<"Name :"<<name<<endl;
		cout<<"Marks :"<<marks<<endl;
		cout<<"College :"<<clg<<endl;
		cout<<endl;
	}
	void operator[](string s){
		cout<<name<<" "<<s;
	}
	void operator!(){
		cout<<name<<" Bhag ja!";
	}
	void operator<<(ostream &x){
		print();
	}
	~Student(){
		cout<<"Deleting student "<<name;
		if(name!=NULL){
			delete [] name;
			name = NULL;
		}
	}
		
};

ostream& operator<<(ostream &x,Student &s){
	s.print();
	return x;
}
istream& operator>>(istream &x,Student &s){
	x>>s.name;
	return x;
}

int main(){
	char name[] = "amit";
	Student s(name,70);

	Student s2 = s;
	// or Student s2(s);

	strcpy(s.name,"Raju");
	s.resetMarks(50);
	s.print();
	s2.print();

	s2 = s; 
	s.name[0] = 'K';
	s.print();
	s2.print();

	Student s3;
	s3 = s2;

	s3+s;
	s3.print();

	s["Edhar aa"];
	s.print();
	
	//!s2;

	
	cout<<"Yaha hai !"<<endl;
	//s2 << cout;
	cout<< s2 <<s3;

	Student *sd = new Student("Xyz",90);
	delete sd;


	return 0;
}


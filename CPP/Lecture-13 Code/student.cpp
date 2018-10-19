#include<iostream>
#include<cstring>
using namespace std;


class Student{
	int marks;
public:
	char name[100];
	char clg[100];

	Student(){
		strcpy(clg,"Coding Blocks");
	}

	Student(char *n,int m){
		strcpy(name,n);
		marks = m;
		strcpy(clg,"Coding Blocks");
	}
	int marksBta(){
		return marks;
	}
	void resetMarks(int m){
	    if(m>=10){
		    marks = m;
	    }
	}
		
};

int main(){
	char name[] = "amit";
	Student s(name,70);
	Student s2,s3;
	s.resetMarks(50);
	cout<<s.marksBta()<<endl;

	cin>>s2.name;
	cout<<s2.name<<endl;

}


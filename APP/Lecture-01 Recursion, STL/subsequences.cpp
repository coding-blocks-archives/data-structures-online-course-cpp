#include<iostream>
#include<set>
using namespace std;

set<string> s;

void subsequence(char in[],int i,char out[],int j){
	if(in[i]=='\0'){
		out[j] = '\0';

		string str(out);
		s.insert(str);
		return;
	}
	///Rec Case
	out[j] = in[i];
	subsequence(in,i+1,out,j+1);
	out[j] = '\0';
	subsequence(in,i+1,out,j);
}

int main(){

	char input[100],out[100];
	cin>>input;
	subsequence(input,0,out,0);

	for(auto it = s.begin();it!=s.end();it++){
		cout<<(*it)<<endl;
	}
	
	//for each loop
	for(auto element:s){
		cout<<"element "<<element<<endl;
	}

	return 0;
}
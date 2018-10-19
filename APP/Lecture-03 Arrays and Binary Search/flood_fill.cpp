#include<iostream>
using namespace std;

int R,C;
void print(char mat[][50]){

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<mat[i][j];
		}
		cout<<endl;
	}
}

void fill(char mat[][50],int i,int j,char ch,char color){
	
	if(i<0||j<0||i>=R||j>=C|| mat[i][j]!=ch){
		return;
	}
	mat[i][j] = color;
	print(mat);
	cout<<endl;

	fill(mat,i+1,j,ch,color);
	fill(mat,i-1,j,ch,color);
	fill(mat,i,j+1,ch,color);
	fill(mat,i,j-1,ch,color);


}


int main(){
	cin>>R>>C;

	char mat[50][50];

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>mat[i][j];
		}
	}

	print(mat);
	fill(mat,8,13,'.','R');
	print(mat);

	return 0;
}
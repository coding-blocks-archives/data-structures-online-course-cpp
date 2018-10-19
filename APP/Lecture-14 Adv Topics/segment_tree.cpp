#include<iostream>
using namespace std;

void build(int *a,int *tree,int index,int s,int e){
	if(s>e){
		return;
	}
	if(s==e){
		tree[index] = a[s];
		return;
	}
	int mid = (s+e)/2;
	build(a,tree,2*index,s,mid);
	build(a,tree,2*index+1,mid+1,e);

	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}

int main(){

	int a[] = {2,3,-1,4,7};
	int n = sizeof(a)/sizeof(int);

	int *tree = new int[4*n+1];

	build(a,tree,1,0,n-1);

	for(int i=0;i<=9;i++){
		cout<<tree[i]<<" ";
	}



}
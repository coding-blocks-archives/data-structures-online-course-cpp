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

void updateNode(int *tree,int index,int s,int e,int node,int node_value){
	//Out of Bounds
	if(node<s||node>e){
		return;
	}
	//Leaf Node
	if(s==e){
		tree[index] = node_value;
		return;
	}
	//Call on both sides
	int mid = (s+e)/2;
	updateNode(tree,2*index,s,mid,node,node_value);
	updateNode(tree,2*index+1,mid+1,e,node,node_value);

	tree[index] = min(tree[2*index],tree[2*index+1]);
}

int queryRMQ(int *tree,int index,int s,int e,int qs,int qe){
	//No Overlap
	if(qs>e || s>qe){
		return INT_MAX;
	}
	//Complete Overlap
	if(s>=qs && e<=qe){
		return tree[index];
	}
	//Partial Overlap
	int mid = (s+e)/2;
	int leftAns = queryRMQ(tree,2*index,s,mid,qs,qe);
	int rightAns =queryRMQ(tree,2*index+1,mid+1,e,qs,qe);
	return min(leftAns,rightAns);
}

int main(){

	int a[] = {2,3,-1,4,7};
	int n = sizeof(a)/sizeof(int);

	int *tree = new int[4*n+1];

	build(a,tree,1,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	int update_i,update_v;
	cin>>update_i>>update_v;
	updateNode(tree,1,0,n-1,update_i,update_v);

	while(1){
	int l,r;
	cin>>l>>r;

	cout<<queryRMQ(tree,1,0,n-1,l,r);
	}
}
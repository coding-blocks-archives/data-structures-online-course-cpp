#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d):data(d),left(NULL),right(NULL){}
};

node* buildTree(){
	int d;
	//cout<<"Enter data";
	cin>>d;

	if(d==-1){
		return NULL;
	}
	else{
		node* n = new node(d);
		n->left = buildTree();
		n->right = buildTree();
		return n;
	}
}
void print1(node*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	print1(root->left);
	print1(root->right);

}
void print2(node*root){
	if(root==NULL){
		return;
	}

	print2(root->left);
	cout<<root->data<<" ";
	print2(root->right);
	
}
void print3(node*root){
	if(root==NULL){
		return;
	}

	print3(root->left);
	print3(root->right);
	cout<<root->data<<" ";
	
}
void levelOrderPrint(node*root){
	queue<node*> q;


	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();

		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		
		else{
			q.pop();
			cout<<temp->data<<" ";
			
			//Push the children
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}

int main(){
	node*root = buildTree();
	print1(root);
	cout<<endl;

	print2(root);
	cout<<endl;

	print3(root);
	cout<<endl;

	levelOrderPrint(root);

}



#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};

//Recursive fn to build tree
node* buildTree(){
	int data;
	cin>>data;
	
	if(data!=-1){
		node*root = new node(data);
		root->left = buildTree();
		root->right = buildTree();
		return root;
	}
	else{
		return NULL;
	}
}

void printTree(node*root){
	//Preorder
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printTree(root->left);
	printTree(root->right);
}

void printInorder(node*root){
	//Preorder
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printPostorder(node*root){
	//Preorder
	if(root==NULL){
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}
node* levelOrderBuild()
{	
	int d;
	cout<<"Enter the root data";
	cin>>d;
	node*root = new node(d);

	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node*temp = q.front();
		q.pop();

		cout<<"Enter children of "<<temp->data<<endl;
		int d1,d2;
		cin>>d1>>d2;

		if(d1!=-1){
			temp->left = new node(d1);
			q.push(temp->left);
		}
		if(d2!=-1){
			temp->right = new node(d2);
			q.push(temp->right);
		}
	} 
	return root;
}

int countNodes(node*root){
	if(root==NULL){
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}
int sumNodes(node*root){
	if(root==NULL){
		return 0;
	}
	return root->data + sumNodes(root->left) + sumNodes(root->right);
}
int height(node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return max(h1,h2) + 1;
}

int replaceNodes(node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	int temp = root->data;
	int leftSum = replaceNodes(root->left);
	int rightSum = replaceNodes(root->right);
	root->data = leftSum + rightSum;
	return temp + root->data;
}



void levelOrderPrint(node*root){
	if(root==NULL){
		return;
	}

	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node*temp = q.front();
		if(temp == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";


			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}

	}
}

ostream& operator<<(ostream&os, node*root){
	levelOrderPrint(root);
	return os;
}
istream& operator>>(istream&is, node*&root){
	root = levelOrderBuild();
	return is;
}

int diameter(node*root){
	if(root==NULL){
		return 0;
	}
	int op1 = height(root->left) + height(root->right);
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(op1,max(op2,op3));
}
class Pair{
public:
	int height;
	int diameter;
};

Pair fastDiameter(node*root){
	Pair p;
	if(root==NULL){
		p.diameter = p.height = 0;
		return p;
	}

	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;

	p.diameter = max(op1,max(op2,op3));
	p.height = max(left.height,right.height) + 1;
	return p;
}

class SumPair{
public:
	int inc;
	int exc;
};

SumPair maxSum(node*root){
	SumPair p;
	if(root==NULL){
		p.inc = p.exc = 0;
		return p;
	}

	SumPair left,right;
	left = maxSum(root->left);
	right = maxSum(root->right);

	p.inc = root->data + left.exc + right.exc;
	p.exc = max(left.inc,left.exc) + max(right.inc,right.exc);
	return p;


}



int main(){

	node*root = NULL;
	cin>>root;

	cout<<root;

	//cout<<diameter(root)<<endl;
	//cout<<fastDiameter(root).diameter<<endl;
	SumPair ans = maxSum(root);

	cout<<ans.inc<<endl;
	cout<<ans.exc <<endl;

return 0;
}
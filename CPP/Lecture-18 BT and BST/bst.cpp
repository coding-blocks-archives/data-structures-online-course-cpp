#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d):data(d),left(NULL),right(NULL){}
};
node* insertInBST(node*root,int data){
	if(root==NULL){
		root = new node(data);
		return root;
	}
	else if(data<=root->data){
		root->left = insertInBST(root->left,data);
	}
	else{
		root->right = insertInBST(root->right,data);
	}
	return root;
}

node* buildTree(){
		
		int d;
		cin>>d;
		node*root = NULL;
		while(d!=-1){
			root = insertInBST(root,d);
			cin>>d;
		}	
		return root;
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

int countNodes(node*root){
	if(root==NULL){
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

//O(N)
int height(node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);

	return max(h1,h2) + 1;
}
class Pair{
public:
	int diameter;
	int height;
};

//This works in O(N)
Pair fastDiameter(node*root){
	Pair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height,right.height) + 1;

	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;

	p.diameter = max(op1,max(op2,op3));
	return p;
}

//O(N^2)
int diameter(node*root){
	if(root==NULL){
		return 0;
	}
	int op1 = height(root->left) + height(root->right);
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1,max(op2,op3));
}

int index=0;
int n;

node*makeTree(int *pre,int *in,int s,int e){
	if(s>e){
		return NULL;
	}

	int d = pre[index];
	node* root = new node(d);
	index++;

	int k=-1;
	
	for(int j=s;j<=e;j++){
		if(in[j]==d){
			k = j;
			break;
		}
	}

	root->left = makeTree(pre,in,s,k-1);
	root->right = makeTree(pre,in,k+1,e);
	return root;
}

void mirror(node *root){
	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

//Complexity O(H)
node* searchInBST(node*root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		return root;
	}
	else if(root->data < key){
		return searchInBST(root->right,key);
	}
	return searchInBST(root->left,key);
}

class Pair2{
public:
	int height;
	bool balance;
};

Pair2 heightBalanced(node*root){
	Pair2 p;
	if(root==NULL){
		p.height =0 ;
		p.balance = true;
		return p;
	}
	Pair2 left = heightBalanced(root->left);
	Pair2 right = heightBalanced(root->right);

	if(left.balance&&right.balance&&(abs(left.height-right.height)<=1)){
		p.balance = true;
	}
	else{
		p.balance = false;
	}
	p.height = max(left.height,right.height)+1;
	return p;
}

bool isBST(node*root,int minV=INT_MIN,int maxV=INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data >=minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
}

node* arrayToBST(int *a,int s,int e){
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	node*root = new node(a[mid]);
	root->left = arrayToBST(a,s,mid-1);
	root->right = arrayToBST(a,mid+1,e);
	return root;
}

class LinkedList{
public:
	node*head;
	node*tail;
};

LinkedList tree2LL(node*root){
	LinkedList l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}
	if(root->left==NULL && root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	else if(root->left!=NULL && root->right==NULL){
		LinkedList leftLL = tree2LL(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	else if(root->left==NULL && root->right!=NULL){
		LinkedList rightLL = tree2LL(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
		return l;

	}
	else{
		LinkedList leftLL = tree2LL(root->left);
		LinkedList rightLL = tree2LL(root->right);

		leftLL.tail->right = root;
		root->right = rightLL.head;

		l.head = leftLL.head;
		l.tail = rightLL.tail;
		return l;
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

	cout<<"Count is "<<countNodes(root)<<endl;
	cout<<"Height is "<<height(root)<<endl;
	cout<<"Diameter is "<<diameter(root)<<endl;

	if(heightBalanced(root).balance){
		cout<<"Yes it is balanced!";
	}
	else{
		cout<<"No it is not!";
	}

	if(isBST(root)){
		cout<<"yes it is bst!";
	}
	else{
		cout<<"no it is not BST!";
	}

	LinkedList l  = tree2LL(root);
	node*temp = l.head;

	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp = temp->right;
	}


return 0;
}



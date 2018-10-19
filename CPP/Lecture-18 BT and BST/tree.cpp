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

node* buildLevelWise(){

	cout<<"Enter root data";
	int d;
	cin>>d;


	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		cout<<"Enter children of "<<temp->data;
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			temp->left = new node(c1);
			q.push(temp->left);
		}
		if(c2!=-1){
			temp->right = new node(c2);
			q.push(temp->right);
		}
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


int main(){
	int pre[] = {1,2,4,5,3,7,6,8};
	int in[] = {4,5,2,1,7,3,8,6};

	//node*root = buildTree();
	n = sizeof(in)/sizeof(int);
	int s= 0;
	int e = n -1;
	//node* root  = makeTree(pre,in,s,e);
	node*root = buildLevelWise();
	//mirror(root);
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




return 0;
}



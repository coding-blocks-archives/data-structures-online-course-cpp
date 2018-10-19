#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* insertInBst(node *root,int data){
	node*n;
	if(root==NULL){
		n = new node(data);
		return n;
	}
	else if(root->data<data){
		root->right = insertInBst(root->right,data);
	}
	else{
		root->left  = insertInBst(root->left,data);
	}
	return root;
}
node* search(node*root,int data){
	if(root==NULL){
		return NULL;
	}
	if(root->data==data){
		return root;
	}
	else if(root->data<data){
		return search(root->right,data);
	}
	else{
		return search(root->left,data);
	}

}

node* takeInput(){
	int d;
	cin>>d;

	node*root = NULL;
	while(d!=-1){
		root = insertInBst(root,d);
		cin>>d;
	}
	return root;
}
node* smallestNode(node*root){
	node*temp = root;
	while(temp->left!=NULL){
		temp = temp->left;
	}
	return temp;

}

node* deleteInBST(node*root,int data){
	if(root==NULL){
		return NULL;
	}
	else if(root->data==data){
		//0. No Child
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}

		//1. Single Child
		else if(root->left!=NULL && root->right==NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL && root->right!=NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}

		//2. Two child
		else{
			node* minNode = smallestNode(root->right);
			root->data = minNode->data;

			root->right = deleteInBST(root->right,minNode->data);
			return root;
		}



	}
	else if(root->data > data){
		root->left = deleteInBST(root->left,data);
	}
	else{
		root->right =  deleteInBST(root->right,data);
	}
	return root;
}

void inOrder(node*root){
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

class linkedList{
public:
	node*head;
	node*tail;
};

linkedList convertTree2LL(node*root){
	linkedList l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}
	if(root->left==NULL && root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	//Left subtree exist, 
	if(root->left!=NULL && root->right==NULL){
		linkedList leftLL = convertTree2LL(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
	}
	else if(root->left==NULL && root->right!=NULL){
		linkedList rightLL = convertTree2LL(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
	}
	else{
		linkedList leftLL = convertTree2LL(root->left);
		linkedList rightLL = convertTree2LL(root->right);

		leftLL.tail->right = root;
		root->right = rightLL.head;

		l.head = leftLL.head;
		l.tail = rightLL.tail;
	}
	return l;
}

bool isBST(node*root,int minV = INT_MIN,int maxV=INT_MAX){
	if(root==NULL){
		return true;
	}

	if(isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV) && 
		root->data>=minV && root->data<=maxV){
		return true;
	}
	return false;
}

node* arrayToBST(int *a,int s,int e){
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	node* root = new node(a[mid]);
	root->left = arrayToBST(a,s,mid-1);
	root->right = arrayToBST(a,mid+1,e);
	return root;
}

int i = 0;
int n = 7;
node* travToBST(int pre[],int in[],int s,int e){
	if(s>e){
		return NULL;
	}

	node* root = new node(pre[i]);

	//Linear Search
	int j;
	for(j=0;j<n;j++){
		if(in[j]==pre[i]){
			break;
		}
	}
	i++;

	root->left = travToBST(pre,in,s,j-1);
	root->right = travToBST(pre,in,j+1,e);
	return root;
}
void printPost(node*root){
	if(root==NULL){
		return;
	}
	printPost(root->left);
	printPost(root->right);

	cout<<root->data<<",";
} 

int main()
{
	/*node*root = takeInput();
	inOrder(root);

	int d;
	int x=5;
	*/
	/*while(x--){
		cout<<"Enter the node to delete";
		cin>>d;
		root = deleteInBST(root,d);
		inOrder(root);
		cout<<endl;
	}*/
	
	/*linkedList l =  convertTree2LL(root);
	node*temp = l.head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->right;
	}
	*/

	//Array to bst
	int a[] = {1,2,3,4,5,6,8,9,10};
	int n = sizeof(a)/sizeof(int);
	node*root = arrayToBST(a,0,n-1);
	//inOrder(root);

	// Preorder to BST;
	int pre[] = {4,2,1,3,5,6,7};
	int in[] = {1,2,3,4,5,6,7};
	 n = sizeof(pre)/sizeof(int);

	node*root2 = travToBST(pre,in,0,n-1);
	printPost(root2);






	return 0;
}


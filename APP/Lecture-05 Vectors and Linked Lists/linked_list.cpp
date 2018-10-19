#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
public:
	node(int d){
		data = d;
		next = NULL;
	}
};
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
}

void insertAtHead(node*&head,int d){
	node* n = new node(d);
	n->next = head;
	head = n;
}
void insertInMiddle(node*&head,int d,int p){
	if(p==0){
		insertAtHead(head,d);
	}
	else{
		//Assuming p<=len
		int jump=1;
		node*temp = head;
		while(jump<=p-1){
			jump++;
			temp = temp->next;
		}

		node* n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}
}

void takeInput(node*&head){
	int d;
	cin>>d;
	while(d!=-1){
		insertAtHead(head,d);
		cin>>d;
	}
}
ostream& operator<<(ostream&os,node*head){
	print(head);
	cout<<endl;
	return os;
}
istream& operator>>(istream&is,node*&head){
	takeInput(head);
	return is;
}
int length(node*head){
	int len=0;
	while(head!=NULL){
		len++;
		head = head->next;
	}
	return len;
}

node* find(node*head,int key){
	if(head==NULL){
		return NULL;
	}
	if(head->data==key){
		return head;
	}
	//Search in the remaining part
	return find(head->next,key);
}

node* midPoint(node*head){
	node*slow = head;
	node*fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void reverse(node*&head){
	node*prev = NULL;
	node*current = head;
	node*next;

	while(current!=NULL){
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}
	head = prev;
}
node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}
	node*newHead;
	if(a->data < b->data){
		newHead = a;
		a->next = merge(a->next,b);
	}
	else{
		newHead = b;
		b->next = merge(a,b->next);
	}
	return newHead;
}
node* mergeSort(node*head){
	//Base Case
	if(head==NULL||head->next==NULL){
		return head;
	}

	//Recursive Case
	//1. Break the list 
	node* mid = midPoint(head);
	node*a = head;
	node*b = mid->next;
	mid->next = NULL;

	//2. Recursive Sort
	a = mergeSort(a);
	b = mergeSort(b);

	//3. Merge
	return merge(a,b);
}
int main(){
	node* head = NULL;
	node*head2 = NULL;
	cin>>head;
	cout<<head;
	head = mergeSort(head);
	//insertInMiddle(head,3,2);
	//cout<<head;
	//node*mid = midPoint(head);
	//cout<<mid->data<<endl;
	//cin>>head2;
	//reverse(head);
	//reverse(head2);

	//cout<<head;
	//cout<<head2;

	//head = merge(head,head2);
	cout<<head;


	return 0;
}



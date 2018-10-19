#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	
	node(int d){
		data = d;
		next = NULL;
	}
};

//Functions for the linked list
void insertAtFront(node*&head,int d){

	node * n = new node(d);
	n->next = head;
	head = n;
}

void takeInput(node*&head){

	int d;
	cin>>d;

	while(d!=-1){
		insertAtFront(head,d);
		cin>>d;
	}
}
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;

}
// 1 Length
// 2 Insert 

int length(node *temp){
	int count = 0;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}


void insertAtTail(node*&head,int d){
	
	if(head==NULL){
		head = new node(d);
		return;
	}

	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new node(d);

return;
}

void insertInMiddle(node*&head,int d,int p){
	if(p==0){
		insertAtFront(head,d);
	}
	else if(p>=length(head)){
		insertAtTail(head,d);
	}
	else{
		int jump=1;
		node*prev = head;
		
		while(jump<=p-1){
			prev = prev->next;
			jump++;
		}

		node*n = new node(d);
		n->next= prev->next;
		prev->next = n;
	}
}
void deleteAtFront(node *&head){
	node*temp = head;
	if(temp!=NULL){
		head = head->next;
		delete temp;
	}
}

//-------------------------Midpoint #Ghoda
node* mid(node*head){
	node*slow = head;
	node*fast = head->next;

	while(fast!=NULL){
		fast = fast->next;
		
		if(fast!=NULL){
			fast = fast->next;
			slow  = slow->next;
		}
	}
	return slow;
}

void reverse(node*&head){
	if(head==NULL||head->next==NULL){
		return;
	}

	node*prev = NULL;
	node*current = head;
	node*N;
	while(current!=NULL){
		//Save the next node
		N = current->next;
		//Update the next of current node
		current->next = prev;

		//update prev & current
		prev = current;
		current = N;

	}
	head = prev;
}

// Search an element Recursively in the Linked List
bool search(node*head,int key){
	if(head==NULL){
		return false;
	}
	if(head->data == key){
		return true;
	}
	return search(head->next,key);
}

//-------------------------------- #Recursive #Reverse
node* recReverse(node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}

	//Otherwise ?

	node*chotaHead = recReverse(head->next);

	/* Choice 1. 
	node*temp = chotaHead;
	while(temp->next!=NULL){
		temp = temp->next;
	}

	temp->next = head;
	*/
	
	//Choice 2.
	head->next->next = head;


	head->next = NULL;
	return chotaHead;

}


int main(){

	node * head = NULL;
	takeInput(head);
	print(head);
	
	cout<<"Enter the data and position";
	int d,p;
	cin>>d>>p;
	insertInMiddle(head,d,p);
	print(head);
	head = recRe(head);
	print(head);

	//node* m = mid(head);
	//cout<<m->data<<endl;

	return 0;
}
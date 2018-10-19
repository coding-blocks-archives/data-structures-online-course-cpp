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

node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}

	node*c; //this points to new head(smaller element)
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}
node* mergeSort(node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	cout<<"In merge sort"<<endl;
	//Break down into parts
	node*m = mid(head);
	node*a = head;
	node*b = m->next;
	m->next = NULL;

	//MergeSort on smaller linked lists
	a = mergeSort(a);
	b = mergeSort(b);

	//Merge the sorted lists
	return merge(a,b);
}
bool isCyclic(node*head){
	node*slow = head;
	node*fast = head;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;

		if(fast==slow){
			cout<<"Cycle Found";
			break;
		}
	}
	slow = head;
	node*prev = head;
	
	while(prev->next!=fast){
		prev = prev->next;
	}

	while(slow!=fast){
		prev  = fast;
		slow = slow->next;
		fast = fast->next;
	}

	prev->next = NULL;
	
	return false;


}
node*getTail(node*temp){
	while(temp->next!=NULL){
		temp = temp->next;
	}
	return temp;
}

int main(){

	node * head = NULL;
	node*head2 = NULL;
	takeInput(head);
	print(head);

	node*tail = getTail(head);
	tail->next = head->next->next;

	//head = mergeSort(head);
	//print(head);
	isCyclic(head);
	print(head);

	return 0;
}
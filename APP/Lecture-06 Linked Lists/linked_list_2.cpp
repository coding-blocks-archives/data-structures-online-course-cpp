#include<iostream>
#include<stack>
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

void bubbleSort(node*&head){

	int n = length(head);

	for(int i=0;i<n-1;i++){

		node*current = head;
		node*prev = NULL;
		node*N;
		
		while(current!=NULL && current->next!=NULL){
			if(current->data > current->next->data){
				//Swapping
				if(prev==NULL){
					N = current->next;
					current->next = N->next;
					N->next = current;

					head = N;
					prev = N;
				}
				else{
					N = current->next;
					prev->next = N;
					current->next = N->next;
					N->next = current;
					prev = N;

				}
			}
			else{
				prev = current;
				current = current->next;
			}
		}
	}

}

node* recReverse(node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}

	
	node* chotaHead = recReverse(head->next);

	node* temp = chotaHead;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return chotaHead;
}

//Optimized Approach
node* recReverse2(node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}

	
	node* chotaHead = recReverse2(head->next);
	head->next->next = head;
	head->next = NULL;
	return chotaHead;
}

void findIntersectionOfLL(node*head1,node*head2){

	stack<node*> s1,s2;
	

	for(node*h1=head1;h1!=NULL;h1=h1->next){
		s1.push(h1);
	}
	for(node*h2=head2;h2!=NULL;h2=h2->next){
		s2.push(h2);
	}

	node* n;
	while(!s1.empty()&&!s2.empty()&&s1.top()==s2.top()){
		n = s1.top();
		s1.pop();
		s2.pop();
	}
	cout<<"Node is"<<(void*)n<<" and data is"<<n->data<<endl; 


}



int main(){
	node* head = NULL;
	node*head2 = NULL;
	cin>>head>>head2;
	cout<<head;

	//bubbleSort(head);
	head = recReverse2(head);
	cout<<head;

	cout<<head2;

	head2->next->next = head->next;

	cout<<head2;

	findIntersectionOfLL(head,head2);




	
	return 0;
}



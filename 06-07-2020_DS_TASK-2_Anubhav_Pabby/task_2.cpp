#include<iostream>
using namespace std;

// Creating a Node Class to create Nodes of the Linked-List
class Node{

public:

	int data;
	Node* next;

	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}

	// This functions belong to class and is used to print all nodes of linked-list
	static void print(Node* head) {

		while(head!=NULL){
			cout << head -> data << " ";
			head =  head -> next;
		}
		cout << endl;

	}

	// This Destructor is made to check whether the heap memory provided to Nodes is freed or Not
	~Node(){
		cout << "Destructor is called to deallocate Memory !" << endl;
	}


};

// This deleteList() deallocates the heap memory of all the nodes in the Linked-list
void deleteList(Node* head1,Node** ptrhead1){
	if(head1==NULL){
		return;
	}

	Node* temphead1 = head1;
	Node* tail = head1 -> next;

	while(temphead1!=NULL){
		temphead1 -> next = NULL;
		delete temphead1;
		
		temphead1 = tail;
		if(tail!=NULL){
			tail = tail -> next;
		}
	}

	*ptrhead1 = NULL;
}

// This function does not delete element if position is very much greater than the length of linked-list
// This function does not delete element if position is 0 or negative.
// This function assumes the position of first Node as 1.
Node* deleteNode(Node* head,int position){

	if(head == NULL){
		return head;
	}

	// It will return the same linked-list in which element is not deleted as position is 0 or negative.
	if(position <= 0){
		return head;
	}

	// It will also return the same linked-list in which element is not deleted if position is very much greater than the length of linked-list
	if(position!=1 && head==NULL){
		return head;
	}

	if(position==1 || (position==1 && head->next==NULL)){
		Node* tail = head -> next;
		head -> next = NULL;
		delete head;

		return tail;
	}

	Node* updatedHead = deleteNode(head -> next,position-1);
	head -> next = updatedHead;

	return head;
}

int main(int argc, char const *argv[]){

	Node* head = NULL;
	Node** ptrHead = &head;

	int data;
	cout << "Enter Data for First Node" << endl;
	cin >> data;
	Node* node1 = new Node(data);
	head = node1;

	cout << "Enter Data for Second Node" << endl;
	cin >> data;
	Node* node2 = new Node(data);
	node1 -> next = node2;

	cout << "Enter Data for Third Node" << endl;
	cin >> data;
	Node* node3 = new Node(data);
	node2 -> next = node3;

	cout << "Enter Data for Fourth Node" << endl;
	cin >> data;
	Node* node4 = new Node(data);
	node3 -> next = node4;

	cout << "printing Linked-List Before Deleting the Node" << endl;
	Node :: print(head);

	int position;
	cout << "Enter the position at which you want to delete the Node" << endl;
	cin >> position;

	// delete Node function modifies list and returns the updated head
	head = deleteNode(head,position);

	cout << "printing Linked-List Before Deleting the Node" << endl;
	Node :: print(head);

	deleteList(head,ptrHead);
	
	return 0;
}
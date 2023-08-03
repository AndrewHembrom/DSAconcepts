#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		
	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}
};

class MyLinkedList{
	Node* head;
	
	public:
		MyLinkedList(){
			head =NULL;
		}
		
		void printList();
		
		int search(int data);
		
		int size();
		
		void insertAtFirst(int data);
		
		void insertAtEnd(int data);
		
		void insert(int data, int position);
		
		void deleteFirstElement();
		
		void deleteLastElement();
		
		void deleteElement(int data);
		
		void reverseList();
		
		void deleteList();
	
};

void MyLinkedList :: printList(){
	if(head == NULL){
		cout<<"List is Empty"<<endl;
		return;
	}
	
	Node* temp = head;
	while(temp != NULL){
		cout<< temp->data << "->";
		temp = temp -> next;
	}
	cout<<" "<<endl;
}

int MyLinkedList :: search(int data){
	Node *ptr;
	ptr =head;
	int cnt = 1;
	while(ptr!=NULL){
		if(ptr->data == data){
			return cnt;
		}
		cnt++;
	}
	return -1;
}

int MyLinkedList :: size(){
	Node *ptr;
	ptr =head;
	int cnt = 1;
	while(ptr!=NULL){
		cnt++;
	}
	return cnt;
}

void MyLinkedList :: insertAtFirst(int data){
	Node* temp = new Node(data);
	temp -> next = head;
	head = temp;
}

void MyLinkedList :: insertAtEnd(int data){
	Node* newNode = new Node(data);
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp -> next;
	}
	temp -> next = newNode;
	
}

void MyLinkedList :: insert(int data, int position){
	if(position == 1){
		insertAtFirst(data);
		return;
	}
	
	Node* temp = head;
	int cnt =1;
	while (cnt<position-1){
		temp = temp->next;
		cnt++;
	}
	
	if(temp->next = NULL){
		insertAtEnd(data);
		return;
	}
	
	Node* nodeToInsert = new Node(data);
	nodeToInsert->next = temp -> next;
	temp->next = nodeToInsert;
}

void MyLinkedList :: deleteFirstElement(){
	Node* temp;
	if(head == NULL){
		return;
	}
	else{
		temp =head;
		head=temp->next;
		delete temp;
	}
}

void MyLinkedList :: deleteLastElement(){
	Node* prevTail, *tail;
	if(head == NULL){
		return; 
	}
	else if(head -> next == NULL){
		tail =head;
		head =NULL;
		delete tail;
	}
	else {
		prevTail = head;
		tail = prevTail -> next;
		while(tail->next!=NULL){
			prevTail = tail;
			tail = tail->next;
		}
		prevTail->next = NULL;
		delete tail;
	}
}

void MyLinkedList :: deleteElement(int data){
	Node *prevNode, *deleteNode;
	deleteNode = head;
	while((deleteNode->data != data) && (deleteNode!=NULL)){
		prevNode = deleteNode;
		deleteNode = deleteNode -> next;
	}
	if(deleteNode->data == data){
		prevNode->next = deleteNode->next;
		delete deleteNode;
	}
}

void MyLinkedList :: reverseList(){
	Node
}

int main(){
	MyLinkedList list;
	
	list.insertAtFirst(10);
	list.insertAtFirst(1);
	list.insertAtEnd(13);
	list.insertAtEnd(15);
	list.insertAtEnd(17);
	list.printList();
	list.deleteElement(13);
	list.printList();
	//list.insert(2, 45);
	cout<< list.search(13);
	list.printList();

	
	return 0;
}


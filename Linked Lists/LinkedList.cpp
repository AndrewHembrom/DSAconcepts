/*
Linked List is a linear dynamic datastructure which is made from a collection of nodes.
Node contains data and the addresss of the next node.
You can grow and shrink it at run time.
No continuous Memory Allocation.
*/

/*
Types of Linked Lists :-
1) Singly Linked List
2) Doubly Linked List
3) Circular Linked List
4) Circular Doubly Linked List
*/

#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{

    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPostion(Node *&head, Node *&tail, int position, int d)
{
    Node *temp = head;
    int cnt = 1;

    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "" << endl;
}

int main()
{

    Node *node1 = new Node(5);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // head pointed to node1;
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
    print(head);

    insertAtTail(tail, 21);
    print(head);

    insertAtPostion(head, tail, 3, 32);
    print(head);

    return 0;
}

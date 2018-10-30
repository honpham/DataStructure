// C++ program to demonstrate all insertion methods on Linked List
#include <iostream>

using namespace std;

// A linked list node
struct Node {
	int data;
	struct Node *next;
};

// Given a reference (pointer to pointer) to the head of a list
// and an int, inserts a new node on the front of the list.
void insertAtBegining(struct Node **aHeadRef, int aNewData) {
	// allocate node
	struct Node *newNode = new Node;
	// put in the data
	newNode->data = aNewData;
	// Make next of new node as head
	newNode->next = *aHeadRef;
	// Move the head to point to the new node
	*aHeadRef = newNode;
}

// Given a node aPreviousNode, insert a new node  after the given aPreviousNode
void insertAfterNode(struct Node *aPreviousNode, int aNewData) {
	// Check if the given aPreviousNode is NULL
	if (aPreviousNode == NULL) {
		cout << "The given previous node cannot be NULL" << endl;
		return;
	}
	// Allocate the new node
	struct Node *newNode = new Node;
	// put in the data
	newNode->data = aNewData;
	// Make next of new node as next of aPreviousNode
	newNode->next = aPreviousNode->next;
	// Move the next of aPreviousNode as newNode
	aPreviousNode->next = newNode;
}

// Given a reference (pointer to pointer) to the head of a list and int,
// appends a new node at the end
void insertAtEnd(struct Node **aHeadRef, int aNewData) {
	// Temp Node used in traverse the list till the last node
	struct Node *temp = *aHeadRef;
	// Allocate node
	struct Node *newNode = new Node;
	// Put in the data
	newNode->data = aNewData;
	// This new node is going to be the last node, so make next of it as NULL
	newNode->next = NULL;
	// If the Linked List is empty, then make new node as head
	if (*aHeadRef == NULL) {
		*aHeadRef = newNode;
		return;
	}
	// Else traverse till the last node
	while (temp->next != NULL) {
		temp = temp->next;
	}
	// Change the  next of last node
	temp->next = newNode;
	return;
}

// Utinity function to print contents of linked list starting from head
void printList(struct Node *nodeHead) {
	while (nodeHead != NULL) {
		cout << nodeHead->data << endl;
		nodeHead = nodeHead->next;
	}
}

// Driver program to test above functions
int main() {
	// Start with the empty list
	struct Node *head = NULL;
	// Insert 3, so linked list becomes 3->NULL
	insertAtEnd(&head, 3);
	// Insert 4 at the begining, so linked list becomes 4->3->NULL
	insertAtBegining(&head, 4);
	// Insert 5 after 4, so linked list becomes 4->5->3->NULL
	insertAfterNode(head, 5);
	printList(head);
	return 0;
}
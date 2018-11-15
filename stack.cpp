// C++ program for linked list implementation of stack
#include <iostream>
using namespace std;


// A class to represent a stack in linked list form.
class StackLinkedList {
private:
	int value;
	StackLinkedList *next;
public:

	bool push(StackLinkedList **aTop, int aValue) {
		StackLinkedList *newNode = new StackLinkedList;
		if (newNode == NULL)
			return false;
		newNode->value = aValue;
		newNode->next = *aTop;
		*aTop = newNode;
		return true;
	}

	bool isEmpty(StackLinkedList *aTop) {
		if (aTop == NULL)
			return true;
		else
			return false;
	}

	int pop(StackLinkedList **aTop) {
		if (aTop == NULL) {
			cout << "Stack Underflow";
			return -1;
		}

		StackLinkedList *temp = *aTop;
		*aTop = (*aTop)->next;
		int popped = temp->value;
		delete temp;
		return popped;
	}

	int getValueOfTop(StackLinkedList *aTop) {
		if (aTop == NULL) {
			cout << "Stack Underflow";
			return -1;
		}
		else
			return aTop->value;
	}

};

// Driver program to test above function;
int main() {
	StackLinkedList *root = NULL;
	root->push(&root, 10);
	root->push(&root, 20);
	root->push(&root, 30);

	cout << "Popped from stack: " << root->pop(&root) << endl;
	cout << "Top element is: " << root->getValueOfTop(root) << endl;
	return 0;
}

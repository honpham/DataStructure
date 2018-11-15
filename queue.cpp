// C++ program to implement queue using Linked List
#include <iostream>

using namespace std;

// A linked list node to store a queue entry
struct QueueNode {
	int data;
	QueueNode *next;
};

// The structure of the queue class
// The queue, front stores the front node of Linked list and rear stores  the last node of Linked list
class Queue {
private:
	QueueNode *front;
	QueueNode *rear;
public:
	// The function to add a noed with value is aData to queue
	void enqueue(int aData) {
		QueueNode *newNode = new QueueNode;
		if (newNode == NULL) {
			cout << "QUeue Overflow";
			return;
		}
		newNode->data = aData;
		newNode->next = NULL;
		// If queue is empty, then new node is front and rear both
		if (front == NULL) {
			front = newNode;
			rear = newNode;
			return;
		}
		// Add the new node at the end of queue and change rear
		rear->next = newNode;
		rear = rear->next;
	}

	// Function to remove a node from given queue
	int dequeue() {
		// If queue is empty then return -1
		if (front == NULL) {
			cout << "Queue Underflow";
			return -1;
		}
		// Store previous front and move front one node ahead
		QueueNode *temp = front;
		int poppedData = front->data;
		front = front->next;
		// If front becomes NULL, then change rear also as NULL
		if (front == NULL)
			rear = NULL;
		delete temp;
		return poppedData;
	}

	bool isEmpty() {
		if (front == NULL)
			return true;
		else
			return false;
	}

	QueueNode *getFrontNode() {
		return front;
	}
	QueueNode *getRearNode() {
		return rear;
	}
};

// Driver program to test above functions
int main() {
	Queue *queueTest = new Queue;
	queueTest->enqueue(10);
	queueTest->enqueue(20);
	queueTest->enqueue(30);
	queueTest->enqueue(40);
	cout << "Dequeued from queueTest : " << queueTest->dequeue() << endl;
	cout << "Front item is: " << (queueTest->getFrontNode())->data<< endl;
	cout << "Rear item is: " << (queueTest->getRearNode())->data << endl;
	return 0;
}

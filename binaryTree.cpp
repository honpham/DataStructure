// C++ program to demonstrate all methods with binary tree
#include <iostream>
#include <queue>

using namespace std;

// A binary tree node has key, pointer to left child and a pointer to right child
struct binaryTree {
	int key;
	struct binaryTree *left;
	struct binaryTree *right;
};

// Function to create a new node of tree and returns pointer of binaryTree
struct binaryTree *newNode(int aKey) 
{ 
	struct binaryTree *temp = new binaryTree; 
	temp->key = aKey; 
	temp->left = temp->right = NULL; 
	return temp; 
}; 

void inorder(struct binaryTree *aNode) {
	if (aNode == NULL)
		return;
	inorder(aNode->left);
	cout << aNode->key << " ";
	inorder(aNode->right);
}
// Function to insert element in binary tree
void insertInBinaryTree(struct binaryTree *aNode, int aKey) {
	queue <struct binaryTree*> q;
	q.push(aNode);

	// Do level order traversal until we find an empty place
	while (!q.empty()) {
		struct binaryTree *temp = q.front();
		q.pop();

		if (temp->left == NULL) {
			temp->left = newNode(aKey);
			break;
		}
		else
			q.push(temp->left);

		if (temp->right == NULL) {
			temp->right = newNode(aKey);
			break;
		}
		else
			q.push(temp->right);
	}
}

// Function to delete the given deepest and rightmost node in binary tree
void deleteDeepestRightmostNode(struct binaryTree *root, struct binaryTree *aDeepestRightmostNode) {
	queue<struct binaryTree*> q;
	q.push(root);

	// Do level order traversal until last node
	struct binaryTree *temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->right != NULL) {
			if (temp->right == aDeepestRightmostNode) {
				temp->right = NULL;
				delete aDeepestRightmostNode;
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left != NULL) {
			if (temp->left == aDeepestRightmostNode) {
				temp->left = NULL;
				delete aDeepestRightmostNode;
				return;
			}
			else
				q.push(temp->left);
		}
	}
}
// Function to delete element in binary tree
void deleteKeyNode(struct binaryTree *root, int aKey) {
	queue<struct binaryTree*> q;
	q.push(root);

	struct binaryTree *deepest_rightmost_node = NULL;
	struct binaryTree *keyNode = NULL;

	// Do level order traversal to find deepest and rightmost node
	// And node to be deleted
	while (!q.empty()) {
		deepest_rightmost_node = q.front();
		q.pop();

		if (deepest_rightmost_node->key == aKey)
			keyNode = deepest_rightmost_node;
		if (deepest_rightmost_node->left != NULL)
			q.push(deepest_rightmost_node->left);
		if (deepest_rightmost_node->right != NULL)
			q.push(deepest_rightmost_node->right);
	}

	//if (keyNode == root) {
	//	root = NULL;
	//	delete keyNode
	//}
	if (keyNode != NULL && deepest_rightmost_node != NULL) {
		keyNode->key = deepest_rightmost_node->key;
		deleteDeepestRightmostNode(root, deepest_rightmost_node);
	}
}

// Function to do level order traversal (breath first Traversal)
void breathFirstTraversal(struct binaryTree *root) {
	queue<struct binaryTree*> q;
	q.push(root);
	struct binaryTree *temp;

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		cout << temp->key << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}

// Given a binary tree, print its nodes according to the bottom-up postorder traversal
void postOrder(struct binaryTree *root) {
	if (root == NULL)
		return;
	// first recur on left subtree
	postOrder(root->left);
	// Then recur on right subtree
	postOrder(root->right);
	// Now deal with the node
	cout << root->key << " ";
}

// Given a binary tree, print its nodes in inorder
void inOrder(struct binaryTree *root) {
	if (root == NULL)
		return;
	// First recur on left subtree
	inOrder(root->left);
	// Then deal with the node
	cout << root->key << " ";
	// Now recur on right subtree
	inOrder(root->right);
}

// Given a binary tree, print its nodes in preorder
void preOrder(struct binaryTree *root) {
	if (root == NULL)
		return;
	// First deal with the node
	cout << root->key << " ";
	// Then recur on left subtree
	preOrder(root->left);
	// Now recur on right subtree
	preOrder(root->right);
}
// Driver function to test above functions
int main() {
	// Test breathFirstTraversal function
	/*struct binaryTree *root = newNode(1);
	root->left = newNode(2); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right = newNode(3); 
	cout << "Levl Order travelsal of binary tree is \n";
	breathFirstTraversal(root);*/

	// Test depth first traversal
	/*struct binaryTree *root = newNode(1); 
    root->left             = newNode(2); 
    root->right         = newNode(3); 
    root->left->left     = newNode(4); 
    root->left->right = newNode(5);  
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    preOrder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    inOrder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    postOrder(root);*/

	return 0;
}
//

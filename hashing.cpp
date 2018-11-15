// C++ program to implement hashing with chaining
#include <iostream>
#include <list>

using namespace std;

// Hash table size
#define TABLE_SIZE 13
// Used in second hash function
#define PRIME 7

class Hash {
	int bucket; // Number of buckets
	// Pointer to an array containing buckets
	list<int> *table;
public:
	Hash(int V); // Constructor function
	// Inserts a key into hash table
	void insertItem(int x);
	// Deletes a key from hash table
	void deleteItem(int key);
	// Hash function to map values to key
	int hashFunction(int x) {
		return (x % bucket);
	}

	void displayHash();
};

Hash::Hash(int b) {
	this->bucket = b;
	table = new list<int>[bucket];
}

void Hash::insertItem(int key) {
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key) {
	// Get the hash index of key
	int index = hashFunction(key);
	// Find the key in list
	list<int> :: iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == key)
			break;
	}
	// If key is found in hash table, remove it
	if (i != table[index].end())
		table[index].erase(i);
}

// Function to display hash table
void Hash::displayHash() {
	list<int> :: iterator l;
	for (int i = 0; i <bucket; i++) {
		cout << i << " ";
		for (l = table[i].begin(); l != table[i].end(); l++)
			cout << " --> " << *l;
		cout << endl;
	}
}


class DoubleHash {
	// Pointer to an array containing buckets
	int *hashTable;
	int curr_size;
public:
	// Function to check if hash table is full
	bool isFull() {
		// If hash size reaches maximum size
		return (curr_size == TABLE_SIZE);
	}

	// Function to calculate first hash
	int hash1(int key) {
		return (key % TABLE_SIZE);
	}
	// Function to calculate second hash
	int hash2(int key) {
		return (PRIME - (key % PRIME));
	}

	DoubleHash() {
		hashTable = new int[TABLE_SIZE];
		curr_size = 0;
		for (int i = 0; i < TABLE_SIZE; i++)
			hashTable[i] = -1;
	}

	// Function to insert key into hash table
	void insertHash(int key) {
		// If hash table is full
		if (isFull())
			return;
		// Get index from first hash
		int index = hash1(key);
		// If collision occurs
		if (hashTable[index] != -1) {
			// Get index 2 from second hash
			int index2 = hash2(key);
			int i = 1;
			while (1) {
				// Get newIndex
				int newIndex = (index + i*index2) % TABLE_SIZE;
				// If no collision occurs, store the key
				if (hashTable[newIndex] == -1) {
					hashTable[newIndex] = key;
					break;
				}
				i++;
			}
		}
		// If no collision occurs
		else
			hashTable[index] = key;
		curr_size++;
	}

	// Function to display the hash table
	void displayHash() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (hashTable[i] != -1)
				cout << i << " --> " << hashTable[i] << endl;
			else
				cout << i << endl;
		}
	}
};
// Driver program
int main() {
	// Test class Hash
	/*// Array that contains keys to be mapped
	int a[] = {15, 11, 27, 8, 12};
	int n = sizeof(a) / sizeof(a[0]);

	// Insert the keys into the hash table
	Hash h(7); // 7 is count of bucketsin hash table
	for (int i = 0; i < n; i++) {
		h.insertItem(a[i]);
	}
	// Delete 12 from hash table
	h.deleteItem(12);
	// Display the hash table
	h.displayHash();*/

	// Test class DoubleHash
	int a[] = {19, 27, 36, 10, 64};
	int n = sizeof(a) / sizeof(a[0]);
	// Inserting keys into hash table
	DoubleHash h;
	for (int i = 0; i < n; i++)
		h.insertHash(a[i]);
	// Display the hash table
	h.displayHash();
	
	return 0;
}

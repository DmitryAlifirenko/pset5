#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <cstdlib>
#include <string.h>
#define LENGTH 45
#define HASHMAP_SIZE 100000
using namespace std;


class HashMap {

private:
	struct Node {
		const char* word;
		Node *next;
	};
	Node* HashTable[HASHMAP_SIZE];
	int Hash(const char* word);

public:
	
	HashMap();
	~HashMap();
	void AddItem(const char* word);
	int NumberOfItemsInIndex(int index);
	void ShowTable();
	bool FindItem(const char* word);
	void RemoveItem(const char* word);
};

#endif /* HASHMAP_H */

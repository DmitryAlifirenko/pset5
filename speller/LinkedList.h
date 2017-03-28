#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class Node{

public:
	int data;
	Node *next;
	int index;

	int getData() const;
	void setData(int data);
	Node *getNext() const;
	void setNext(Node *next);
	
};

class LinkedList {

private:
	Node *head;
	int size;

public:
	LinkedList();
	void addNode(int data);
	void removeNode(int index);
	void showList();
	int getNode(int index);
	int getSize();
	~LinkedList();
};

#endif /* LINKEDLIST_H */

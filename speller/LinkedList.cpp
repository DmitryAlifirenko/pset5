#include "LinkedList.h"

using namespace std;

int Node::getData() const 
{
	return data;
}

void Node::setData(int data) 
{
	Node::data = data;
}

Node * Node::getNext() const
{
	return next;
}

void Node::setNext(Node *next) 
{
	Node::next = next;
}


LinkedList::LinkedList() 
{
	size = 0;
	head = NULL;
}

LinkedList::~LinkedList()
{
	delete[] head;
}

void LinkedList::addNode(int data)
{
	size++;
	Node* new_node = new Node;
	new_node->next = NULL;
	new_node->data = data;

	if (head != NULL) 
	{
		Node* current = head;
		while (current->next != NULL) 
		{
			current = current->next;
		}
		current->next = new_node;
		current->next->index = size;
	}
	else 
	{
		head = new_node;
		head->index = size;
	}
}

void LinkedList::removeNode(int index)
{
	Node* temp = head;
	Node* current = head;

	while (current != NULL && current->index != index) 
	{
		temp = current;
		current = current->next;
	}

	if (current == NULL) 
	{
		cout << index << "  There is no data with such index in this list" << endl;
		delete current;
	}
	else if (current == head) 
	{
		head = head->next;
	}
	else 
	{
		temp->next = current->next;
		delete current;
		size--;
	}

	
}

void LinkedList::showList()
{
	Node* current = head;

	while (current != NULL) 
	{
		cout << current->data  << endl;
		current = current->next;
	}
	delete current;
}

int LinkedList::getNode(int index)
{
	Node* current = head;
	while (current->next != NULL) {
		if (current->index == index) {
			return current->data;
		}
		else {
			current = current->next;
		}
	}	
	return 0;
}

int LinkedList::getSize()
{
	return size;
}



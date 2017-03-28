#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <string.h>

using namespace std;

class ArrayList {

private:

	int *array;
	int *newarray;
	int size;
	int multipliyer;
	int allocated;

public:

	ArrayList();
	~ArrayList();
	void add(int data);
	void remove(int index);
	int get(int index);
	void show();
	int sizeofArray();
	
};
#endif /* ARRAYLIST_H */

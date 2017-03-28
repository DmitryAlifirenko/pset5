#include "ArrayList.h"

using namespace std;

ArrayList::ArrayList() 
{
	allocated = 10;
	array = new int [allocated];
	multipliyer = 2;
}

ArrayList::~ArrayList()
{
	delete[] array;
}

void ArrayList::add(int data)
{
	if (size >= allocated)
	{
		allocated *= multipliyer;

		newarray = new int[allocated];

		memcpy(newarray, array, sizeof(int) * size);

		array = newarray;

		array[size] = data;
		size++;
	}
	else
	{
		array[size] = data;
		size++;
	}
}

void ArrayList::remove(int index)
{
	while (index <= size) 
	{
		array[index] = array[index + 1];
		index++;
	}
	--size;
}

int ArrayList::get(int index)
{
	return array[index];
}

void ArrayList::show()
{
	for (int i = 0; i < allocated; i++) 
	{
		cout << array[i] << "  ";
	}
}

int ArrayList::sizeofArray()
{
	return size;
}

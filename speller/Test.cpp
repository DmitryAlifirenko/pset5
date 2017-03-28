#include "ArrayList.h"
#include "LinkedList.h"
#include "HashMap.h"

void ArrayListTest() {
	ArrayList a;
	for (int i = 0; i < 20; i++) {
		a.add(i);
	}
	a.remove(3);
	a.add(20);
	a.add(15);
	a.show();
	cout << endl << a.get(8) << endl;
	cout << "Array Size " << a.sizeofArray() << endl;
}

void LinkedListTest() {
	LinkedList a;
	for (int i = 1; i <= 10; i++) {
		a.addNode(i);
	}

	a.removeNode(7);
	a.addNode(20);
	a.showList();

	a.removeNode(7);
	a.showList();

	cout << "List Size: " << a.getSize() << endl;
	cout << a.getNode(8) << endl;
}

void HashMapTest() {
	HashMap Hashy;
	Hashy.AddItem("Computer");
	Hashy.AddItem("pumoCrte");
	Hashy.AddItem("Bot");
	Hashy.AddItem("Calstraasoksafkfaskfasfk");
	Hashy.RemoveItem("Computer");
	Hashy.ShowTable();
	Hashy.FindItem("Bot");
	Hashy.FindItem("Computer");

}

int main() {
	//ArrayListTest();
	HashMapTest();
	//LinkedListTest();
	system("pause");
	return 0;
}

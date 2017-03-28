#include "HashMap.h"

HashMap::HashMap()
{
	for(int i = 0; i < HASHMAP_SIZE; i++)
	{
		HashTable[i] = new Node;
		HashTable[i]->word = NULL;
		HashTable[i]->next = NULL;
	}
}

HashMap::~HashMap()
{
	Node* temp;
    Node* temp_next;
    for(int i = 0; i < HASHMAP_SIZE; i++) 
	{ 
        temp = HashTable[i];
        while(NULL != temp) 
		{
            temp_next = temp->next;
            delete temp;
            temp = temp_next;
        } 
        HashTable[i] = NULL;
    }
	
}

int HashMap::Hash(const char* key)
{
	int hash = 0;
	int n;
	for (int i = 0; key[i] != '\0'; i++)
	{
		// alphabet case
		if (isalpha(key[i]))
			n = key[i] - 'a' + 1;

		// comma case
		else
			n = 27;

		hash = ((hash << 3) + n) % HASHMAP_SIZE;
	}
	return hash;
}

void HashMap::AddItem(const char* word)
{
	Node* new_word = new Node;
	new_word->word = word;

	int index = Hash(word);
        
        
    if (HashTable[index]->word == NULL)
    {
        HashTable[index] = new_word;
        new_word->next = NULL;
    }

    else
    {
        new_word->next = HashTable[index];
        HashTable[index] = new_word;
    }   
    //cout << HashTable[index]->word << " | " << index << " | " << NumberOfItemsInIndex(index) << endl;
}

int HashMap::NumberOfItemsInIndex(int index)
{
	int count = 0;
	Node* cursor = new Node;
	
	if (HashTable[index]->word == NULL)
	{
		return count;
	}
	else
	{
		count++;
		cursor = HashTable[index];
		while (cursor->next != NULL)
		{
			count++;
			cursor = cursor->next;
		}
	}
	return count;
}

/*void HashMap::ShowTable()
{
	int number;
	for (int i = 0; i < HASHMAP_SIZE; i++) 
	{
		number = NumberOfItemsInIndex(i);
		cout << "----------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->word << endl;
		cout << "N of items " << number << endl;
		cout << "----------------------\n";	
	}
}*/

bool HashMap::FindItem(const char * word)
{
	int index = Hash(word);

	//Временный поиск
	if (HashTable[index]->word != NULL)
	{
		return  true;
	}

	//Должен работать этот
	/*Node* cursor = HashTable[index];
	while (cursor != NULL)
	{
		if (cursor->word == word)
		{
			//cout << word << " | was found in the Hash Table!" << endl;
			return true;
		}
		cursor = cursor->next;
	}*/

	return false;
}

void HashMap::RemoveItem(const char * word)
{
	int index = Hash(word);

	if (HashTable[index] == NULL)
	{
		//cout << word << " was not fount in the Hash Table" << endl;
	}
	else if (HashTable[index]->word == word)
	{
		while (HashTable[index] != NULL)
		{
			Node* delPtr = new Node;
			delPtr = HashTable[index];
			HashTable[index] = HashTable[index]->next;
			delete delPtr;
		}
		//cout << word << " was removed from the Hash Table" << endl;
	}
}


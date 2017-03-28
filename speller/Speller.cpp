#include "dictionary.h"

// default dictionary
#define DICTIONARY "dictionaries/large"



int main(int argc, char *argv[])
{
    // check for correct number of args
    if (argc != 2 && argc != 3)
    {
        printf("Usage: speller [dictionary] text\n");
        return 1;
    }
    
    // determine dictionary to use
    const char* dictionary = (argc == 3) ? argv[1] : DICTIONARY;
    
    // try to open text
    char *text = (argc == 3) ? argv[2] : argv[1];

	Dictionary obj;
	obj.LoadDictionary(dictionary);
    	obj.OpenAndCheckText(text);
	obj.DictionarySize();
	obj.UnloadDictionary();
	obj.Benchmarks();
	
    // that's all folks
    return 0;
}



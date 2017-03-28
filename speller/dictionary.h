/**
* Declares a dictionary's functionality.
*/
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "HashMap.h"

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>

#undef calculate
#undef getrusage


#define LENGTH 45

class Dictionary {

private:
	
	HashMap HashTable;
	unsigned int dictionary_size;
	
	// structs for timing data
	struct rusage before, after;

	// benchmarks
    	double time_load, time_check, time_size, time_unload;

	int index, misspellings, words;

	// prototype
	double calculate(const struct rusage *b, const struct rusage *a);
	bool check(const char *word);
	bool load(const char *dictionary);
	unsigned int size(void);
	bool unload(void);

	
public:
	

	Dictionary();
	void LoadDictionary(const char* dictionary);
	void OpenAndCheckText(char* text);
	void DictionarySize();
	void UnloadDictionary();
	void Benchmarks();
	
	
	
};
#endif // DICTIONARY_H

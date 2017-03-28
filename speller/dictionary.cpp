/**
* Implements a spell-checker.
*/
#include "dictionary.h"
#include "HashMap.h"


Dictionary::Dictionary()
{
	HashMap HashTable;
	dictionary_size = 0;
	index = 0;
	misspellings = 0;
	words = 0;
	time_load = 0.0; 
	time_check = 0.0; 
	time_size = 0.0;
	time_unload = 0.0;
}


/*---------------------------Private Functions-------------------*/
bool Dictionary::load(const char *dictionary)
{
	FILE* input = fopen(dictionary, "r");
	if (input == NULL)
	{
		return false;
	}
		

	char word[LENGTH + 1] ={};

	while (!feof(input))
	{
		fscanf(input, "%s\n", word);
		HashTable.AddItem(word);
		dictionary_size++;
	}
	fclose(input);
	return true;
}


bool Dictionary::check(const char *word)
{
	char check_word[LENGTH + 1] = {};

	int len = strlen(word);

	for (int i = 0; i < len; i++)
	{
		check_word[i] = tolower(word[i]);
	}

	check_word[len] = '\0';

 	return HashTable.FindItem(check_word); 
}


unsigned int Dictionary::size(void)
{
	if (dictionary_size > 0)
	{
		return dictionary_size;
	}
	else
	{
		return 0;
	}
}


bool Dictionary::unload(void)
{
	HashTable.~HashMap();

	return true;
}


double Dictionary::calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}
/*---------------------------------------------------------------*/



/*-------------------------Public Functions---------------------*/
void Dictionary::LoadDictionary(const char* dictionary)
{
	// load dictionary
    getrusage(RUSAGE_SELF, &before);
    bool loaded = this->load(dictionary);
    getrusage(RUSAGE_SELF, &after);

    // abort if dictionary not loaded
    if (!loaded)
    {
        printf("Could not load %s.\n", dictionary);
        //return 1;
    }

    // calculate time to load dictionary
    time_load = calculate(&before, &after);
}


void Dictionary::OpenAndCheckText(char* text)
{
	FILE *fp = fopen(text, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", text);
        this->unload();
        //return 1;
    }

    // prepare to report misspellings
    printf("\nMISSPELLED WORDS\n\n");

    // prepare to spell-check
    char word[LENGTH+1];

    // spell-check each word in text
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        // allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // append character to word
            word[index] = c;
            index++;

            // ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // consume remainder of alphabetical string
                while ((c = fgetc(fp)) != EOF && isalpha(c));

                // prepare for new word
                index = 0;
            }
        }

        // ignore words with numbers (like MS Word can)
        else if (isdigit(c))
        {
            // consume remainder of alphanumeric string
            while ((c = fgetc(fp)) != EOF && isalnum(c));

            // prepare for new word
            index = 0;
        }

        // we must have found a whole word
        else if (index > 0)
        {
            // terminate current word
            word[index] = '\0';

            // update counter
            words++;

            // check word's spelling
            getrusage(RUSAGE_SELF, &before);
           	bool misspelled = !this->check(word);
            getrusage(RUSAGE_SELF, &after);

            // update benchmark
            time_check += calculate(&before, &after);

            // print word if misspelled
            if (misspelled)
            {
                printf("%s\n", word);
                misspellings++;
            }

            // prepare for next word
            index = 0;
        }
    }

    // check whether there was an error
    if (ferror(fp))
    {
        fclose(fp);
        printf("Error reading %s.\n", text);
        this->unload();
        //return 1;
    }

    // close text
    fclose(fp);
}


void Dictionary::DictionarySize()
{
	// determine dictionary's size
    getrusage(RUSAGE_SELF, &before);
    this->size();
    getrusage(RUSAGE_SELF, &after);

    // calculate time to determine dictionary's size
    time_size = calculate(&before, &after);
}


void Dictionary::UnloadDictionary()
{
	// unload dictionary
    getrusage(RUSAGE_SELF, &before);
    bool unloaded = this->unload();
    getrusage(RUSAGE_SELF, &after);

    // abort if dictionary not unloaded
    if (!unloaded)
    {
        printf("Could not unload \n");
        //return 1;
    }

    // calculate time to unload dictionary
    time_unload = calculate(&before, &after);
}


void Dictionary::Benchmarks()
{
	// report benchmarks
    printf("\nWORDS MISSPELLED:     %d\n", misspellings);
    printf("WORDS IN DICTIONARY:  %d\n", dictionary_size);
    printf("WORDS IN TEXT:        %d\n", words);
    printf("TIME IN load:         %.2f\n", time_load);
    printf("TIME IN check:        %.2f\n", time_check);
    printf("TIME IN size:         %.2f\n", time_size);
    printf("TIME IN unload:       %.2f\n", time_unload);
    printf("TIME IN TOTAL:        %.2f\n\n", 
     time_load + time_check + time_size + time_unload);
}
/*---------------------------------------------------------------*/

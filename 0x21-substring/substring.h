#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct Trie - Dictionnary
 * @string: str
 * @index: length of str
 */
typedef struct Dict
{
	char *string;
	int occurence;
} Dict;

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif

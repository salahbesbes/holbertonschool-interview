#include "substring.h"

/**
 * freeArry - free Array
 *
 * @arr: array of strigns
 * @len: length of array
 */
void freeArry(Dict **arr, int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		free(arr[i]->string);
		free(arr[i]);
	}
}

/**
 * CheckArraysAreEqual - check fi the content of arrays are same
 *
 * @ar1: array of strigns
 * @ar2: array of strigns
 * @len: length of array same
 * Return: 1 if all content of one array exist in the other oner
 */
int CheckArraysAreEqual(Dict **ar1, Dict **ar2, int len)
{
	int i, j, dictExist;

	for (i = 0; i < len; i++)
	{

		for (j = 0; j < len; j++)
		{
			dictExist = strcmp(ar1[i]->string, ar2[j]->string);

			if (dictExist == 0)
			{
				if (ar1[i]->occurence == ar2[j]->occurence)
				{
					break;
				}
				dictExist = -1;
			}
			else
				dictExist = -1;
		}
		if (dictExist == -1)
			return (0);
	}
	return (1);
}
/**
 * getSubstring - check fi the content of arrays are same
 *
 * @s: original strign
 * @i:  start index of the substring
 * @limit: length of the substring
 * Return: return substring
 */
char *getSubstring(char const *s, int i, int limit)
{
	char *substring;

	substring = malloc(limit - i + 1);
	memcpy(substring, &s[i], limit - i);
	substring[limit - i] = '\0';

	return (substring);
}

Dict *TryToAddToArray(Dict **arr, char *ref, int index)
{
	int i = 0;
	Dict *newDict;

	newDict = malloc(sizeof(Dict));
	newDict->string = ref;
	newDict->occurence = 1;
	for (i = 0; i < index; i++)
	{
		if (strcmp(arr[i]->string, ref) == 0)
		{
			newDict->occurence++;
			arr[i]->occurence++;
			return (newDict);
		}
	}
	return (newDict);
}

/**
 * find_substring - finds substring composed of all concatenated words
 * @s: the string to search
 * @words: array of contentated words to find
 * @nb_words: the size of passed array
 * @n: size of return array, to set
 * Return: array of indices where all words found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, i, j, k, *indices, lengthOfFirst, lengthOfAlllCombined;
	char *currentSubString, *substring;
	Dict **wordCount, **secondCount;

	indices = calloc(0, sizeof(int));
	if (s == NULL || *s == '\0' || words == NULL)
		return (indices);
	wordCount = malloc(nb_words * sizeof(Dict));
	secondCount = malloc(nb_words * sizeof(Dict));
	for (i = 0; i < nb_words; i++)
	{
		wordCount[i] = TryToAddToArray(wordCount, strdup(words[i]), i);
	}
	lengthOfFirst = strlen(words[0]);
	lengthOfAlllCombined = nb_words * lengthOfFirst;
	s_len = strlen(s);
	for (i = 0; i <= s_len - lengthOfAlllCombined; i++)
	{
		currentSubString = getSubstring(s, i, i + lengthOfAlllCombined);
		j = 0;
		for (k = 0; k < nb_words; k++)
		{
			substring = getSubstring(currentSubString, j, j + lengthOfFirst);

			secondCount[k] = TryToAddToArray(secondCount, substring, k);
			j += lengthOfFirst;
		}
		if (CheckArraysAreEqual(wordCount, secondCount, nb_words))
		{
			indices[*n] = i;
			(*n)++;
		}
		freeArry(secondCount, nb_words);
		free(currentSubString);
	}
	freeArry(wordCount, nb_words);
	free(wordCount);
	free(secondCount);
	return (indices);
}

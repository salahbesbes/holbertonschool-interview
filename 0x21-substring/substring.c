#include "substring.h"

/**
 * compaiarString- compaire 2strings
 *
 * @s1: first str
 * @s2: second str
 * Return: 1 if same else 0
 */
int compaiarString(char *s1, char const *s2)
{
	int i, len;

	for (len = 0; s1[len]; len++)
		;
	for (i = 0; i < len; i++)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
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
		if (arr[i] != NULL)
			free(arr[i]->string);
		free(arr[i]);
	}
}
/**
 * stringExistInArray - check if dic exis in the array
 *
 * @ar2: array of strigns
 * @ar1: array of strigns
 * @pos: index of the string in the array
 * @len: length of array
 * Return: true or false
 */
int stringExistInArray(Dict **ar2, Dict **ar1, int pos, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (compaiarString(ar2[pos]->string, ar1[i]->string))
		{
			if (ar1[pos]->occurence == ar2[i]->occurence)
				return (1);
		}
	}
	return (0);
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
	int i;

	for (i = 0; i < len; i++)
	{

		if (!stringExistInArray(ar2, ar1, i, len))
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

Dict *TryToAddToArray(Dict **arr, char const *ref, int index)
{
	int i = 0;
	Dict *newDict;

	newDict = malloc(sizeof(Dict));
	newDict->string = strdup(ref);
	newDict->occurence = 1;
	for (i = 0; i < index; i++)
	{
		if (compaiarString(arr[i]->string, ref))
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

	indices = malloc(sizeof(int));
	if (s == NULL || *s == '\0' || words == NULL)
		return (indices);
	wordCount = malloc(nb_words * sizeof(Dict));
	secondCount = malloc(nb_words * sizeof(Dict));
	for (i = 0; i < nb_words; i++)
	{
		wordCount[i] = TryToAddToArray(wordCount, words[i], i);
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
			(*n)++;
			indices = realloc(indices, sizeof(int) * (*n));
			indices[*n - 1] = i;
		}
		freeArry(secondCount, nb_words);
		free(currentSubString);
	}
	freeArry(wordCount, nb_words);
	free(wordCount);
	free(secondCount);
	return (indices);
}

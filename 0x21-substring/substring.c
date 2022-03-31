#include "substring.h"

int compaiarString(char *s1, char *s2, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
void freeArry(char **arr, int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] != NULL)
			free(arr[i]);
	}
}
int stringExistInArray(char *str, char **arr, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (compaiarString(str, arr[i], 3))
			return (1);
	}
	return (0);
}

int CheckArraysAreEqual(char **ar1, char **ar2, int len)
{
	int i, j, stringlen, strExistinArray;

	for (stringlen = 0; ar1[0][stringlen]; stringlen++)
		;
	for (i = 0; i < len; i++)
	{

		for (j = 0; j < len; j++)
		{
			strExistinArray = compaiarString(ar1[i], ar2[j], stringlen);
			if (strExistinArray == 1)
				break;
		}

		if (strExistinArray == 0)
			return (0);
	}
	return (1);
}

char *getSubstring(char const *s, int i, int limit)
{
	char *substring;

	substring = malloc(limit - i + 1);
	memcpy(substring, &s[i], limit - i);
	substring[limit - i] = '\0';

	return (substring);
}
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, i, j, k, *indices, lengthOfFirst, lengthOfAlllCombined;
	char **wordCount, *currentSubString, **secondCount, *substring;

	indices = malloc(sizeof(int));
	if (s == NULL || *s == '\0' || words == NULL)
		return (indices);
	wordCount = malloc(nb_words * sizeof(char *));
	secondCount = malloc(nb_words * sizeof(char *));
	for (i = 0; i < nb_words; i++)
		wordCount[i] = strdup(words[i]);
	lengthOfFirst = strlen(words[0]);
	lengthOfAlllCombined = nb_words * lengthOfFirst;
	s_len = strlen(s);
	for (i = 0; i <= s_len - lengthOfAlllCombined; i++)
	{
		currentSubString = getSubstring(s, i, i + lengthOfAlllCombined);
		j = 0;
		for (k = 0; k < nb_words; k++)
		{
			/* Divide the current string into strings of length of */
			/* each word in the array */
			substring = getSubstring(currentSubString, j, j + lengthOfFirst);
			/* Put this string into the wordMap */
			secondCount[k] = substring;
			/* Update j and index */
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

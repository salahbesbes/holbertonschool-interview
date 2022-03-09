#include "holberton.h"

/**
 * checkCharExist - checkCharExist in some string
 *
 * @string: string
 * @ch: char
 *
 * Return: 1 if exist else 0
 */
int checkCharExist(char *string, char ch)
{
	if (*string == '\0')
		return (0);
	else if (*string == ch)
		return (1);
	return (checkCharExist(string + 1, ch));
}
/**
 * searchChar - searchChar search for the char in some string and
 * return the last index of that char
 *
 * @string: string
 * @ch: char
 * @lastIndex: last index of the char found
 *
 * Return: return the index of the char else 0
 */
int searchChar(char *string, char ch, int lastIndex)
{
	int tmp = 0;

	if (*string == '\0')
		return (lastIndex);
	if (*string == ch)
	{
		tmp = searchChar(string + 1, ch, lastIndex);
		if (checkCharExist(string + 1, ch))
		{
			return (tmp + 1);
		}
		return (lastIndex);
	}
	else if (*string != ch)
	{
		return (searchChar(string + 1, ch, lastIndex + 1));
	}

	return (lastIndex);
}
/**
 * ignoringStarts - ignore all "*" char and stop on the next char
 *
 * @string: string
 *
 * Return: the number of steps needed to found first char not "*"
 */
int ignoringStarts(char *string)
{
	if (*string == '*')
	{
		return (1 + ignoringStarts(string + 1));
	}
	return (0);
}
/**
 * wildcmp -  compares two strings and returns 1 if the strings
 * can be considered identical, otherwise return 0
 *
 * @s1: string
 * @s2: string 2 with * as jocker Char
 *
 * Return: 1 if equal else 0
 */
int wildcmp(char *s1, char *s2)
{

	int indx = 0, i = 0;

	if (s2 == NULL || s1 == NULL)
		return (0);
	if (*s2 == '*')
	{
		indx = ignoringStarts(s2);
		s2 = s2 + indx;

		i = searchChar(s1, *s2, 0);
		s1 = s1 + i;

		wildcmp(s1, s2);
	}

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	else
		return (0);
}

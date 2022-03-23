#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches
 * a given string
 * @str: the given string
 * @pattern: the given pattern
 * Return: 1 if the pattern matches the string, or
 * 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	if (str == NULL || pattern == NULL)
		return (0);
	if (*str == '\0' && (*pattern == '\0' || *(pattern + 1) == '\0'))
		return (1);
	if (*str == *pattern)
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
		return (regex_match(str, pattern + 1));
	if (pattern[0] == '*')
	{
		if (pattern[1] == '*')
			return (regex_match(str, pattern + 1));
		if (pattern[1] == '\0')
			return (regex_match(str + 1, pattern));
		if (regex_match(str + 1, pattern))
			return (1);
		else
			return (regex_match(str, pattern + 1));
	}

	if (pattern[0] == '.')
	{
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}

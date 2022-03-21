#include "regex.h"

/**
 * regex_match - regex search
 *
 * @str: string with no "*" or "."
 * @pattern: pattern
 *
 * Return: 1 if found else 0
 */
int regex_match(char const *str, char const *pattern)
{
	if (str == NULL || pattern == NULL)
		return (0);

	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*str == *pattern)
		return (regex_match(str + 1, pattern + 1));
	else if (*(pattern + 1) == '*')
		return (regex_match(str, pattern + 1));
	if (*pattern == '*')
	{
		if (*(pattern + 1) == '*')
			return (regex_match(str, pattern + 1));

		if (regex_match(str + 1, pattern))
			return (1);
		else
			return (regex_match(str, pattern + 1));
	}

	if (*pattern == '.')
	{

		return (regex_match(str + 1, pattern + 1));
	}
	return (0);
}

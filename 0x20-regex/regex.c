#include "regex.h"

int searchforChar(const char *str, char ch, int index)
{
	if (ch == '\0' || *str == '\0')
		return (-1);
	if (*str == ch)
		return (index + 1);
	return (searchforChar(str + 1, ch, index + 1));
}

/**
 * recheckString - checks whether a given pattern matches
 * a given string
 * @str: the given string
 * @pattern: the given pattern
 * Return: 1 if the pattern matches the string, or
 * 0 if it doesn’t
 */
int recheckString(char const *str, char const *pattern, char const *original)
{
	printf("str %s, pattern %s \n", str, pattern);
	if (str == NULL || pattern == NULL)
		return (0);
	if (*str == '\0' && (*pattern == '\0' || *(pattern + 1) == '\0'))
		return (1);
	if (*pattern == '\0')
		return (0);
	if (*str == *pattern)
		return (recheckString(str + 1, pattern + 1, original));

	if (pattern[0] == '*')
	{
		if (pattern[1] == '*')
			return (recheckString(str, pattern + 1, original));
		if (pattern[1] == str[0])
			return recheckString(str, pattern + 1, original);
		if (recheckString(str + 1, pattern, original))
			return (1);
		else
			return (recheckString(original, pattern, original));
	}

	if (pattern[0] == '.')
	{
		return (recheckString(str + 1, pattern + 1, original));
	}

	if (pattern[1] == '*')
	{
		return (recheckString(str, pattern + 1, original));
	}

	return (0);
}
int regex_match(char const *str, char const *pattern)
{
	return (recheckString(str, pattern, str));
}

#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

#define TEST_MATCH(s, p)                                      \
	do                                                    \
	{                                                     \
		{                                             \
			int res = regex_match(s, p);          \
			printf("%s -> %s = %d  ", s, p, res); \
		}                                             \
	} while (0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	TEST_MATCH("Holberton", "holberton");
	printf("expected (0) \n");

	TEST_MATCH("H", "H");
	printf("expected (1) \n");
	TEST_MATCH("HH", "H");
	printf("expected (0) \n");

	TEST_MATCH("HH", "H*");
	printf("expected (1) \n");

	TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");
	printf("expected (1) \n");

	TEST_MATCH("Holberton", ".*");
	printf("expected (1) \n");

	TEST_MATCH("Alex", ".*");
	printf("expected (1) \n");

	TEST_MATCH("Guillaume", ".*");
	printf("expected (1) \n");

	TEST_MATCH("Julien", ".*");
	printf("expected (1) \n");

	TEST_MATCH("Holberton", "Z*H.*"); //
	printf("expected (1) \n");

	TEST_MATCH("Holberton", "Z*H.*olberton"); //
	printf("expected (1) \n");

	TEST_MATCH("Holberton", "Z*H.*o."); //
	printf("expected (1) \n");

	TEST_MATCH("Holberton", "Z*H.*o");
	printf("expected (0) \n");

	TEST_MATCH("Holberton", ".olberton");
	printf("expected (1) \n");

	TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");
	printf("expected (1) \n");

	return (EXIT_SUCCESS);
}

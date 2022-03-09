#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = wildcmp("main-main.c", "ma*in.c");
	printf("%d\n", r);
	return (0);
}

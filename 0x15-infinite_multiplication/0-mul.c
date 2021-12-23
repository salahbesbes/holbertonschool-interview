#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
/**
 * reverse - inverse an array
 *
 * @arr: array
 * @n: length
 */
void reverse(char arr[], int n)
{
	int aux[n], i;

	for (i = 0; i < n; i++)
	{
		aux[n - 1 - i] = arr[i];
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = aux[i];
	}
}
/**
 * printResult- print a readable string from array
 *
 * @arr: Result Array
 * @length: length of array
 */
void printResult(char *arr, int length)
{
	int i = 0;

	if (arr[0] == 0)
		i = 1;

	for (; i < length; i++)
	{
		if (arr[i] >= 0 && arr[i] <= 9)
			putchar(arr[i] + '0');
		else
			putchar(arr[i]);
	}
	putchar('\n');
}
/**
 * string_length - length of string
 *
 * @pointer: string
 * Return: int
 */
int string_length(char *pointer)
{
	int c = 0;

	for (c = 0; pointer[c] != '\0'; c++)
	{
		if (pointer[c] < '0' || pointer[c] > '9')
		{
			return (-1);
		}
	}
	return (c);
}

/**
 * multiply - multiply 2 strings
 *
 * @n1: string1
 * @n1L:  length str1
 * @n2:  string 2
 * @n2L:  length str2
 * @res:  Result Array array
 */
void multiply(char *n1, int n1L, char *n2, int n2L, char *res)
{
	int i, j, digit;

	for (i = 0; i < n1L; i++)
	{
		for (j = 0; j < n2L; j++)
		{
			digit = (n1[i] - '0') * (n2[j] - '0');
			res[i + j] += digit;
			res[i + j + 1] += res[i + j] / 10;
			res[i + j] = (res[i + j] % 10);
		}
	}
}
/**
 * main - check the code
 * @argc: nb of argument
 * @argv: list of argumets(strings)
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{

	char *arg1 = argv[1], *arg2 = argv[2];
	int n1L, n2L, i;
	char *n1, *n2, *res;

	if (argc != 3)
	{
		printResult("Error", 5);
		exit(98);
	}
	n1L = string_length(arg1);
	n2L = string_length(arg2);
	if (n1L == -1 || n2L == -1)
	{
		printResult("Error", 5);
		exit(98);
	}
	if ((n1L == 1 || n2L == 1) && (*arg1 == '0' || *arg2 == '0'))
	{
		printResult("0", 1);
		return (0);
	}
	n1 = malloc(sizeof(int) * n1L);
	n2 = malloc(sizeof(int) * n2L);
	res = malloc(sizeof(int) * (n1L + n2L));
	for (i = 0; i < n1L; i++)
		n1[i] = arg1[i];
	for (i = 0; i < n2L; i++)
		n2[i] = arg2[i];
	reverse(n1, n1L);
	reverse(n2, n2L);
	for (i = 0; i < (n1L + n2L); i++)
		res[i] = 0;
	multiply(n1, n1L, n2, n2L, res);
	reverse(res, n1L + n2L);
	printResult(res, n1L + n2L);
	free(n1);
	free(n2);
	free(res);
	return (0);
}

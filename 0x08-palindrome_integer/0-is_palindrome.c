#include "palindrome.h"
#include <stdio.h>

/**
 * get_multiplier - calculate the length of the number
 * @n: any number
 *
 * Return: int
 */
int get_multiplier(unsigned long n)
{
	int mul = 1;

	while (n >= 10)
	{
		mul *= 10;
		n /= 10;
	}

	return (mul);
}

/**
 * is_palindrome - recursiive way, compaire first and last digit then,
 * if they are equal check the new number between them
 * @n: any number
 *
 * Return: 1 if is palindromique else 0
 */
int is_palindrome(unsigned long n)
{

	int first_digit, last_digit, mul, new_digit;

	mul = get_multiplier(n);

	first_digit = n / mul;
	last_digit = n % 10;

	printf("n =  %ld mul = %d\n", n, mul);

	if (first_digit != last_digit)
		return (0);

	/*
	 * if the number length is 2 digit long or less
	 * we dont want to ckeck any more
	*/
	if (mul <= 100)
		return (1);

	new_digit = (n - (first_digit * mul));

	new_digit = new_digit / 10;

	return (is_palindrome(new_digit));
}

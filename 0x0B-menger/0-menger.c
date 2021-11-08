#include "menger.h"

/**
 * printSymbol - Function that decides if must print a
 * symbol or a space.
 * @x: rows
 * @y: columns
 * Return: 0 if it's a symbol or 1 if it's a space
 */
int printSymbol(int x, int y)
{
	while (x && y)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x = x / 3;
		y = y / 3;
	}
	return (1);
}

/**
 * menger - Function that draws a 2D Menger Sponge
 * @level:  is the level of the Menger Sponge to draw
 * Return: void
 */
void menger(int level)
{
	int x, y, size;

	size = pow(3, level);
	if (level >= 0)
	{
		for (x = 0; x < size; x++)
		{
			for (y = 0; y < size; y++)
			{
				if (printSymbol(x, y))
					printf("#");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}

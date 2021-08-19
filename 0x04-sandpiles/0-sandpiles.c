#include "sandpiles.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * init_corresponded_grid - fill the corresponded grid with 0
 * @corres: grid 3 by 3 empty
 * Return: void
 */
void init_corresponded_grid(int corres[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			corres[i][j] = 0;
		}
	}
}
/**
 * calculate_sum - calculate the sum of the 2 grids and return 1 if the result
 * contain one box > 3
 * @grid1: first grid 3 by 3
 * @grid2: sedond 3by 3 grid
 *
 * Return: 1 if we need to streatch else 0
 */
int calculate_sum(int grid1[3][3], int grid2[3][3])
{
	int recalculate_sum = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3 && recalculate_sum == 0)
				recalculate_sum = 1;
		}
	}
	return (recalculate_sum);
}

/**
 * check_before_stretch - check if the grid needs an other streach
 * @gr: 3 by 3 grid
 * Return: 1 if there is a value > 3 else 0
 */

int check_before_stretch(int gr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gr[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * stretch - marque the position of all value > 3 in the grid and save it
 * in the corresponded grid, and reduce its value by 4. then for each value in
 * the corresponded Grid equal to 1 we have to add 1 to the adjacent value of
 * the grid
 * @gr: 3 by 3 grid
 *
 * Return: void
 */
void stretch(int gr[3][3])
{
	int correspondance[3][3];

	init_corresponded_grid(correspondance);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gr[i][j] > 3)
			{
				/* mark the position of the box that have vlue > 3 */
				correspondance[i][j] = 1;
				/* set the value to 0 */
				gr[i][j] -= 4;
			}
		}
	}
	for (int line = 0; line < 3; line++)
	{
		for (int column = 0; column < 3; column++)
		{
			if (correspondance[line][column] == 1)
			{
				/* add 1 to the adjacent position */
				if (column + 1 < 3)
					gr[line][column + 1] += 1;
				if (column - 1 >= 0)
					gr[line][column - 1] += 1;
				if (line + 1 < 3)
					gr[line + 1][column] += 1;
				if (line - 1 >= 0)
					gr[line - 1][column] += 1;
			}
		}
	}
	printf("=\n");
	print_grid(gr);
	if (check_before_stretch(gr))
		stretch(gr);
}

/**
 * sandpiles_sum - each iteration to calculate the sum of 2 sandpiles
 * print the result
 * @grid1: first grid 3 by 3
 * @grid2: sedond 3by 3 grid
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int need_stretch;

	need_stretch = calculate_sum(grid1, grid2);

	print_grid(grid1);

	if (need_stretch)
		stretch(grid1);
}

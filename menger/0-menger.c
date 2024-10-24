#include "menger.h"

/**
 * menger - Draw 2D Meng
 * @level: MLevel to draw
 */
void menger(int level)
{
	int row, column, size;
	char rizar;

	size = pow(3, level);

	for (row = 0; row < size; ++row)
	{
		for (column = 0; column < size; ++column)
		{
			rizar = characters(row, column);
			printf("%c", rizar);
		}
		putchar(10);
	}
}


/**
 * characters - draws a character
 * @row: row
 * @column: cols
 * Return: (char) Characters
 */
char characters(int row, int column)
{
	while (row || column)
	{
		if (row % 3 == 1 && column % 3 == 1)
			return (' ');

		row /= 3;
		column /= 3;
	}

	return ('#');
}

#include "holberton.h"

/**
 * _puts - prints a string.
 * @s: a string.
 * Return: Nothing.
 */
void _puts(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		_puts(s + 1);
	}
}

/**
 * err_message - print an error message and exit with status 98.
 * @s: error message to print
 * Return: Nothing
 */
void err_message(char *s)
{
	_puts(s);
	exit(98);
}

/**
 * _isdigit - check if a string is a number.
 * @s: string to check.
 * Return: 0 if s is a number, otherwise 1.
 */
int _isdigit(char *s)
{
	int i, digit = 0;

	for (i = 0; s[i] && !digit; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			digit++;
	}
	return (digit);
}

/**
 * operations - multiplies, adds and stores the result in a string.
 * @num1: first number.
 * @num2: second number.
 * @len1: length of num1.
 * @len2: length of num2.
 * Return: result of multiplication.
 */
char *operations(char *num1, char *num2, int len1, int len2)
{
	char *result;
	int i, j, carry, len_total = (len1 + len2);

	result = malloc(sizeof(char) * (len_total + 1));
	if (!result)
		err_message("Error");

	for (i = 0; i < len_total; i++)
		result[i] = '0';
	result[len_total] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			carry += (num1[i] - '0') * (num2[j] - '0');
			carry += result[i + j + 1] - '0';
			result[i + j + 1] = (carry % 10) + '0';
			carry /= 10;
		}
		if (carry)
			result[i + j + 1] = (carry % 10) + '0';
	}
	return (result);
}

/**
 * main - multiplies two positive numbers.
 * Description: Usage: mul num1 num2
 * Print the result, followed by a new line.
 * @ac: arguments count
 * @av: arguments value (num1, num2)
 * Return: 0 if success, otherwise 98 and print Error.
 */
int main(int ac, char **av)
{
	int len1 = 0, len2 = 0;
	char *num1, *num2, *result;

	if (ac != 3)
		err_message("Error");

	num1 = av[1];
	num2 = av[2];

	if (_isdigit(num1) || _isdigit(num2))
		err_message("Error");

	if (num1[0] == '0' || num2[0] == '0')
	{
		_puts("0");
		return (0);
	}

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = operations(num1, num2, len1, len2);

	while (*result == '0')
		result++;

	_puts(result);

	free(result - (len1 + len2));
	return (0);
}

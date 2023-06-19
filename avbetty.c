#include "shell.h"

/**
 * sum_numb - sum two numbers.
 * @a: First number.
 * @v:econd number.
 * Return: The sum of a and v.
 */
int sum_numb(int a, int v)
{
	return (a + v);
}

/**
 * main - Entry point.
 * Return: Always 0.
 */
int main(void)
{
	int num1 = 9;
	int num2 = 11;
	int result;

	result = sum_numb(num1, num2);
	printf("The sum is: %d\n", result);

	return (0);
}




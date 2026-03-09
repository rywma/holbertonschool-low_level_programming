#include "main.h"

/**
 * _memset - fill memory
 * @s: memory area filled
 * @b: char to copy
 * @n: number of lines to copy b
 *
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

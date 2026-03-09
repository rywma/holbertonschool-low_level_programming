#include "main.h"

char *_memset(char *s, char b, unisgned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

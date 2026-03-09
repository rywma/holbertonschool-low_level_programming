char *_memset(char *s, char b, unisgned int n)
{
	unsigned int i;

	for (i = 0; i < n; ++)
	{
		s[i] = b;
	}

	return (s);
}

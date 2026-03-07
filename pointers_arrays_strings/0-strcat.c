#include "main.h"

/**
 * _strcat - concatenates strings
 * @dest: destiantion
 * @src: source
 *
 * Return: pointer to resulting stings
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

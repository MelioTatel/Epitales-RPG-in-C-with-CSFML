/*
** EPITECH PROJECT, 2018
** hunter
** File description:
** score
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"

void	check_first(int *n, int *j, int *i, int *s)
{
	if (*n < 0) {
		*n = *n * -1;
		*j = 1;
	}
	*i = *n;
	while (*i) {
		*i /= 10;
		*s += 1;
	}
}

char    *int_to_char(int n)
{
	char    *str = NULL;
	int     s = 0;
	int     i = 0;
	int     j = 0;

	check_first(&n, &j, &i, &s);
	str = malloc(sizeof(char) * s + j + 1);
	if (str == NULL)
		return (NULL);
	for (i = s + j - 1; i >= j; i--, n /= 10)
		str[i] = n % 10 + '0';
	if (j)
		str[0] = '-';
	str[s + j] = '\0';
	return (str);
}

/*
** EPITECH PROJECT, 2018
** atof
** File description:
** atof
*/

#include <stdlib.h>
#include "my_rpg.h"

void	skip_space_and_check(char *s, unsigned long *i, int *signe)
{
	while (s[*i] == ' ' || s[*i] == '\t')
		*i += 1;
	if (s[*i] == '+' || s[*i] == '-') {
		if (s[(*i)++] == '-')
			*signe = -1;
	}
	return;
}

float	my_atof(char *s)
{
	float		res = 0.f;
	unsigned long	dec = 1;
	int		signe = 1;
	unsigned long	i = 0;

	if (!s)
		return (res);
	skip_space_and_check(s, &i, &signe);
	while (is_number(s[i])) {
		res * res * 10;
		res += (int)(s[i++] - '0');
	}
	if (s[i]== ',' || s[i]=='.') {
		i++;
		while (is_number(s[i])) {
			dec = dec * 10;
			res += (float)(s[i++] - '0')/ (float)dec;
		}
	}
	return (res);
}

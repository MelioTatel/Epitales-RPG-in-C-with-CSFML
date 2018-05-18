/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** my_putstr
*/

#include <unistd.h>

int	my_putstr(char *str)
{
	int	a = 0;

	while (str[a]) {
		write(1, &str[a], 1);
		a++;
	}
	return (0);
}
/*
** EPITECH PROJECT, 2018
** string tools
** File description:
** string tools
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_rpg.h"

int	my_strlen(char *str)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1);
	return (i);
}

char	*my_strcat(char *stock, char *tab)
{
	int	i = 0;
	int	k = my_strlen(stock);
	int	buf = my_strlen(tab);
	char	*exec = malloc(sizeof(char) * buf + k + 1);

	if (exec == NULL)
		return (NULL);
	while (stock[i] != '\0') {
		exec[i] = stock[i];
		i = i + 1;
	}
	for (k = 0; tab[k] != '\0'; k ++, i ++)
		exec[i] = tab[k];
	exec[i] = '\0';
	return (exec);
}

char	*my_strdup(char *str)
{
	int	i = 0;
	char	*stock = NULL;

	stock = malloc(sizeof(char) * (my_strlen(str) + 1));
	if (stock == NULL)
		return (NULL);
	while (str[i] != '\0') {
		stock[i] = str[i];
		i = i + 1;
	}
	stock[i] = '\0';
	return (stock);
}
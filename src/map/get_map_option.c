/*
** EPITECH PROJECT, 2018
** get map option
** File description:
** get the map options
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int	my_map_get_nbr(char *s, int *index)
{
	int	i = 0;
	int	nb = 0;

	for (i = *index; s[i] && s[i] != '\t' && s[i] != '\n' &&
	(s[i] >= '0' && s[i] <= '9'); i += 1) {
		nb = nb * 10 + s[i] - '0';
	}
	if (s[i] != '\0' && s[i] != '\t' && s[i] != '\n') {
		my_putstr("Map file must contain only int\n");
		return (-1);
	}
	if (s[i] == '\t' || s[i] == '\n')
		*index = i + 1;
	return (nb);
}

int	parse_map_file(char *s, list_t **elem)
{
	int	index = 0;

	(*elem)->init_x = my_map_get_nbr(s, &index);
	if ((*elem)->init_x >= MAP_X || (*elem)->init_x == -1)
		return (-1);
	(*elem)->init_y = my_map_get_nbr(s, &index);
	if ((*elem)->init_y >= MAP_Y || (*elem)->init_y == -1)
		return (-1);
	(*elem)->last_x = my_map_get_nbr(s, &index);
	if ((*elem)->last_x >= MAP_X || (*elem)->last_x == -1)
		return (-1);
	(*elem)->last_y = my_map_get_nbr(s, &index);
	if ((*elem)->last_y >= MAP_Y || (*elem)->last_y == -1)
		return (-1);
	(*elem)->type = my_map_get_nbr(s, &index);
	if ((*elem)->type == -1)
		return (-1);
	(*elem)->first = my_map_get_nbr(s, &index);
	if ((*elem)->first == -1)
		return (-1);
	return (0);
}

int	my_map_in_list(char *s, list_t **l1)
{
	list_t	*elem;
	list_t	*tmp = *l1;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return (-1);
	if (parse_map_file(s, &elem) == -1)
		return (-1);
	elem->next = NULL;
	if (tmp == NULL) {
		*l1 = elem;
		return (0);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return (0);
}

int	verif_line(char *s)
{
	int	i = 0;
	int	count = 0;

	for (i = 0; s[i]; i += 1) {
		if (s[i] == '\t')
			count += 1;
	}
	if (count != 5) {
		my_putstr("Error in map file\n");
		return (-1);
	}
	return (0);
}

int	get_map_file(list_t **l1)
{
	FILE	*stream = fopen("./game_config/map_config", "r");
	size_t	len = 0;
	char	*s = NULL;

	if (!stream)
		return (-1);
	for (int i = 0; i < 29; i += 1)
		if (getline(&s, &len, stream) == -1)
			return (-1);
	while (getline(&s, &len, stream) != -1) {
		if (verif_line(s) == -1)
			return (-1);
		if (my_map_in_list(s, l1) == -1)
			return (-1);
	}
	free(s);
	return (0);
}

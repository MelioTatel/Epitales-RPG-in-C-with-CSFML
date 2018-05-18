/*
** EPITECH PROJECT, 2018
** check bfr put on the map
** File description:
** check bfr put on the map
*/

#include <stdlib.h>
#include "my_rpg.h"

void	map_y_first(list_t **l1, int **map)
{
	if ((*l1)->init_y > (*l1)->last_y)
		sub_map_y(l1, map);
	else
		add_map_y(l1, map);
	if ((*l1)->init_x > (*l1)->last_x)
		sub_map_x(l1, map);
	else
		add_map_x(l1, map);
	return;
}

void	map_x_first(list_t **l1, int **map)
{
	if ((*l1)->init_x > (*l1)->last_x)
		sub_map_x(l1, map);
	else
		add_map_x(l1, map);
	if ((*l1)->init_y > (*l1)->last_y)
		sub_map_y(l1, map);
	else
		add_map_y(l1, map);
	return;
}

void	modif_map(list_t **l1, int **map)
{
	list_t	*tmp;

	while (*l1 != NULL) {
		if ((*l1)->first == 0)
			map_y_first(l1, map);
		else
			map_x_first(l1, map);
		tmp = *l1;
		*l1 = (*l1)->next;
		free(tmp);
	}
}

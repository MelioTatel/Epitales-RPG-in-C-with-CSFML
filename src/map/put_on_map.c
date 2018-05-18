/*
** EPITECH PROJECT, 2018
** put_on_map
** File description:
** put_on_map
*/

#include "my_rpg.h"

void	sub_map_y(list_t **l1, int **map)
{
	while ((*l1)->init_y != (*l1)->last_y) {
		map[(*l1)->init_y][(*l1)->init_x] = (*l1)->type;
		(*l1)->init_y += -1;
	}
	map[(*l1)->init_y][(*l1)->init_x] = (*l1)->type;
	return;
}

void	sub_map_x(list_t **l1, int **map)
{
	while ((*l1)->init_x != (*l1)->last_x) {
		map[(*l1)->init_y][(*l1)->init_x] = (*l1)->type;
		(*l1)->init_x += -1;
	}
	map[(*l1)->init_y][(*l1)->init_x] = (*l1)->type;
	return;
}

void	add_map_y(list_t **l1, int **map)
{
	while ((*l1)->init_y != (*l1)->last_y) {
		map[(*l1)->init_y][(*l1)->init_x] = (*l1)->type;
		(*l1)->init_y += 1;
	}
	map[(*l1)->init_y][(*l1)->init_x] = (*l1)->type;
	return;
}

void	add_map_x(list_t **l1, int **map)
{
	while ((*l1)->init_x != (*l1)->last_x) {
		map[(*l1)->init_y][(*l1)->init_x] = (*l1)->type;
		(*l1)->init_x += 1;
	}
	map[(*l1)->init_y][(*l1)->init_x] = (*l1)->type;
	return;
}

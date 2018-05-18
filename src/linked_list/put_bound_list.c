/*
** EPITECH PROJECT, 2018
** put bound list
** File description:
** put on bound list
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

void	my_put_in_list(bounds_t **bounds, sfFloatRect rect)
{
	bounds_t	*elem;
	bounds_t	*tmp = *bounds;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return;
	elem->rect = rect;
	elem->next = NULL;
	if (tmp == NULL) {
		*bounds = elem;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return;
}
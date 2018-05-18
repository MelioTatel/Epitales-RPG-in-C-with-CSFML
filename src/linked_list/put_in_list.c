/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** put in list
*/

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

void	my_put_in_listl(char **tab, list_conf_t **list)
{
	list_conf_t	*tmp = *list;
	list_conf_t	*elem;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return;
	elem->data = tab;
	elem->next = NULL;
	if (tmp == NULL) {
		*list = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}

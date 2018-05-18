/*
** EPITECH PROJECT, 2018
** linked_list
** File description:
** linked_list
*/

#ifndef	LINKED_H_
#define LINKED_H_

typedef struct		s_list
{
	int		init_x;
	int		init_y;
	int		last_x;
	int		last_y;
	int		type;
	int		first;
	struct s_list	*next;
}	list_t;

typedef	struct		s_item
{
	int		type;
	int		used;
	sfSprite	*sprite;
	sfTexture	*texture;
	sfFloatRect	hitbox;
	struct	s_item	*next;
}	item_t;

typedef struct		s_list_conf
{
	char			**data;
	struct s_list_conf	*next;
}	list_conf_t;

#endif /* LINKED_H_ */

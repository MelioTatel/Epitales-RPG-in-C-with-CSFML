/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_invent
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

void	add_item(int type, char *texture, sfVector2f vect, item_t **inv)
{
	item_t	*elem = NULL;
	item_t	*tail = *inv;

	elem = malloc(sizeof(item_t));
	elem->type = type;
	elem->next = NULL;
	elem->sprite = sfSprite_create();
	elem->texture = sfTexture_createFromFile(texture, NULL);
	sfSprite_setTexture(elem->sprite, elem->texture, sfTrue);
	sfSprite_setScale(elem->sprite, d_v(0.15, 0.15));
	elem->hitbox = sfSprite_getGlobalBounds(elem->sprite);
	sfSprite_setPosition(elem->sprite, vect);
	if (!tail) {
		*inv = elem;
		return;
	}
	while (tail->next)
		tail = tail->next;
	tail->next = elem;
	return;
}

int	init_inv(game_t *g)
{
	char	*p_tt = "./src/assets/items/inventory.png";

	g->inv.in_inv = 0;
	g->inv.item = NULL;
	g->inv.layer_sprite = sfSprite_create();
	g->inv.layer_texture = sfTexture_createFromFile(p_tt, NULL);
	sfSprite_setTexture(g->inv.layer_sprite, g->inv.layer_texture, sfTrue);
	sfSprite_setPosition(g->inv.layer_sprite, d_v(1300, 500));
	sfSprite_setScale(g->inv.layer_sprite, d_v(2, 2));
	add_item(1, "./src/assets/items/heal.png", d_v(1315, 500),
	&(g->inv.item));
	add_item(2, "./src/assets/items/heal.png", d_v(1615, 500),
	&(g->inv.item));
	return (0);
}

int	inv_event(game_t *g, item_t *tmp, sfEvent ev)
{
	if (ev.type == sfEvtKeyReleased && ev.key.code == sfKeyEscape)
		g->inv.in_inv = 0;
	if (ev.type == sfEvtKeyReleased && ev.key.code == sfKeyI)
		g->inv.in_inv = 0;
	if (ev.type == sfEvtClosed) {
		sfRenderWindow_close(g->video.win);
		g->inv.in_inv = 0;
	}
}

int	draw_item(game_t *g)
{
	sfEvent	ev;
	item_t	*tmp = NULL;

	if (g->inv.item)
		tmp = g->inv.item;
	while (tmp) {
		if (tmp->used == 0)
			sfRenderWindow_drawSprite(g->video.win,
			tmp->sprite, NULL);
		while (sfRenderWindow_pollEvent(g->video.win, &ev))
			inv_event(g, tmp, ev);
		tmp = tmp->next;
	}
	return (0);
}

int	inventory(game_t *g)
{
	while (g->inv.in_inv == 1) {
		sfRenderWindow_drawSprite(g->video.win,
		g->inv.layer_sprite, NULL);
		draw_item(g);
		sfRenderWindow_display(g->video.win);
	}
}
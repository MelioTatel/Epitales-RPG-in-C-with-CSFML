/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** check_visual
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	check_for_visual3(game_t *g, sfEvent e)
{
	int	x = e.mouseMove.x;
	int	y = e.mouseMove.y;

	if (sfFloatRect_contains(&g->menu[9].hitbox, x, y)) {
		sfSprite_setScale(g->menu[9].sprite, d_v(1.2, 1.2));
		sfText_setScale(g->menu[9].text, d_v(1, 1));
	}
	if (sfFloatRect_contains(&g->menu[10].hitbox, x, y)) {
		sfSprite_setScale(g->menu[10].sprite, d_v(1.2, 1.2));
		sfText_setScale(g->menu[10].text, d_v(1, 1));
	}
	if (sfFloatRect_contains(&g->menu[11].hitbox, x, y)) {
		sfSprite_setScale(g->menu[11].sprite, d_v(1.2, 1.2));
		sfText_setScale(g->menu[11].text, d_v(1, 1));
	}
	if (sfFloatRect_contains(&g->menu[19].hitbox, x, y)) {
		sfSprite_setScale(g->menu[19].sprite, d_v(1.2, 1.2));
		sfText_setScale(g->menu[19].text, d_v(1, 1));
	}
}

void	check_for_visual2(game_t *g, sfEvent e)
{
	int	x = e.mouseMove.x;
	int	y  = e.mouseMove.y;

	if (sfFloatRect_contains(&g->menu[5].hitbox, x, y)) {
		sfSprite_setScale(g->menu[5].sprite, d_v(1.2, 1.2));
		sfText_setScale(g->menu[5].text, d_v(1, 1));
	}
	if (sfFloatRect_contains(&g->menu[6].hitbox, x, y)) {
		sfSprite_setScale(g->menu[6].sprite, d_v(1.2, 1.2));
		sfText_setScale(g->menu[6].text, d_v(1, 1));
	}
	check_for_visual3(g, e);
}

void	check_for_visual(game_t *g, sfEvent e)
{
	int	x = e.mouseMove.x;
	int	y  = e.mouseMove.y;

	if (sfFloatRect_contains(&g->menu[0].hitbox, x, y)) {
		if (g->bool_pos == 0) {
			sfSprite_setScale(g->menu[0].sprite, d_v(1.2, 1.2));
			sfText_setScale(g->menu[0].text, d_v(1, 1));
		}
	}
	if (sfFloatRect_contains(&g->menu[1].hitbox, x, y)) {
		sfSprite_setScale(g->menu[1].sprite, d_v(1.2, 1.2));
		sfText_setScale(g->menu[1].text, d_v(1, 1));
	}
	if (sfFloatRect_contains(&g->menu[2].hitbox, x, y)) {
		sfSprite_setScale(g->menu[2].sprite, d_v(1.2, 1.2));
		sfText_setScale(g->menu[2].text, d_v(1, 1));
	}
	check_for_visual2(g, e);
}
/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** change state button
*/

#include "my_rpg.h"

void	change_state3(game_t *g, sfEvent e)
{
	int	x = e.mouseButton.x;
	int	y  = e.mouseButton.y;

	if (sfFloatRect_contains(&g->menu[9].hitbox, x, y)) {
		g->menu[0].rbut.top = 79;
		g->menu[0].rbut.left = 0;
		sfSprite_setTextureRect(g->menu[9].sprite, g->menu[0].rbut);
	}
	if (sfFloatRect_contains(&g->menu[10].hitbox, x, y)) {
		g->menu[0].rbut.top = 79;
		g->menu[0].rbut.left = 0;
		sfSprite_setTextureRect(g->menu[10].sprite, g->menu[0].rbut);
	}
	if (sfFloatRect_contains(&g->menu[19].hitbox, x, y)) {
		g->menu[0].rbut.top = 79;
		g->menu[0].rbut.left = 0;
		sfSprite_setTextureRect(g->menu[19].sprite, g->menu[0].rbut);
	}
}

void	change_state2(game_t *g, sfEvent e)
{
	int	x = e.mouseButton.x;
	int	y  = e.mouseButton.y;

	if (sfFloatRect_contains(&g->menu[5].hitbox, x, y)) {
		g->menu[0].rbut.top = 79;
		g->menu[0].rbut.left = 0;
		sfSprite_setTextureRect(g->menu[5].sprite, g->menu[0].rbut);
	}
	if (sfFloatRect_contains(&g->menu[6].hitbox, x, y)) {
		g->menu[0].rbut.top = 79;
		g->menu[0].rbut.left = 0;
		sfSprite_setTextureRect(g->menu[6].sprite, g->menu[0].rbut);
	}
	change_state3(g, e);
}

void	change_state(game_t *g, sfEvent e)
{
	int	x = e.mouseButton.x;
	int	y  = e.mouseButton.y;

	if (sfFloatRect_contains(&g->menu[0].hitbox, x, y)) {
		g->menu[0].rbut.top = 79;
		g->menu[0].rbut.left = 0;
		sfSprite_setTextureRect(g->menu[0].sprite, g->menu[0].rbut);
	}
	if (sfFloatRect_contains(&g->menu[1].hitbox, x, y)) {
		g->menu[0].rbut.top = 79;
		g->menu[0].rbut.left = 0;
		sfSprite_setTextureRect(g->menu[1].sprite, g->menu[0].rbut);
	}
	if (sfFloatRect_contains(&g->menu[2].hitbox, x, y)) {
		g->menu[0].rbut.top = 79;
		g->menu[0].rbut.left = 0;
		sfSprite_setTextureRect(g->menu[2].sprite, g->menu[0].rbut);
	}
	change_state2(g, e);
}

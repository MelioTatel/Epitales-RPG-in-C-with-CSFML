/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** event menu
*/

#include "my_rpg.h"

void	texture_rect(game_t *g)
{
	sfSprite_setTextureRect(g->menu[0].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[1].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[2].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[5].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[6].sprite, g->menu[0].rbut);
}

void	in_menu(game_t *g, sfEvent e)
{
	int	x = e.mouseButton.x;
	int	y  = e.mouseButton.y;

	g->menu[0].rbut.left = 0;
	g->menu[0].rbut.top = 0;
	texture_rect(g);
	if (sfFloatRect_contains(&g->menu[0].hitbox, x, y)) {
		champ_select(g);
		g->graph[2] = init_sprite(g->hero_path);
		sfSprite_setPosition(g->graph[2].sp, d_v(100, 200));
		g->graph[2].rect = do_irect(0, 0, 28, 45);
		sfSprite_setTextureRect(g->graph[2].sp, g->graph[2].rect);
		sfSprite_setOrigin(g->graph[2].sp, d_v(28 / 2, 45 / 2));
		g->graph[2].class = guerrier();
	}
	if (sfFloatRect_contains(&g->menu[1].hitbox, x, y))
		g->bool_pos = 11;
	if (sfFloatRect_contains(&g->menu[2].hitbox, x, y))
		g->bool_pos = 8;
	return;
}

/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** pause
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	key_event(game_t *g, sfEvent ev)
{
	if (ev.type == sfEvtKeyReleased && ev.key.code == sfKeyI) {
		if (g->bool_pos == 1) {
			g->inv.in_inv = 1;
			inventory(g);
		}
	}
	if (ev.key.code == sfKeyEscape && g->bool_pos == 0)
		g->bool_pos = 8;
	else if (ev.key.code == sfKeyEscape && g->bool_pos == 11)
		g->bool_pos = 0;
	else if (ev.key.code == sfKeyEscape && g->bool_pos == 8)
		g->bool_pos = 0;
	else if (ev.key.code == sfKeyEscape && g->bool_pos == 1)
		g->bool_pos = 10;
	else if (ev.key.code == sfKeyEscape && g->bool_pos == 10)
		g->bool_pos = 1;
	else if (ev.key.code == sfKeyEscape && g->bool_pos == 9)
		g->bool_pos = 10;
	else if (ev.key.code == sfKeyEscape && g->bool_pos == 12)
		g->bool_pos = 10;
}

void	in_quit(game_t *g, sfEvent e)
{
	int	x = e.mouseButton.x;
	int	y  = e.mouseButton.y;

	g->menu[0].rbut.left = 0;
	g->menu[0].rbut.top = 0;
	sfSprite_setTextureRect(g->menu[9].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[10].sprite, g->menu[0].rbut);
	if (sfFloatRect_contains(&g->menu[9].hitbox, x, y) && g->bool_pos == 8)
		sfRenderWindow_close(g->video.win);
	if (sfFloatRect_contains(&g->menu[9].hitbox, x, y) && g->bool_pos == 9)
		g->bool_pos = 0;
	if (sfFloatRect_contains(&g->menu[10].hitbox, x, y) && g->bool_pos == 8)
		g->bool_pos = 0;
	if (sfFloatRect_contains(&g->menu[10].hitbox, x, y) && g->bool_pos == 9)
		g->bool_pos = 10;
}

void	pause_in_game(game_t *g, sfEvent e)
{
	int	x = e.mouseButton.x;
	int	y  = e.mouseButton.y;

	g->menu[0].rbut.left = 0;
	g->menu[0].rbut.top = 0;
	sfSprite_setTextureRect(g->menu[1].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[2].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[6].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[9].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[10].sprite, g->menu[0].rbut);
	if (sfFloatRect_contains(&g->menu[19].hitbox, x, y))
		g->bool_pos = 1;
	if (sfFloatRect_contains(&g->menu[1].hitbox, x, y)) {
		g->bool_pos = 12;
		draw_opt_ig(g);
	}
	if (sfFloatRect_contains(&g->menu[2].hitbox, x, y))
		g->bool_pos = 9;
}

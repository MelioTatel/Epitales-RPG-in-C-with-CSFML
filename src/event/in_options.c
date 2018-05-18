/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** actions in option
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	option_change_bool(game_t *g, int x, int y)
{
	if (sfFloatRect_contains(&g->menu[6].hitbox, x, y) && g->bool_pos == 11)
		g->bool_pos = 0;
	if (sfFloatRect_contains(&g->menu[6].hitbox, x, y) && g->bool_pos == 12)
		g->bool_pos = 10;
	if (sfFloatRect_contains(&g->menu[6].hitbox, x, y) && g->bool_pos == 12)
		g->bool_pos = 10;
}

void	in_options(game_t *g, sfEvent e)
{
	int	x = e.mouseButton.x;
	int	y  = e.mouseButton.y;
	sfFloatRect	hm = sfText_getGlobalBounds(g->menu[8].text);
	sfFloatRect	hp = sfText_getGlobalBounds(g->menu[7].text);
	sfFloatRect	hs = sfSprite_getGlobalBounds(g->msc.on);

	if (sfFloatRect_contains(&hm, x, y) && g->opt.pos >= 2) {
		g->opt.pos--;
		g->msc.vol -= 10;
	}
	if (sfFloatRect_contains(&hp, x, y) && g->opt.pos <= 10) {
		g->opt.pos++;
		g->msc.vol += 10;
	}
	option_change_bool(g, x, y);
	if (sfFloatRect_contains(&hs, x, y))
		g->msc.bs += 1;
}

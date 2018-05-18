/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** reset state
*/

#include "my_rpg.h"

void	reset_all(game_t *g)
{
	g->menu[0].rbut.left = 0;
	g->menu[0].rbut.top = 0;
	sfSprite_setTextureRect(g->menu[0].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[1].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[2].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[3].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[4].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[5].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[6].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[7].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[8].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[9].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[10].sprite, g->menu[0].rbut);
	sfSprite_setTextureRect(g->menu[19].sprite, g->menu[0].rbut);
}

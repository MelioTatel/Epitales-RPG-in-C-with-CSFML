/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** status
*/

#include "struct.h"
#include "my_rpg.h"

void	init_status(game_t *g)
{
	g->status.hp = sfText_create();
	g->status.def = sfText_create();
	g->status.dmg = sfText_create();
	g->status.agi = sfText_create();
	g->status.mag = sfText_create();
	g->graph[2].class = guerrier();
	sfText_setFont(g->status.hp, g->menu[0].police);
	sfText_setFont(g->status.def, g->menu[0].police);
	sfText_setFont(g->status.dmg, g->menu[0].police);
	sfText_setFont(g->status.agi, g->menu[0].police);
	sfText_setFont(g->status.mag, g->menu[0].police);
	sfText_setString(g->status.hp, int_to_char(g->graph[2].class.hp));
	sfText_setString(g->status.def, int_to_char(g->graph[2].class.def));
	sfText_setString(g->status.dmg, int_to_char(g->graph[2].class.dmg));
	sfText_setString(g->status.agi, int_to_char(g->graph[2].class.agi));
	sfText_setString(g->status.mag, int_to_char(g->graph[2].class.mag));
}

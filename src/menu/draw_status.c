/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** draw status
*/

#include "struct.h"
#include "my_rpg.h"

void	set_status(game_t *g)
{
	sfSprite_setPosition(g->champ.status, d_v(1275, 430));
	sfText_setPosition(g->status.hp, d_v(1465, 440));
	sfText_setColor(g->status.hp, sfRed);
	sfText_setPosition(g->status.def, d_v(1475, 490));
	sfText_setColor(g->status.def, sfYellow);
	sfText_setPosition(g->status.dmg, d_v(1475, 535));
	sfText_setPosition(g->status.agi, d_v(1475, 585));
	sfText_setColor(g->status.agi, sfGreen);
	sfText_setPosition(g->status.mag, d_v(1475, 635));
	sfText_setColor(g->status.mag, sfBlue);
}

void	reset_string(game_t *g)
{
	sfText_setString(g->status.hp, int_to_char(g->graph[2].class.hp));
	sfText_setString(g->status.def, int_to_char(g->graph[2].class.def));
	sfText_setString(g->status.dmg, int_to_char(g->graph[2].class.dmg));
	sfText_setString(g->status.agi, int_to_char(g->graph[2].class.agi));
	sfText_setString(g->status.mag, int_to_char(g->graph[2].class.mag));
}

void	draw_status(game_t *g, int *a)
{
	set_status(g);
	sfRenderWindow_drawText(g->video.win, g->status.hp, NULL);
	sfRenderWindow_drawText(g->video.win, g->status.def, NULL);
	sfRenderWindow_drawText(g->video.win, g->status.dmg, NULL);
	sfRenderWindow_drawText(g->video.win, g->status.agi, NULL);
	sfRenderWindow_drawText(g->video.win, g->status.mag, NULL);
	if (*a == 1)
		g->graph[2].class = mage();
	else if (*a == 0)
		g->graph[2].class = guerrier();
	reset_string(g);
}

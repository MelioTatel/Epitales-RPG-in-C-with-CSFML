/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** my_rpg
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

int	display(game_t *g)
{
	sfSprite_setTextureRect(g->graph[2].sp, g->graph[2].rect);
	sfRenderWindow_drawSprite(g->video.win, g->graph[2].sp, NULL);
	sfSprite_setTextureRect(g->pnj[0].sp, g->pnj[0].rect);
	sfSprite_setTextureRect(g->pnj[1].sp, g->pnj[1].rect);
	sfRenderWindow_drawSprite(g->video.win, g->pnj[0].sp, NULL);
	if (g->pnj[1].classe.hp > 0)
		sfRenderWindow_drawSprite(g->video.win, g->pnj[1].sp, NULL);
	if (g->graph[2].rect.left > 70)
		g->graph[2].rect.left = 0;
	return (0);
}

int	do_boucle_cut(game_t *g, sfVector2f **map2d, int **map3d)
{
	if (g->bool_pos == 0)
		draw_menu(g);
	if (g->bool_pos == 11 || g->bool_pos == 12)
		draw_options(g);
	if (g->bool_pos == 8)
		draw_pause(g);
	if (g->bool_pos == 9) {
		draw_2d_map(map2d, map3d, g);
		display(g);
		ask_quit_ig(g);
	}
	return (0);
}

int	do_boucle(game_t *g, sfVector2f **map2d, int **map3d, bounds_t *tmp)
{
	my_event(g, tmp);
	sfRenderWindow_clear(g->video.win, sfBlack);
	introduction(g);
	do_boucle_cut(g, map2d, map3d);
	if (g->bool_pos == 10) {
		draw_2d_map(map2d, map3d, g);
		display(g);
		draw_pause_ingame(g);
	}
	if (g->bool_pos == 1) {
		draw_2d_map(map2d, map3d, g);
		display(g);
		g->graph[2].frect = sfSprite_getGlobalBounds(g->graph[2].sp);
		anim_water(g, tmp);
		verif_dialog(g, map3d, map2d);
		tmp = g->bounds;
	}
	sfRenderWindow_display(g->video.win);
	return (0);
}

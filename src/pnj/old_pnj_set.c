/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** old_pnj_set
*/

#include <stdlib.h>
#include "my_rpg.h"

void	set_old_lady_dialog(game_t *g)
{
	sfClock_restart(g->graph[1].clock);
	g->dialog[0] = init_dialog(g->hero_path);
	g->dialog[1] = init_dialog("./src/assets/old_lady2.png");
	g->dialog[0].rect = do_irect(96, 0, 30, 45);
	g->dialog[1].rect = do_irect(47, 0, 30, 39);
	sfSprite_setTextureRect(g->dialog[0].sp, g->dialog[0].rect);
	sfSprite_setTextureRect(g->dialog[1].sp, g->dialog[1].rect);
	sfSprite_setScale(g->dialog[0].sp, d_v(4, 4));
	sfSprite_setScale(g->dialog[1].sp, d_v(4, 4));
	sfSprite_setPosition(g->dialog[0].sp, d_v(-100, 400));
	sfSprite_setPosition(g->dialog[1].sp, d_v(1920, 400));
	return;
}

void	draw_old_lady_dialog(int **map3d, sfVector2f **map2d, game_t *g)
{
	sfRenderWindow_clear(g->video.win, sfWhite);
	draw_2d_map(map2d, map3d, g);
	sfRenderWindow_drawSprite(g->video.win, g->escape.sp, NULL);
	sfSprite_setTextureRect(g->dialog[0].sp, g->dialog[0].rect);
	sfRenderWindow_drawSprite(g->video.win, g->dialog[0].sp, NULL);
	sfSprite_setTextureRect(g->dialog[1].sp, g->dialog[1].rect);
	sfRenderWindow_drawSprite(g->video.win, g->dialog[1].sp, NULL);
	sfRenderWindow_display(g->video.win);
	return;
}

void	rotate_old_lady(game_t *g)
{
	if (pnj_intersect(g, g->pnj[0], g->graph[2]) == 0) {
		g->pnj[0].near = 0;
		g->pnj[0].frect = sfSprite_getGlobalBounds(g->pnj[0].sp);
		move_old_pnj_up(g);
		move_old_pnj_left(g);
		move_old_pnj_right(g);
		move_old_pnj_down(g);
	} else
		g->pnj[0].near = 1;
	return;
}
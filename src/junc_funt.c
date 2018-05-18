/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** junc_funt
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

void	destroy_ev(game_t *g, int **map3d)
{
	sfSprite_destroy(g->graph[0].sp);
	sfSprite_destroy(g->graph[1].sp);
	sfTexture_destroy(g->graph[0].text);
	sfTexture_destroy(g->graph[1].text);
	sfMusic_destroy(g->msc.music);
	sfRenderWindow_destroy(g->video.win);
	return;
}

int	**create_3d_map(void)
{
	int	**map3d;

	map3d = malloc(sizeof(*map3d) * MAP_Y);
	for (int y = 0; y < MAP_Y; y += 1) {
		map3d[y] = malloc(sizeof(*map3d[y]) * MAP_X);
		for (int x = 0; x < MAP_X; x += 1) {
			map3d[y][x] = 0;
		}
	}
	return (map3d);
}

void	anim_water(game_t *g, bounds_t *tmp)
{
	rotate_old_lady(g);
	if (g->pnj[1].classe.hp > 0)
		rotate_goblinc(g);
	if (Clock1 > 500) {
		g->pnj[0].rotate = rand() % 4 + 1;
		if (g->graph[1].clock_bool == 0) {
			sfTexture_destroy(g->ground[WATER].text);
			g->ground[WATER].text = sfTexture_createFromFile
			("./src/assets/Ground/water1.png", NULL);
			g->graph[1].clock_bool = 1;
		}
		else if (g->graph[1].clock_bool == 1) {
			sfTexture_destroy(g->ground[WATER].text);
			g->ground[WATER].text = sfTexture_createFromFile
			("./src/assets/Ground/water2.png", NULL);
			g->graph[1].clock_bool = 0;
		}
		sfClock_restart(g->graph[1].clock);
	}
	return;
}

int	verif_dialog(game_t *g, int **map3d, sfVector2f **map2d)
{
	if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
		if (g->pnj[0].near == 1) {
			old_pnj_dialog(g, map3d, map2d);
		}
	}
	return (0);
}

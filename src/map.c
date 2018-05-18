/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map
*/

#include <math.h>
#include <stdlib.h>
#include "my_rpg.h"

void	draw_xy_map_check(sfVertexArray **vertex_array, game_t *g)
{
	if (g->video.states.texture == g->ground[7].text &&
		g->get_bounds == 0)
		my_put_in_list(&g->bounds,
		sfVertexArray_getBounds(*vertex_array));
	if (g->video.states.texture == g->ground[2].text &&
		g->get_bounds == 0)
		my_put_in_list(&g->bounds,
		sfVertexArray_getBounds(*vertex_array));
	if (g->video.states.texture == g->ground[3].text &&
		g->get_bounds == 0)
		my_put_in_list(&g->bounds,
		sfVertexArray_getBounds(*vertex_array));
	return;
}

void	draw_xy_map(int x, int y, sfVector2f **map2d, game_t *g)
{
	sfVertexArray	*vertex_array;

	if (x + 1 < MAP_X && y + 1 < MAP_Y) {
		vertex_array = create_tile(&map2d[y][x], &map2d[y][x + 1],
		&map2d[y + 1][x + 1], &map2d[y + 1][x]);
		draw_xy_map_check(&vertex_array, g);
		sfRenderWindow_drawVertexArray(g->video.win,
		vertex_array, &g->video.states);
		sfVertexArray_destroy(vertex_array);
	}
	return;
}

int	draw_2d_map(sfVector2f **map2d, int **map3d, game_t *g)
{
	for (int y = 0; y < MAP_Y; y += 1) {
		for (int x = 0; x < MAP_X; x += 1) {
			g->video.states.texture = g->ground[map3d[y][x]].text;
			draw_xy_map(x, y, map2d, g);
		}
	}
	return (0);
}

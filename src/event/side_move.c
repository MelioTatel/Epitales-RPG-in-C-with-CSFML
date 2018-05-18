/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** side_move
*/

#include "my_rpg.h"

int	move_up(game_t *g, bounds_t *tmp, sfEvent ev)
{
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyUp) {
		g->graph[2].frect.top += -5;
		if (check_contain(g->graph[2].frect, tmp) == 0 &&
		sfFloatRect_intersects(&g->pnj[0].frect, &g->graph[2].frect,
		NULL) == sfFalse) {
			g->graph[2].rect.top = 144;
			g->graph[2].rect.left += 32;
			sfSprite_move(g->graph[2].sp, d_v(0, -5));
		}
		else
			g->graph[2].rect.top = 144;
	}
	return (0);
}

int	move_down(game_t *g, bounds_t *tmp, sfEvent ev)
{
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyDown) {
		g->graph[2].frect.top += 5;
		if (check_contain(g->graph[2].frect, tmp) == 0 &&
		sfFloatRect_intersects(&g->pnj[0].frect,
		&g->graph[2].frect, NULL) == sfFalse) {
			g->graph[2].rect.top = 0;
			g->graph[2].rect.left += 32;
			sfSprite_move(g->graph[2].sp, d_v(0, 5));
		}
		else
			g->graph[2].rect.top = 0;
	}
	return (0);
}

int	move_left(game_t *g, bounds_t *tmp, sfEvent ev)
{
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyLeft) {
		g->graph[2].frect.left += -5;
		if (check_contain(g->graph[2].frect, tmp) == 0 &&
		sfFloatRect_intersects(&g->pnj[0].frect, &g->graph[2].frect,
		NULL) == sfFalse) {
			g->graph[2].rect.top = 47;
			g->graph[2].rect.left += 32;
			sfSprite_move(g->graph[2].sp, d_v(-5, 0));
		}
		else
			g->graph[2].rect.top = 47;
	}
	return (0);
}

int	move_right(game_t *g, bounds_t *tmp, sfEvent ev)
{
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyRight) {
		g->graph[2].frect.left += 5;
		if (check_contain(g->graph[2].frect, tmp) == 0 &&
		sfFloatRect_intersects(&g->pnj[0].frect, &g->graph[2].frect,
		NULL) == sfFalse) {
			g->graph[2].rect.top = 96;
			g->graph[2].rect.left += 32;
			sfSprite_move(g->graph[2].sp, d_v(5, 0));
		}
		else
			g->graph[2].rect.top = 96;
	}
	return (0);
}

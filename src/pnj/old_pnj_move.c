/*
** EPITECH PROJECT, 2018
** old player move
** File description:
** old player move
*/

#include "my_rpg.h"

void	move_old_pnj_up(game_t *g)
{
	if (g->pnj[0].rotate == 1) {
		g->pnj[0].rect.top = 0;
		g->pnj[0].frect.top += 1;
		if (check_contain(g->pnj[0].frect, g->bounds) == 0)
			sfSprite_move(g->pnj[0].sp, d_v(0, 0.5));
		g->pnj[0].frect.top += -1;
		g->pnj[0].obstacle = 1;
	}
	return;
}

void	move_old_pnj_left(game_t *g)
{
	if (g->pnj[0].rotate == 2) {
		g->pnj[0].rect.top = 47;
		g->pnj[0].frect.top += +21;
		g->pnj[0].frect.left += -1;
		if (check_contain(g->pnj[0].frect, g->bounds) == 0)
			sfSprite_move(g->pnj[0].sp, d_v(-0.5, 0));
		g->pnj[0].frect.left += +1;
		g->pnj[0].frect.top += -21;
	}
	return;
}

void	move_old_pnj_right(game_t *g)
{
	if (g->pnj[0].rotate == 3) {
		g->pnj[0].rect.top = 95;
		g->pnj[0].frect.top += +21;
		g->pnj[0].frect.left += +1;
		if (check_contain(g->pnj[0].frect, g->bounds) == 0)
			sfSprite_move(g->pnj[0].sp, d_v(0.5, 0));
		g->pnj[0].frect.left += -1;
		g->pnj[0].frect.top += -21;
	}
	return;
}

void	move_old_pnj_down(game_t *g)
{
	if (g->pnj[0].rotate == 4) {
		g->pnj[0].rect.top = 142;
		g->pnj[0].frect.top += -1;
		if (check_contain(g->pnj[0].frect, g->bounds) == 0)
			sfSprite_move(g->pnj[0].sp, d_v(0, -0.5));
		g->pnj[0].frect.top += 1;
		g->pnj[0].obstacle = 0;
	}
	return;
}
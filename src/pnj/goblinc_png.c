/*
** EPITECH PROJECT, 2018
** goblin c
** File description:
** goblin c
*/

#include "my_rpg.h"
#include "pnj.h"

void	move_goblin_down(game_t *g)
{
	sfVector2f	pos;

	if (g->pnj[1].rotate == 0)
		g->pnj[1].rect.top = 0;
	pos = sfSprite_getPosition(g->pnj[1].sp);
	if (pos.y < 900 && g->pnj[1].rotate == 0) {
		sfSprite_move(g->pnj[1].sp, d_v(0, 0.5));
		pos = sfSprite_getPosition(g->pnj[1].sp);
	}
	if (pos.y >= 900)
		g->pnj[1].rotate = 2;
	return;
}

void	move_goblin_up(game_t *g)
{
	sfVector2f	pos;

	if (g->pnj[1].rotate == 1)
		g->pnj[1].rect.top = 96;
	pos = sfSprite_getPosition(g->pnj[1].sp);
	if (pos.y > 800 && g->pnj[1].rotate == 1) {
		sfSprite_move(g->pnj[1].sp, d_v(0, -0.5));
		pos = sfSprite_getPosition(g->pnj[1].sp);
	}
	if (pos.y <= 800)
		g->pnj[1].rotate = 3;
	return;
}

void	move_goblin_right(game_t *g)
{
	sfVector2f	pos;

	pos = sfSprite_getPosition(g->pnj[1].sp);
	if (g->pnj[1].rotate == 2) {
		g->pnj[1].rect.top = 64;
	}
	if (pos.x < 275 && g->pnj[1].rotate == 2) {
		sfSprite_move(g->pnj[1].sp, d_v(0.5, 0));
		pos = sfSprite_getPosition(g->pnj[1].sp);
	}
	if (pos.x >= 275)
		g->pnj[1].rotate = 1;
	return;
}

void	move_goblin_left(game_t *g)
{
	sfVector2f	pos;

	pos = sfSprite_getPosition(g->pnj[1].sp);
	if (g->pnj[1].rotate == 3) {
		g->pnj[1].rect.top = 32;
	}
	if (pos.x > 75 && g->pnj[1].rotate == 3) {
		sfSprite_move(g->pnj[1].sp, d_v(-0.5, 0));
		pos = sfSprite_getPosition(g->pnj[1].sp);
	}
	if (pos.x <= 75)
		g->pnj[1].rotate = 0;
	return;
}

void	rotate_goblinc(game_t *g)
{
	g->pnj[1].frect = sfSprite_getGlobalBounds(g->pnj[1].sp);
	if (pnj_intersect(g, g->pnj[1], g->graph[2]) == 0) {
		g->pnj[1].near = 0;
		g->pnj[1].frect = sfSprite_getGlobalBounds(g->pnj[1].sp);
		move_goblin_down(g);
		move_goblin_right(g);
		move_goblin_up(g);
		move_goblin_left(g);
		g->fight_bool = 0;
		return;
	}
	else {
		if (g->fight_bool != 4)
			g->fight_bool = do_fight(g);
	}
	return;
}

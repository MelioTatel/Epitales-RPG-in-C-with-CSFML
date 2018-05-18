/*
** EPITECH PROJECT, 2018
** old pnj dialog
** File description:
** old lady dialog
*/

#include <stdlib.h>
#include "my_rpg.h"

void	move_old_lady_dialog_bool(game_t *g)
{
	if (g->dialog[0].rect.left > 80)
		g->dialog[0].rect.left = 0;
	if (g->dialog[1].rect.left > 80)
		g->dialog[1].rect.left = 0;
	return;
}

void	move_old_lady_dialog(game_t *g)
{
	sfVector2f	lady = sfSprite_getPosition(g->dialog[1].sp);
	sfVector2f	hero = sfSprite_getPosition(g->dialog[0].sp);

	if (hero.x < 400) {
		sfSprite_move(g->dialog[0].sp, d_v(2, 0));
		if (Clock1 > 500) {
			g->dialog[0].rect.left += 30;
		}
	} else
		g->dialog[0].rect.left = 0;
	if (lady.x > 1420) {
		sfSprite_move(g->dialog[1].sp, d_v(-2, 0));
		if (Clock1 > 500) {
			g->dialog[1].rect.left += 30;
		}
	}
	move_old_lady_dialog_bool(g);
	if (Clock1 > 500)
		sfClock_restart(g->graph[1].clock);
	return;
}

void	old_pnj_loop(game_t *g, int *boo)
{
	sfEvent	ev;

	while (sfRenderWindow_pollEvent(g->video.win, &ev)) {
		if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyReturn)
			*boo = 1;
		if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeySpace) {
			sfSprite_setPosition(g->dialog[0].sp, d_v(400, 400));
			sfSprite_setPosition(g->dialog[1].sp, d_v(1420, 400));
		}
	}
}

int	old_pnj_dialog(game_t *g, int **map3d, sfVector2f **map2d)
{
	set_old_lady_dialog(g);
	for (int boo = 0, mread = 0; boo == 0;) {
		old_pnj_loop(g, &boo);
		draw_old_lady_dialog(map3d, map2d, g);
		move_old_lady_dialog(g);
	}
	return (0);
}

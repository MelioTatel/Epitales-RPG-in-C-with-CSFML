/*
** EPITECH PROJECT, 2018
** gest_spells
** File description:
** gest_spells
*/

#include "my_rpg.h"

void	no_spells(sfVector2f pos, game_t *g, fight_t *f)
{
	if (f->pos == 0) {
		sfSprite_move(f->pnj[0].sp, d_v(5, 0));
		pos = sfSprite_getPosition(f->pnj[0].sp);
		if (pos.x >= 1300) {
			f->pos = 1;
			sfSprite_move(f->pnj[1].sp, d_v(100, 0));
		}
	}
	if (f->pos == 1) {
		sfSprite_move(f->pnj[0].sp, d_v(-5, 0));
		pos = sfSprite_getPosition(f->pnj[0].sp);
	}
	if (pos.x <= 400) {
		sfSprite_move(f->pnj[1].sp, d_v(-100, 0));
		g->pnj[1].classe.hp += -10;
		f->bool_pos = MENU;
		f->pos = 0;
	}
	return;
}
/*
** EPITECH PROJECT, 2018
** draw mage skill
** File description:
** draw mage skill
*/

#include "my_rpg.h"

void	black_hole(game_t *g, fight_t *f)
{
	sfRenderWindow_drawSprite(g->video.win, f->skill[0].sp, NULL);
	if (Clock2 > 150) {
		f->skill[0].irect.left += 194;
		sfClock_restart(f->clock);
	}
	if (f->skill[0].irect.top < 1340) {
		if (f->skill[0].irect.left > 960) {
			f->skill[0].irect.left = 194;
			f->skill[0].irect.top += 194;
		}
	}
	else
		f->skill[0].irect.top = 0;
	sfSprite_setTextureRect(f->skill[0].sp, f->skill[0].irect);
	return;
}

void	fire_tornado(game_t *g, fight_t *f)
{
	sfRenderWindow_drawSprite(g->video.win, f->skill[1].sp, NULL);
	if (Clock2 > 150) {
		f->skill[1].irect.left += 194;
		sfClock_restart(f->clock);
	}
	if (f->skill[1].irect.top < 960) {
		if (f->skill[1].irect.top > 960) {
			f->skill[1].irect.left = 194;
			f->skill[1].irect.top += 194;
		}
	}
	else
		f->skill[1].irect.top = 0;
	sfSprite_setTextureRect(f->skill[1].sp, f->skill[1].irect);
	return;
}

void	draw_mage_skill(game_t *g, fight_t *f)
{
	if (f->bool_pos == SKILLS) {
		if (f->spells == BLACKHOLE)
			black_hole(g, f);
		if (f->spells == FIRE_TORNADO)
			fire_tornado(g, f);
	}
	return;
}
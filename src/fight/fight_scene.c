/*
** EPITECH PROJECT, 2018
** fight scene
** File description:
** fight scene
*/

#include "my_rpg.h"

void		analyse_choice(game_t *g, fight_t *f)
{
	sfVector2f	pos;

	pos = sfSprite_getPosition(f->pnj[0].sp);
	if (f->bool_pos == FIGHT) {
		if (f->spells == NO_SPELL)
			no_spells(pos, g, f);
	}
	if (f->bool_pos == SKILLS) {
		if (f->menu.skill_bool == 0) {
			f->x_arrow = 80;
			f->y_arrow = 920;
			sfSprite_setPosition(f->interface[1].sp,
			d_v(f->x_arrow, f->y_arrow));
			f->menu.skill_bool = 1;
			init_skills_sprites(f);
		}
	}
	return;
}

void		battle_event(game_t *g, fight_t *f)
{
	while (sfRenderWindow_pollEvent(g->video.win, &f->ev)) {
		if (f->bool_pos == MENU)
			select_menu_choice(g, f);
		if (f->bool_pos == SKILLS)
			select_skills_choice(g, f);
	}
	analyse_choice(g, f);
	return;
}

int		do_fight(game_t *g)
{
	fight_t		f;

	init_fight(g, &f);
	while (g->pnj[1].classe.hp > 0 && f.bool_pos != 4) {
		battle_event(g, &f);
		draw_fight(g, &f);
	}
	destroy_fight(g, &f);
	return (f.bool_pos);
}
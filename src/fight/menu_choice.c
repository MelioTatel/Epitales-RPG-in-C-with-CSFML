/*
** EPITECH PROJECT, 2018
** menu_choice
** File description:
** menu_choice
*/

#include "my_rpg.h"

void		select_menu_choice(game_t *g, fight_t *f)
{
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyDown)
		f->y_arrow = 980;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyUp)
		f->y_arrow = 920;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyLeft)
		f->x_arrow = 840;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyRight)
		f->x_arrow = 1100;
	sfSprite_setPosition(f->interface[1].sp, d_v(f->x_arrow, f->y_arrow));
	set_menu_choice(g, f);
	return;
}

void		set_menu_choice(game_t *g, fight_t *f)
{
	if (f->y_arrow == 920 && f->x_arrow == 840 &&
		f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyReturn)
		f->bool_pos = FIGHT;
	if (f->y_arrow == 980 && f->x_arrow == 840 &&
		f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyReturn)
		f->bool_pos = SKILLS;
	if (f->y_arrow == 920 && f->x_arrow == 1100 &&
		f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyReturn)
		f->bool_pos = ITEMS;
	if (f->y_arrow == 980 && f->x_arrow == 1100 &&
	f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyReturn) {
		f->bool_pos = ESCAPE;
		g->pnj[1].classe.hp = 50;
	}
	return;
}
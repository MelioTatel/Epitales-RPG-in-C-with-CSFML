/*
** EPITECH PROJECT, 2018
** fight
** File description:
** fight
*/

#include "my_rpg.h"

void		destroy_fight(game_t *g, fight_t *f)
{
	sfSprite_destroy(f->interface[0].sp);
	sfSprite_destroy(f->interface[1].sp);
	sfSprite_destroy(f->interface[2].sp);
	sfSprite_destroy(f->interface[3].sp);
	return;
}

escape_t	create_ui(char *path)
{
	escape_t	ui;

	ui.text = sfTexture_createFromFile(path, NULL);
	ui.sp = sfSprite_create();
	sfSprite_setTexture(ui.sp, ui.text, sfTrue);
	return (ui);
}

battle_t	init_battle(char *path)
{
	battle_t	dial;

	dial.text = sfTexture_createFromFile(path, NULL);
	dial.sp = sfSprite_create();
	sfSprite_setTexture(dial.sp, dial.text, sfTrue);
	return (dial);
}

void		set_fight(fight_t *f)
{
	sfSprite_setScale(f->pnj[0].sp, d_v(3, 3));
	sfSprite_setScale(f->pnj[1].sp, d_v(4, 4));
	sfSprite_setScale(f->interface[3].sp, d_v(4, 4));
	sfSprite_setScale(f->interface[0].sp, d_v(0.5, 0.5));
	sfSprite_setPosition(f->pnj[0].sp, d_v(400, 500));
	sfSprite_setPosition(f->pnj[1].sp, d_v(1300, 500));
	sfSprite_setPosition(f->interface[0].sp, d_v(10, 740));
	sfSprite_setPosition(f->interface[1].sp, d_v(840, 920));
	sfSprite_setPosition(f->interface[3].sp, d_v(720, 670));
	sfSprite_setTextureRect(f->pnj[0].sp, f->pnj[0].rect);
	sfSprite_setTextureRect(f->pnj[1].sp, f->pnj[1].rect);
	sfSprite_setTextureRect(f->interface[3].sp, do_irect(0, 0, 30, 22));
	return;
}

void		init_fight(game_t *g, fight_t *f)
{
	f->pos = 0;
	f->bool_pos = 0;
	f->spells = 0;
	f->x_arrow = 840;
	f->y_arrow = 920;
	f->clock = sfClock_create();
	f->menu.menu_bool = 0;
	f->menu.items_bool = 0;
	f->menu.skill_bool = 0;
	f->pnj[0] = init_battle(g->hero_path);
	f->pnj[1] = init_battle("./src/assets/goblinc.png");
	f->interface[3] = create_ui(g->hero_path);
	f->interface[0] = create_ui("./src/assets/battle_ui.png");
	f->interface[2] = create_ui("./src/assets/Grassland2.png");
	f->interface[1] = create_ui("./src/assets/fight_ui_arrow.png");
	f->pnj[0].rect = do_irect(96, 0, 30, 45);
	f->pnj[1].rect = do_irect(32, 0, 30, 32);
	set_fight(f);
	return;
}

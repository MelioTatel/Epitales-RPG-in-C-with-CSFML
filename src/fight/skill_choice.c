/*
** EPITECH PROJECT, 2018
** skill_choice
** File description:
** skill_choice
*/

#include "my_rpg.h"

skill_t		assign_skills_sprites(char *path)
{
	skill_t	skill;

	skill.irect = do_irect(0, 0, 194, 194);
	skill.sp = sfSprite_create();
	skill.text = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(skill.sp, skill.text, sfTrue);
	sfSprite_setTextureRect(skill.sp, skill.irect);
	sfSprite_setPosition(skill.sp, d_v(1300, 500));
	return (skill);
}

void	init_skills_sprites(fight_t *f)
{
	f->skill[0] = assign_skills_sprites("./src/assets/Darkness3.png");
	f->skill[1] = assign_skills_sprites("./src/assets/Fire_tornado.png");
	f->skill[2] = assign_skills_sprites("./src/assets/Heal.png");
	return;
}

void	set_skills_choice(fight_t *f)
{
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyReturn &&
		f->x_arrow == 480 && f->y_arrow == 920)
		f->spells = BLACKHOLE;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyReturn &&
		f->x_arrow == 80 && f->y_arrow == 920)
		f->spells = FIRE_TORNADO;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyReturn &&
		f->x_arrow == 420 && f->y_arrow == 980)
		f->spells = HEAL;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyBack)
		f->spells = NO_SPELL;
	return;
}

void	select_skills_choice_cut(game_t *g, fight_t *f)
{
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyDown
		&& f->x_arrow != 480)
		f->y_arrow = 980;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyUp)
		f->y_arrow = 920;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyLeft)
		f->x_arrow = 80;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyRight
		&& f->y_arrow != 980)
		f->x_arrow = 480;
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyRight
	&& f->y_arrow == 980) {
		f->x_arrow = 480;
		f->y_arrow = 920;
	}
}

void	select_skills_choice(game_t *g, fight_t *f)
{
	select_skills_choice_cut(g, f);
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyDown
	&& f->x_arrow == 480) {
		f->y_arrow = 980;
		f->x_arrow = 80;
	}
	if (f->ev.type == sfEvtKeyPressed && f->ev.key.code == sfKeyBack) {
		f->bool_pos = MENU;
		f->x_arrow = 840;
		f->y_arrow = 980;
		f->menu.skill_bool = 0;
	}
	sfSprite_setPosition(f->interface[1].sp, d_v(f->x_arrow, f->y_arrow));
	set_skills_choice(f);
	return;
}
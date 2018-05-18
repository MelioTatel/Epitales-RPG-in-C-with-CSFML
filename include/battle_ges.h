/*
** EPITECH PROJECT, 2018
** battle_ges
** File description:
** battle_ges
*/

#ifndef BATTLE_GES_H_
# define BATTLE_GES_H_

#include "struct.h"

enum		e_pos
{
	MENU = 0,
	FIGHT = 1,
	SKILLS = 2,
	ITEMS = 3,
	ESCAPE = 4,
	ENNEMY = 5,
};

enum		e_spell
{
	NO_SPELL = 0,
	BLACKHOLE = 1,
	FIRE_TORNADO = 2,
	ARMOR_UP = 3,
	HEROIC_STRIKE = 4,
	BATTLECRY = 8,
	ASSASSINATE = 5,
	STEALTH = 6,
	HEAL = 7,
};

typedef struct		s_battle
{
	sfIntRect	rect;
	sfSprite	*sp;
	sfTexture	*text;
}	battle_t;

typedef struct		s_menu_gest
{
	int	menu_bool;
	int	items_bool;
	int	skill_bool;
}	menu_gest_t;

typedef struct		s_skill
{
	sfSprite	*sp;
	sfTexture	*text;
	sfIntRect	irect;
	sfFloatRect	frect;
}	skill_t;

typedef struct		s_fight
{
	int		pos;
	int		bool_pos;
	int		spells;
	float		x_arrow;
	float		y_arrow;
	sfEvent		ev;
	sfClock		*clock;
	skill_t		skill[3];
	battle_t	pnj[2];
	escape_t	interface[4];
	menu_gest_t	menu;
}	fight_t;

/*
**=============================
**	  INIT_FIGHT
**=============================
*/

void		set_fight(fight_t *);
void		init_fight(game_t *, fight_t *);
void		draw_fight(game_t *, fight_t *);
void		destroy_fight(game_t *, fight_t *);
void		no_spells(sfVector2f, game_t *, fight_t *);

/*
**=============================
**	   MENU SELECT
**=============================
*/

void		set_menu_choice(game_t *, fight_t *);
void		select_menu_choice(game_t *, fight_t *);

/*
**=============================
**  	 SKILLS SELECT
**=============================
*/

void	draw_mage_skill(game_t *, fight_t *);
void	select_skills_choice(game_t *, fight_t *);

int		do_fight(game_t *);

escape_t	create_ui(char *);
battle_t	init_battle(char *);

#endif /* !BATTLE_GES_H_ */

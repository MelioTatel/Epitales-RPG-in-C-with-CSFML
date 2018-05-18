/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_and_anim
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

char	**path_champ(void)
{
	char	**pth = NULL;

	pth = malloc(sizeof(char *) * 5);
	pth[0] = "./src/assets/hero.png";
	pth[1] = "./src/assets/heroine.png";
	pth[2] = NULL;
	return (pth);
}

int	set_select(game_t *it)
{
	sfTexture_setRepeated(it->champ.para_tt, sfTrue);
	sfSprite_setTexture(it->champ.para, it->champ.para_tt, sfTrue);
	sfSprite_setTexture(it->champ.status, it->champ.status_tt, sfTrue);
	sfSprite_setTexture(it->champ.arrow_r, it->champ.arrow_tt_r, sfTrue);
	sfSprite_setTexture(it->champ.arrow_l, it->champ.arrow_tt_l, sfTrue);
	sfSprite_setPosition(it->champ.para, d_v(800, 300));
	sfSprite_setPosition(it->champ.arrow_l, d_v(1730, 500));
	sfSprite_setPosition(it->champ.arrow_r, d_v(90, 500));
	sfSprite_setPosition(it->champ.sprite, d_v(870, 500));
	sfSprite_setScale(it->champ.sprite, d_v(5, 5));
	sfSprite_setScale(it->champ.para, d_v(0.6, 0.6));
	it->champ.para_rect = do_irect(0, 0, 500, 730);
	sfSprite_setTextureRect(it->champ.para, it->champ.para_rect);
	it->champ.arrow_hit_r = sfSprite_getGlobalBounds(it->champ.arrow_r);
	it->champ.arrow_hit_l = sfSprite_getGlobalBounds(it->champ.arrow_l);
}

int	init_select(game_t *it)
{
	char	*para_path = "./src/assets/champ_select/forest_para.png";
	char	*arrow_path_r = "./src/assets/champ_select/arrow_r.png";
	char	*arrow_path_l = "./src/assets/champ_select/arrow_l.png";
	char	*status_path = "./src/assets/champ_select/status_cadre.png";

	it->champ.is_champ = 0;
	it->champ.path = path_champ();
	it->champ.para = sfSprite_create();
	it->champ.sprite = sfSprite_create();
	it->champ.status = sfSprite_create();
	it->champ.arrow_r = sfSprite_create();
	it->champ.arrow_l = sfSprite_create();
	it->champ.para_tt = sfTexture_createFromFile(para_path, NULL);
	it->champ.status_tt = sfTexture_createFromFile(status_path, NULL);
	it->champ.arrow_tt_r = sfTexture_createFromFile(arrow_path_l, NULL);
	it->champ.arrow_tt_l = sfTexture_createFromFile(arrow_path_r, NULL);
	set_select(it);
	return (0);
}

int	champ_anim(game_t *g, int *nb_run, sfIntRect *border, sfClock *anim)
{
	if (sfTime_asMilliseconds(sfClock_getElapsedTime(anim)) > 300) {
		border->left += 32;
		sfClock_restart(anim);
	}
	if (border->left >= 90) {
		(*nb_run)++;
		border->left = 0;
	}
	return (0);
}

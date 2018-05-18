/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** champ_select
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

int	champ_loop(game_t *g, sfIntRect *border, sfClock *anim, int *nb_run)
{
	champ_anim(g, nb_run, border, anim);
	sfSprite_setTextureRect(g->champ.sprite, *border);
	sfRenderWindow_drawSprite(g->video.win, g->champ.para, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->champ.status, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[11].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[11].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->champ.arrow_r, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->champ.arrow_l, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->champ.sprite, NULL);
	sfSprite_setTextureRect(g->champ.para, g->champ.para_rect);
	sfTexture_destroy(g->champ.texture);
	g->champ.para_rect.left += 1;
	return (0);
}

int	champ_select(game_t *g)
{
	int		a = 0;
	sfIntRect	border = {0, 0, 30, 45};
	sfClock		*anim;
	int		nb_run = 0;

	if (g->champ.is_champ != 0 && g->champ.is_champ != -1)
		return (g->champ.is_champ);
	anim = sfClock_create();
	while (g->champ.is_champ == 0) {
		champ_event(g, &a, &border);
		g->champ.texture = sfTexture_createFromFile
		(g->champ.path[a], NULL);
		sfSprite_setTexture(g->champ.sprite, g->champ.texture, sfTrue);
		sfRenderWindow_clear(g->video.win, sfBlack);
		draw_status(g, &a);
		champ_loop(g, &border, anim, &nb_run);
		sfRenderWindow_display(g->video.win);
	}
	g->hero_path = g->champ.path[a];
	g->champ.is_champ = 0;
	return (0);
}

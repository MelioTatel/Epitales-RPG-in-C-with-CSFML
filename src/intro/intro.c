/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** intro
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

char	**path_intro(void)
{
	char	**pth = NULL;

	pth = malloc(sizeof(char *) * 3);
	pth[0] = "./src/assets/intro1.png";
	pth[1] = "./src/assets/intro2.png";
	pth[2] = NULL;
	return (pth);
}

int	init_intro(game_t *it)
{
	it->intro.bool_intro = 0;
	it->intro.path = path_intro();
	it->intro.sprite = sfSprite_create();
	it->intro.timer = sfClock_create();
	return (0);
}

int	introduction_event(game_t *g)
{
	sfEvent e = g->intro.event;

	while (sfRenderWindow_pollEvent(g->video.win, &e)) {
		if (e.type == sfEvtKeyPressed)
			return (1);
		if (e.type == sfEvtClosed) {
			sfRenderWindow_close(g->video.win);
			return (1);
		}
	}
}

void	loop_intro(game_t *g, int *a)
{
	g->intro.texture = sfTexture_createFromFile(g->intro.path[*a], NULL);
	sfSprite_setTexture(g->intro.sprite, g->intro.texture, sfTrue);
	sfRenderWindow_drawSprite(g->video.win, g->intro.sprite, NULL);
	if (sfTime_asMilliseconds
	(sfClock_getElapsedTime(g->intro.timer)) > 2500) {
		(*a)++;
		sfClock_restart(g->intro.timer);
	}
	sfRenderWindow_display(g->video.win);
	sfRenderWindow_clear(g->video.win, sfBlack);
	sfTexture_destroy(g->intro.texture);
	if (introduction_event(g) == 1)
		g->intro.bool_intro = 1;
}

void	introduction(game_t *g)
{
	int	a = 0;

	if (g->intro.bool_intro == 1)
		return;
	while (g->intro.path[a] != NULL && g->intro.bool_intro == 0)
		loop_intro(g, &a);
	g->intro.bool_intro = 1;
}


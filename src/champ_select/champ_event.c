/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** champ_event
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

int	champ_mouse_event2(game_t *g, int *a, sfEvent ev)
{
	int	x = ev.mouseButton.x;
	int	y = ev.mouseButton.y;

	if (ev.mouseButton.button == sfMouseLeft) {
		if (sfFloatRect_contains(&g->menu[11].hitbox, x, y)) {
			g->menu[0].rbut.top = 79;
			g->menu[0].rbut.left = 0;
			sfSprite_setTextureRect
			(g->menu[11].sprite, g->menu[0].rbut);
		}
	}
}

int	champ_mouse_event(game_t *g, int *a, sfEvent ev)
{
	int	x = ev.mouseButton.x;
	int	y = ev.mouseButton.y;

	g->menu[0].rbut.top = 0;
	g->menu[0].rbut.left = 0;
	sfSprite_setTextureRect(g->menu[11].sprite, g->menu[0].rbut);
	if (ev.mouseButton.button == sfMouseLeft) {
		if (sfFloatRect_contains(&g->champ.arrow_hit_r,
			ev.mouseButton.x, ev.mouseButton.y))
			*a -= 1;
		if (sfFloatRect_contains(&g->champ.arrow_hit_l,
			ev.mouseButton.x, ev.mouseButton.y))
			*a += 1;
	}
	if (ev.mouseButton.button == sfMouseLeft) {
		if (sfFloatRect_contains(&g->menu[11].hitbox, x, y)) {
			g->champ.is_champ = -1;
			g->bool_pos = 1;
		}
	}
}

int	champ_is_mouse_event(game_t *g, int *a, sfIntRect *border, sfEvent ev)
{
	if (ev.type == sfEvtMouseMoved)
		check_for_visual(g, ev);
	if (ev.type == sfEvtMouseButtonReleased)
		champ_mouse_event(g, a, ev);
	if (ev.type == sfEvtMouseButtonPressed)
		champ_mouse_event2(g, a, ev);
}

int	champ_event(game_t *g, int *a, sfIntRect *border)
{
	sfEvent	ev;

	while (sfRenderWindow_pollEvent(g->video.win, &ev)) {
		reset_size(g, ev);
		champ_is_mouse_event(g, a, border, ev);
		if (ev.type == sfEvtKeyReleased)
			event_key_pressed(g, ev, border);
		if (ev.type == sfEvtClosed) {
			sfRenderWindow_close(g->video.win);
			g->champ.is_champ = -1;
		}
	}
	if (*a < 0)
		*a = 1;
	if (g->champ.path[*a] == NULL)
		*a = 0;
	return (0);
}

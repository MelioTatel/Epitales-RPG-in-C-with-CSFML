/*
** EPITECH PROJECT, 2018
** move player
** File description:
** move the player
*/

#include "my_rpg.h"

int	check_contain(sfFloatRect frect, bounds_t *tmp)
{
	int	boo = 0;

	for (boo = 0; tmp && boo == 0; tmp = tmp->next)
		if (sfFloatRect_intersects(&frect,
			&tmp->rect, NULL) == sfTrue)
			boo = 1;
	if (boo == 1)
		return (1);
	return (0);
}

int	pnj_intersect_cut(cre_pnj_t *pnj, cre_sprite_t *hero,
int *boo, game_t *g)
{
	pnj->frect.top += -8;
	if (sfFloatRect_intersects(&pnj->frect,
		&hero->frect, NULL) == sfTrue)
		*boo = 1;
	if (*boo == 1) {
		g->pnj[0].rect.top = 142;
		return (1);
	}
	pnj->frect.left += -8;
	if (sfFloatRect_intersects(&pnj->frect,
		&hero->frect, NULL) == sfTrue)
		*boo = 1;
	if (*boo == 1) {
		g->pnj[0].rect.top = 47;
		return (1);
	}
}

int	pnj_intersect(game_t *g, cre_pnj_t pnj, cre_sprite_t hero)
{
	int		boo = 0;

	pnj.frect.top += 4;
	if (sfFloatRect_intersects(&pnj.frect,
		&hero.frect, NULL) == sfTrue)
		boo = 1;
	if (boo == 1) {
		g->pnj[0].rect.top = 0;
		return (1);
	}
	pnj.frect.left += 4;
	if (sfFloatRect_intersects(&pnj.frect,
		&hero.frect, NULL) == sfTrue)
		boo = 1;
	if (boo == 1) {
		g->pnj[0].rect.top = 95;
		return (1);
	}
	pnj_intersect_cut(&pnj, &hero, &boo, g);
	return (0);
}

int	detect_event(game_t *g, sfEvent ev)
{
	if (ev.type == sfEvtMouseButtonPressed)
		if (ev.mouseButton.button == sfMouseLeft)
			change_state(g, ev);
	if (ev.type == sfEvtMouseButtonReleased &&
	ev.mouseButton.button == sfMouseLeft) {
		reset_all(g);
		if (g->bool_pos == 0)
			in_menu(g, ev);
		if (g->bool_pos == 11 || g->bool_pos == 12)
			in_options(g, ev);
		if (g->bool_pos == 8 || g->bool_pos == 9)
			in_quit(g, ev);
		if (g->bool_pos == 10)
			pause_in_game(g, ev);
	}
	return (0);
}

int	my_event(game_t *g, bounds_t *tmp)
{
	sfEvent	ev;

	while (sfRenderWindow_pollEvent(g->video.win, &ev)) {
		verif_save(g, ev);
		move_right(g, tmp, ev);
		move_up(g, tmp, ev);
		move_down(g, tmp, ev);
		move_left(g, tmp, ev);
		reset_size(g, ev);
		detect_event(g, ev);
		if (ev.type == sfEvtKeyReleased)
			key_event(g, ev);
		if (ev.type == sfEvtMouseMoved)
			check_for_visual(g, ev);
		if (ev.type == sfEvtClosed)
			sfRenderWindow_close(g->video.win);
	}
	return (0);
}

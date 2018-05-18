/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** key pressed
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	event_key_pressed(game_t *g, sfEvent ev, sfIntRect *border)
{
	if (ev.key.code == sfKeyDown)
		border->top = 0;
	if (ev.key.code == sfKeyLeft)
		border->top = 47;
	if (ev.key.code == sfKeyRight)
		border->top = 96;
	if (ev.key.code == sfKeyUp)
		border->top = 144;
	if (ev.key.code == sfKeyReturn) {
		g->champ.is_champ = -1;
		g->bool_pos = 1;
	}
	if (ev.key.code == sfKeyEscape) {
		g->champ.is_champ = -1;
		g->bool_pos = 0;
	}
	return;
}

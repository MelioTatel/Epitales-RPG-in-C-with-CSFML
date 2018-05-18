/*
** EPITECH PROJECT, 2018
** pnj
** File description:
** pnj
*/

#ifndef PNJ_H_
#define PNJ_H_

#include <SFML/Graphics.h>
#include "struct.h"

/*
**===================================
**	   Old Lady Pnj
**===================================
*/

void	move_old_pnj_up(game_t *);
void	move_old_pnj_down(game_t *);
void	move_old_pnj_left(game_t *);
void	move_old_pnj_right(game_t *);

void	rotate_old_lady(game_t *);
void	set_old_lady_dialog(game_t *);
void	draw_old_lady_dialog(int **, sfVector2f **, game_t *);

int	old_pnj_dialog(game_t *, int **, sfVector2f **);
int	pnj_intersect(game_t *, cre_pnj_t, cre_sprite_t);
int	check_contain(sfFloatRect, bounds_t *);

/*
**===================================
**	   Goblin Mage
**===================================
*/

void	rotate_goblinc(game_t *);

#endif /* !PNJ_H_ */

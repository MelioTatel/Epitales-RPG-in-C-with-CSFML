/*
** EPITECH PROJECT, 2018
** draw fight
** File description:
** draw fight
*/

#include "my_rpg.h"

void		battle_sprite(game_t *g, fight_t *f)
{
	sfRenderWindow_drawSprite(g->video.win, f->interface[2].sp, NULL);
	sfRenderWindow_drawSprite(g->video.win, f->interface[0].sp, NULL);
	sfRenderWindow_drawSprite(g->video.win, f->interface[1].sp, NULL);
	sfRenderWindow_drawSprite(g->video.win, f->interface[3].sp, NULL);
	sfRenderWindow_drawSprite(g->video.win, f->pnj[0].sp, NULL);
	sfRenderWindow_drawSprite(g->video.win, f->pnj[1].sp, NULL);
	draw_mage_skill(g, f);
	return;
}

void		battle_text(game_t *g, fight_t *f)
{
	sfRenderWindow_drawText(g->video.win, g->menu[12].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[13].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[14].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[15].text, NULL);
	if (f->bool_pos == SKILLS) {
		sfRenderWindow_drawText(g->video.win, g->menu[16].text, NULL);
		sfRenderWindow_drawText(g->video.win, g->menu[17].text, NULL);
		sfRenderWindow_drawText(g->video.win, g->menu[18].text, NULL);
	}
	return;
}

void		draw_fight(game_t *g, fight_t *f)
{
	sfRenderWindow_clear(g->video.win, sfBlack);
	battle_sprite(g, f);
	battle_text(g, f);
	sfRenderWindow_display(g->video.win);
	sfSprite_setTextureRect(f->pnj[0].sp, f->pnj[0].rect);
	sfSprite_setTextureRect(f->pnj[1].sp, f->pnj[1].rect);
	if (Clock2 > 200) {
		f->pnj[0].rect.left += 30;
		f->pnj[1].rect.left += 30;
		if (f->pnj[0].rect.left > 60)
			f->pnj[0].rect.left = 0;
		if (f->pnj[1].rect.left > 60)
			f->pnj[1].rect.left = 0;
		sfClock_restart(f->clock);
	}
	return;
}

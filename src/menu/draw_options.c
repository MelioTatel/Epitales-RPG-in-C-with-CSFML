/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** options draw
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	draw_icone(game_t *g)
{
	sfSprite_setPosition(g->msc.on, d_v(870, 185));
	sfSprite_setScale(g->msc.on, d_v(1.4, 1.4));
	sfSprite_setPosition(g->msc.off, d_v(870, 185));
	sfSprite_setScale(g->msc.off, d_v(1.4, 1.4));
	if ((g->msc.bs % 2) == 0) {
		sfRenderWindow_drawSprite(g->video.win, g->msc.on, NULL);
		sfMusic_setVolume(g->msc.music, g->msc.vol);
	}
	else {
		sfRenderWindow_drawSprite(g->video.win, g->msc.off, NULL);
		sfMusic_setVolume(g->msc.music, 0);
	}
}

void	draw_options(game_t *g)
{
	sfIntRect	area = do_irect(0, 0, 64, 64);
	int		state = 6;

	sfRenderWindow_drawSprite(g->video.win, g->menu->bg_m, NULL);
	draw_icone(g);
	sfRenderWindow_drawText(g->video.win, g->menu[3].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[4].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[5].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[5].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[6].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[6].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[7].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[8].text, NULL);
	state = g->opt.pos - 1;
	area.left = 64 * state;
	sfSprite_setTextureRect(g->opt.sprite, area);
	sfSprite_setScale(g->opt.sprite, d_v(4.7, 3));
	sfRenderWindow_drawSprite(g->video.win, g->opt.sprite, NULL);
}

void	draw_opt_ig(game_t *g)
{
	sfIntRect	area = do_irect(0, 0, 64, 64);
	int		state = 6;

	draw_icone(g);
	sfRenderWindow_drawText(g->video.win, g->menu[3].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[4].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[5].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[5].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[6].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[6].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[7].text, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[8].text, NULL);
	state = g->opt.pos - 1;
	area.left = 64 * state;
	sfSprite_setTextureRect(g->opt.sprite, area);
	sfSprite_setScale(g->opt.sprite, d_v(4.7, 3));
	sfRenderWindow_drawSprite(g->video.win, g->opt.sprite, NULL);
}

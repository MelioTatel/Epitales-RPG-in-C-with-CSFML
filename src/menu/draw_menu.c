/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** draw all menu
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	reset_pos(game_t *g)
{
	sfSprite_setPosition(g->menu[0].sprite, d_v(940, 400));
	sfText_setPosition(g->menu[0].text, d_v(940, 400));
	sfSprite_setPosition(g->menu[1].sprite, d_v(940, 630));
	sfText_setPosition(g->menu[1].text, d_v(940, 630));
	sfSprite_setPosition(g->menu[2].sprite, d_v(940, 860));
	sfText_setPosition(g->menu[2].text, d_v(940, 860));
	g->menu[0].hitbox = sfSprite_getGlobalBounds(g->menu[0].sprite);
	g->menu[1].hitbox = sfSprite_getGlobalBounds(g->menu[1].sprite);
	g->menu[2].hitbox = sfSprite_getGlobalBounds(g->menu[2].sprite);
}

void	draw_menu(game_t *g)
{
	static sfIntRect	area = {0, 0, 682, 884};

	sfRenderWindow_drawSprite(g->video.win, g->menu->bg_m, NULL);
	reset_pos(g);
	g->menu->time = sfClock_getElapsedTime(g->menu->clock);
	if (sfTime_asMilliseconds(g->menu->time) > 300) {
		if (area.left > 1024)
			area.left = 0;
		else
			area.left += 682;
		sfSprite_setTextureRect(g->menu[0].sw, area);
		sfClock_restart(g->menu->clock);
	}
	sfSprite_setTextureRect(g->menu[0].sw, area);
	sfRenderWindow_drawSprite(g->video.win, g->menu[0].sw, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[0].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[0].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[1].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[1].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[2].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[2].text, NULL);
}

void	reset_size2(game_t *g, sfEvent e)
{
	sfSprite_setScale(g->menu[5].sprite, d_v(g->menu[5].x_sca +
	0.27, g->menu[5].y_sca + 0.27));
	sfSprite_setScale(g->menu[6].sprite, d_v(g->menu[6].x_sca + 0.27,
	g->menu[6].y_sca + 0.27));
	sfSprite_setScale(g->menu[9].sprite, d_v(g->menu[9].x_sca + 0.27,
	g->menu[9].y_sca + 0.27));
	sfSprite_setScale(g->menu[10].sprite, d_v(g->menu[10].x_sca + 0.27,
	g->menu[10].y_sca + 0.27));
	sfSprite_setScale(g->menu[11].sprite, d_v(g->menu[11].x_sca + 0.27,
	g->menu[11].y_sca + 0.27));
	sfText_setScale(g->menu[5].text, d_v(g->menu[9].x_sca,
	g->menu[9].y_sca));
	sfText_setScale(g->menu[6].text, d_v(g->menu[10].x_sca,
	g->menu[10].y_sca));
	sfText_setScale(g->menu[9].text, d_v(g->menu[9].x_sca,
	g->menu[9].y_sca));
	sfText_setScale(g->menu[10].text, d_v(g->menu[10].x_sca,
	g->menu[10].y_sca));
	sfText_setScale(g->menu[11].text, d_v(g->menu[11].x_sca,
	g->menu[11].y_sca));
}

void	reset_size(game_t *g, sfEvent e)
{
	sfSprite_setScale(g->menu[0].sprite, d_v(g->menu[0].x_sca + 0.27,
	g->menu[0].y_sca + 0.27));
	sfSprite_setScale(g->menu[1].sprite, d_v(g->menu[1].x_sca + 0.27,
	g->menu[1].y_sca + 0.27));
	sfSprite_setScale(g->menu[2].sprite, d_v(g->menu[2].x_sca + 0.27,
	g->menu[2].y_sca + 0.27));
	sfSprite_setScale(g->menu[19].sprite, d_v(g->menu[19].x_sca + 0.27,
	g->menu[19].y_sca + 0.27));
	sfText_setScale(g->menu[0].text, d_v(g->menu[0].x_sca,
	g->menu[0].y_sca));
	sfText_setScale(g->menu[1].text, d_v(g->menu[1].x_sca,
	g->menu[1].y_sca));
	sfText_setScale(g->menu[2].text, d_v(g->menu[2].x_sca,
	g->menu[2].y_sca));
	sfText_setScale(g->menu[19].text, d_v(g->menu[19].x_sca,
	g->menu[19].y_sca));
	reset_size2(g, e);
}

/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** draw pause
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	draw_pause(game_t *g)
{
	sfRenderWindow_drawSprite(g->video.win, g->menu->bg_m, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[0].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[0].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->pause.sprite, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[9].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[9].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[10].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[10].text, NULL);
}

void	ask_quit_ig(game_t *g)
{
	sfRenderWindow_drawSprite(g->video.win, g->pause.sprite, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[9].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[9].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[10].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[10].text, NULL);
}

void	draw_pause_ingame(game_t *g)
{
	sfSprite_setPosition(g->menu[19].sprite, d_v(940, 250));
	sfText_setPosition(g->menu[19].text, d_v(940, 250));
	sfSprite_setPosition(g->menu[1].sprite, d_v(940, 480));
	sfText_setPosition(g->menu[1].text, d_v(940, 480));
	sfSprite_setPosition(g->menu[2].sprite, d_v(940, 710));
	sfText_setPosition(g->menu[2].text, d_v(940, 710));
	g->menu[19].hitbox = sfSprite_getGlobalBounds(g->menu[19].sprite);
	g->menu[1].hitbox = sfSprite_getGlobalBounds(g->menu[1].sprite);
	g->menu[2].hitbox = sfSprite_getGlobalBounds(g->menu[2].sprite);
	sfRenderWindow_drawSprite(g->video.win, g->menu[19].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[19].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[1].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[1].text, NULL);
	sfRenderWindow_drawSprite(g->video.win, g->menu[2].sprite, NULL);
	sfRenderWindow_drawText(g->video.win, g->menu[2].text, NULL);
}

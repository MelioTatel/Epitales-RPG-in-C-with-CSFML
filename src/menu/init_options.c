/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init options
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	init_options(game_t *g)
{
	g->opt.pos = 6;
	g->opt.texture = sfTexture_createFromFile("./src/assets/volume.png"
	, NULL);
	g->opt.sprite = sfSprite_create();
	sfSprite_setTexture(g->opt.sprite, g->opt.texture, sfTrue);
	g->menu->bg_menu = sfTexture_createFromFile("./src/assets/BG_MENU.png"
	, NULL);
	g->menu->bg_m = sfSprite_create();
	sfSprite_setTexture(g->menu->bg_m, g->menu->bg_menu, sfTrue);
	g->menu[0].sword = sfTexture_createFromFile("./src/assets/sword.png"
	, NULL);
	g->menu[0].sw = sfSprite_create();
	sfSprite_setTexture(g->menu[0].sw, g->menu[0].sword, sfTrue);
	sfSprite_setPosition(g->opt.sprite, d_v(800, 364));
	g->menu->clock = sfClock_create();
	sfSprite_setPosition(g->menu[0].sw, d_v(580, -60));
	sfSprite_setScale(g->menu[0].sw, d_v(1, 1.2));
}

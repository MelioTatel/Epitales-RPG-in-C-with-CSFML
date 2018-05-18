/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_menu
*/

#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "linked_list.h"
#include "struct.h"
#include "my_rpg.h"

int	create_data(game_t *g, int i, list_conf_t *tmp)
{
	sfIntRect	rbut = {0, 0, 175, 79};

	g->menu[i].texture = sfTexture_createFromFile
	("./src/assets/but.png", NULL);
	g->menu[i].sprite = sfSprite_create();
	sfSprite_setTexture(g->menu[i].sprite, g->menu[i].texture, sfTrue);
	g->menu[i].text = sfText_create();
	sfText_setFont(g->menu[i].text, g->menu[0].police);
	sfText_setString(g->menu[i].text, tmp->data[0]);
	g->menu[i].x_pos = my_getnbr(tmp->data[1]);
	g->menu[i].y_pos = my_getnbr(tmp->data[2]);
	g->menu[i].x_sca = my_atof(tmp->data[3]);
	g->menu[i].y_sca = my_atof(tmp->data[4]);
	g->menu[0].rbut = rbut;
	return (0);
}

int	set_data(game_t *g, int i, list_conf_t *tmp)
{
	sfFloatRect	rect;

	sfSprite_setTextureRect(g->menu[i].sprite, g->menu[0].rbut);
	rect = sfText_getGlobalBounds(g->menu[i].text);
	sfSprite_setOrigin(g->menu[i].sprite, d_v(90, 32));
	sfText_setOrigin(g->menu[i].text, d_v(rect.width / 2,
	rect.height / 2));
	sfText_setPosition(g->menu[i].text, d_v(g->menu[i].x_pos,
	g->menu[i].y_pos));
	sfText_setScale(g->menu[i].text, d_v(g->menu[i].x_sca,
	g->menu[i].y_sca));
	sfSprite_setScale(g->menu[i].sprite, d_v(g->menu[i].x_sca + 0.27,
	g->menu[i].y_sca + 0.27));
	sfSprite_setPosition(g->menu[i].sprite, d_v(840 + g->menu[i].x_pos,
	150 + g->menu[i].y_pos));
	sfText_setPosition(g->menu[i].text, d_v(840 + g->menu[i].x_pos,
	150 + g->menu[i].y_pos));
	g->menu[i].hitbox = sfSprite_getGlobalBounds(g->menu[i].sprite);
}

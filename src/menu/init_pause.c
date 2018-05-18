/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** pause
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	init_pause(game_t *g)
{
	char	*path = "./src/assets/pause.png";
	g->pause.texture = sfTexture_createFromFile(path, NULL);
	g->pause.sprite = sfSprite_create();
	sfSprite_setTexture(g->pause.sprite, g->pause.texture, sfTrue);
}

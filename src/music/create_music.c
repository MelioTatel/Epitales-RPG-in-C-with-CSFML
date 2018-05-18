/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** music
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void	create_music(game_t *g)
{
	char	*music = "./src/assets/music/Hearthstone.ogg";
	char	*on = "./src/assets/music/sound_on.png";
	char	*off = "./src/assets/music/sound_off.png";

	g->msc.bs = 0;
	g->msc.vol = 50;
	g->msc.music = sfMusic_createFromFile(music);
	g->msc.on = sfSprite_create();
	g->msc.off = sfSprite_create();
	g->msc.s_on = sfTexture_createFromFile(on, NULL);
	g->msc.s_off = sfTexture_createFromFile(off, NULL);
	sfSprite_setTexture(g->msc.on, g->msc.s_on, sfTrue);
	sfSprite_setTexture(g->msc.off, g->msc.s_off, sfTrue);
	sfMusic_setVolume(g->msc.music, g->msc.vol);
}

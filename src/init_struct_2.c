/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_struct_2
*/


#include <SFML/Graphics.h>
#include "my_rpg.h"

cre_pnj_t	init_pnj_sprite(char *path, sfIntRect borders)
{
	cre_pnj_t	pnj;

	pnj.text = sfTexture_createFromFile(path, NULL);
	pnj.sp = sfSprite_create();
	pnj.rect = borders;
	sfSprite_setTexture(pnj.sp, pnj.text, sfTrue);
	sfSprite_setTextureRect(pnj.sp, pnj.rect);
	return (pnj);
}

cre_sprite_t	init_sprite(char *path)
{
	cre_sprite_t	graph;

	graph.text = sfTexture_createFromFile(path, NULL);
	graph.sp = sfSprite_create();
	sfSprite_setTexture(graph.sp, graph.text, sfTrue);
	return (graph);
}

cre_grass_t	init_grass_sprite(char *path)
{
	cre_grass_t	graph;

	graph.text = sfTexture_createFromFile(path, NULL);
	graph.sp = sfSprite_create();
	sfSprite_setTexture(graph.sp, graph.text, sfTrue);
	return (graph);
}

dialog_t	init_dialog(char *path)
{
	dialog_t	dial;

	dial.text = sfTexture_createFromFile(path, NULL);
	dial.sp = sfSprite_create();
	sfSprite_setTexture(dial.sp, dial.text, sfTrue);
	return (dial);
}

int	init_pnj(game_t *g)
{
	char	*path = "./src/assets/old_lady2.png";
	char	*path2 = "./src/assets/goblinc.png";

	g->pnj[0] = init_pnj_sprite(path, do_irect(0, 0, 30, 39));
	sfSprite_setPosition(g->pnj[0].sp, d_v(400, 400));
	g->pnj[0].obstacle = 0;
	g->pnj[0].rotate = 0;
	g->pnj[1] = init_pnj_sprite(path2, do_irect(0, 0, 30, 32));
	sfSprite_setPosition(g->pnj[1].sp, d_v(75, 800));
	g->pnj[1].obstacle = 0;
	g->pnj[1].rotate = 0;
	g->pnj[1].classe = mag_monster();
	return (0);
}

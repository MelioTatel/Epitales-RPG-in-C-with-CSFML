/*
** EPITECH PROJECT, 2018
** init_struct
** File description:
** init all the struct
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

int	init_grass(game_t *g)
{
	g->ground[0] = init_grass_sprite("./src/assets/Ground/grass_rpg.png");
	g->ground[1] = init_grass_sprite("./src/assets/Ground/Bridge.png");
	g->ground[2] = init_grass_sprite("./src/assets/Ground/Tree.png");
	g->ground[3] = init_grass_sprite("./src/assets/Ground/mountain.png");
	g->ground[4] = init_grass_sprite(
	"./src/assets/Ground/right_border.png");
	g->ground[5] = init_grass_sprite(
	"./src/assets/Ground/top_left_corner.png");
	g->ground[6] = init_grass_sprite(
	"./src/assets/Ground/top_right_corner.png");
	g->ground[7] = init_grass_sprite("./src/assets/Ground/water1.png");
	return (0);
}

int	init_graph(game_t *g)
{
	g->graph[0] = init_sprite("./src/assets/Ground/grass_rpg.png");
	g->graph[1] = init_sprite("./src/assets/Ground/water1.png");
	g->graph[1].clock = sfClock_create();
	g->graph[1].clock_bool = 0;
	g->graph[1].clock = sfClock_create();
	g->graph[1].clock_bool = 0;
	return (0);
}

escape_t	init_escape(char *path)
{
	escape_t	es;

	es.text = sfTexture_createFromFile(path, NULL);
	es.sp = sfSprite_create();
	sfSprite_setTexture(es.sp, es.text, sfTrue);
	return (es);
}

int	init_all(game_t *g)
{
	init_inv(g);
	init_pnj(g);
	init_graph(g);
	init_win(&g->video);
	init_intro(g);
	init_class(g->init_class);
	init_select(g);
	init_grass(g);
	g->escape = init_escape("./src/assets/escape.png");
	g->map_opt = NULL;
	if (get_map_file(&g->map_opt) == -1)
		return (84);
	g->bounds = NULL;
	g->pnj[0].frect = sfSprite_getGlobalBounds(g->pnj[0].sp);
	g->get_bounds = 0;
	return (0);
}

int	init_win(win_t *v)
{
	char	n[] = "Tales of Epitech";

	v->mode.width = 1920;
	v->mode.height = 1080;
	v->mode.bitsPerPixel = 60;
	v->win = sfRenderWindow_create(v->mode, n, sfClose | sfResize, NULL);
	if (!v->win)
		return (-1);
	v->states.shader = NULL;
	v->states.texture = NULL;
	v->states.transform = sfTransform_Identity;
	v->states.blendMode = sfBlendNone;
	return (0);
}

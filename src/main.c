/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "my_rpg.h"

int	my_rpg(void)
{
	void		*r = malloc(1);
	game_t		g;
	sfVector2f	**map2d;
	bounds_t	*tmp;
	int		**map3d = create_3d_map();

	srand((unsigned long)r);
	if (init_all(&g) == 84)
		return (84);
	modif_map(&g.map_opt, map3d);
	map2d = create_2d_map(map3d);
	draw_2d_map(map2d, map3d, &g);
	tmp = g.bounds;
	g.get_bounds = 1;
	g.fight_bool = 0;
	if (my_menu(&g) == 1)
		return (84);
	while (sfRenderWindow_isOpen(g.video.win))
		do_boucle(&g, map2d, map3d, tmp);
	destroy_ev(&g, map3d);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int		status = 0;

	status = check(ac, av, env);
	if (status == -1)
		return (84);
	if (status == 1)
		return (0);
	return (my_rpg());
}

/*
** EPITECH PROJECT, 2018
** vertex
** File description:
** vertex
*/

#include <math.h>
#include <stdlib.h>
#include "my_rpg.h"

sfVertexArray	*create_tile(sfVector2f *p1, sfVector2f *p2,
sfVector2f *p3, sfVector2f *p4)
{
	sfVertexArray	*vertex_array = sfVertexArray_create();
	sfVertex	vertex1 = {.position = *p1, .color = sfWhite};
	sfVertex	vertex2 = {.position = *p2, .color = sfWhite};
	sfVertex	vertex3 = {.position = *p3, .color = sfWhite};
	sfVertex	vertex4 = {.position = *p4, .color = sfWhite};

	vertex1.texCoords = d_v(0, 0);
	vertex2.texCoords = d_v(150, 0);
	vertex3.texCoords = d_v(150, 150);
	vertex4.texCoords = d_v(0, 150);
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}

sfVector2f	project_iso_point(int point_x, int point_y, int point_z)
{
	int	x = point_x;
	int	y = point_y;
	int	z = point_z;
	double	angle_x = 45 * M_PI / 180;
	double	angle_y = 35 * M_PI / 180;
	sfVector2f	point;

	point.x = x;
	point.y = y;
	return (point);
}

sfVector2f	**create_2d_map(int **map3d)
{
	int		z = 0;
	int		x1 = 0;
	int		y1 = 0;
	sfVector2f	**map2d;

	map2d = malloc(sizeof(*map2d) * MAP_Y);
	for (int y = 0; y < MAP_Y; y += 1) {
		map2d[y] = malloc(sizeof(*map2d[y]) * MAP_X);
		for (int x = 0; x < MAP_X; x += 1) {
			x1 = x * SCALING_X;
			y1 = y * SCALING_Y;
			z = map3d[y][x] * SCALING_Z;
			map2d[y][x] = project_iso_point(x1, y1, z);
		}
	}
	return (map2d);
}

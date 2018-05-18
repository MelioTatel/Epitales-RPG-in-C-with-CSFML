/*
** EPITECH PROJECT, 2018
** draw_tools
** File description:
** draw_tools
*/

#include "my_rpg.h"

sfIntRect	do_irect(int t, int left, int width, int height)
{
	sfIntRect	rectangle;

	rectangle.top = t;
	rectangle.left = left;
	rectangle.width = width;
	rectangle.height = height;
	return (rectangle);
}

sfFloatRect	do_rect(float t, float left, float width, float height)
{
	sfFloatRect	rectangle;

	rectangle.top = t;
	rectangle.left = left;
	rectangle.width = width;
	rectangle.height = height;
	return (rectangle);
}

sfVector2f		d_v(float x, float y)
{
	sfVector2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

sfColor	d_c(unsigned char r, unsigned char g, char b, char a)
{
	sfColor	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

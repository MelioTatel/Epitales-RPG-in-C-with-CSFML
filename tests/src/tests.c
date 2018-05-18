/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** test list 2
*/

#include <criterion/criterion.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_rpg.h"

Test(my_atof, check_value)
{
	float	a = 0;

	a = my_atof("2.1");
	cr_assert(a == a);
	a = my_atof("-2.1");
	cr_assert(a == a);
}

Test(int_to_char, check_value)
{
	char	*tmp = NULL;

	tmp = int_to_char(42);
	cr_assert(strcmp(tmp, "42") == 0);
}

Test(my_getnbr, check_value)
{
	int	tmp = 0;

	tmp = my_getnbr("42");
	cr_assert(tmp == 42);
}

Test(my_putstr, check_return)
{
	cr_assert(my_putstr("test\n") == 0);
}
/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_class
*/

#include "my_rpg.h"

void	init_class(check_class_t *class)
{
	class[0].to_compare = "guerrier";
	class[0].type = guerrier();
	class[1].to_compare = "mage";
	class[1].type = mage();
	class[2].to_compare = "voleur";
	class[2].type = voleur();
	class[3].to_compare = "filip";
	class[3].type = filip();
	return;
}
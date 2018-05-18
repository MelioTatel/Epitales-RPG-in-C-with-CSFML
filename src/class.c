/*
** EPITECH PROJECT, 2018
** class
** File description:
** different class
*/

#include "my_rpg.h"

class_t	mag_monster(void)
{
	class_t	class;

	class.hp = 50;
	class.def = 0;
	class.dmg = 10;
	class.agi = 0;
	class.mag = 10;
	return (class);
}

class_t	guerrier(void)
{
	class_t	class;

	class.hp = 100;
	class.def = 9;
	class.dmg = 11;
	class.agi = 4;
	class.mag = 3;
	return (class);
}

class_t	mage(void)
{
	class_t	class;

	class.hp = 80;
	class.def = 4;
	class.dmg = 6;
	class.agi = 3;
	class.mag = 13;
	return (class);
}

class_t	voleur(void)
{
	class_t	class;

	class.hp = 90;
	class.def = 5;
	class.dmg = 9;
	class.agi = 10;
	class.mag = 2;
	return (class);
}

class_t	filip(void)
{
	class_t	class;

	class.hp = 70;
	class.def = 7;
	class.dmg = 7;
	class.agi = 7;
	class.mag = 7;
	return (class);
}

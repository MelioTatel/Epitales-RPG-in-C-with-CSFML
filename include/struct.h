/*
** EPITECH PROJECT, 2018
** struct
** File description:
** header struct
*/

#ifndef STRUCT_H_
#	define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "linked_list.h"

enum	e_grass
{
	FLAT = 0,
	WATER = 7,
	DLCORNER = 1,
	DRCORNER = 2,
	LBORDER = 3,
	RBORDER = 4,
	TLCORNER = 5,
	TRCORNER = 6,
	MOUNTAIN = 8,
};

typedef struct		s_bounds
{
	sfFloatRect	rect;
	struct s_bounds	*next;
}	bounds_t;

/*****************************************/
/* Struct for champ select		 */
/* 					 */
/*****************************************/

typedef struct		s_champ
{
	int		is_champ;
	char		**path;
	sfIntRect	para_rect;
	sfFloatRect	arrow_hit_r;
	sfFloatRect	arrow_hit_l;
	sfSprite	*arrow_r;
	sfSprite	*arrow_l;
	sfSprite	*cadre;
	sfSprite	*para;
	sfSprite	*status;
	sfTexture	*cadre_tt;
	sfTexture	*para_tt;
	sfTexture	*status_tt;
	sfTexture	*arrow_tt_r;
	sfTexture	*arrow_tt_l;
	sfSprite	*sprite;
	sfTexture	*texture;
	sfEvent		event;
}	champ_t;

/*****************************************/
/* Struct for inventory			 */
/* 					 */
/*****************************************/

typedef struct		s_inv
{
	int		in_inv;
	sfSprite	*layer_sprite;
	sfTexture	*layer_texture;
	item_t		*item;
}	inv_t;

/*****************************************/
/* Struct for intro			 */
/* 					 */
/*****************************************/

typedef struct		s_intro
{
	int		bool_intro;
	char		**path;
	sfSprite	*sprite;
	sfTexture	*texture;
	sfClock		*timer;
	sfEvent		event;
}	intro_t;

typedef struct		s_class
{
	int	hp;
	int	def;
	int	dmg;
	int	agi;
	int	mag;
}	class_t;
/*****************************************/
/* Struct creating a classe with all     */
/* stats				 */
/*****************************************/

typedef struct		s_win
{
	sfView		*view;
	sfView		*minimap;
	sfEvent		ev;
	sfRenderWindow	*win;
	sfVideoMode	mode;
	sfRenderStates	states;
	sfVector2i	mouse;
}	win_t;
/*************************************/
/* Struct referençant tout ce qui    */
/* est relatif à la creation de la   */
/* fenetre			     */
/*************************************/

typedef struct		s_check_class
{
	char	*to_compare;
	class_t	type;
}	check_class_t;

/************************************/
/* Struct permettant d'initialiser  */
/* / de trouver une classe	    */
/************************************/

typedef struct		s_dialog
{
	sfIntRect	rect;
	sfSprite	*sp;
	sfTexture	*text;
}	dialog_t;

typedef struct		s_escape
{
	sfSprite	*sp;
	sfTexture	*text;
}	escape_t;

typedef struct		s_cre_grass
{
	sfSprite	*sp;
	sfTexture	*text;
}	cre_grass_t;

typedef struct		s_cre_pnj
{
	int		near;
	int		rotate;
	int		obstacle;
	int		clock_bool;
	sfSprite	*sp;
	sfTexture	*text;
	sfIntRect	rect;
	sfFloatRect	frect;
	sfClock		*clock;
	class_t		classe;
}	cre_pnj_t;

typedef struct		s_cre_sprite
{
	int		clock_bool;
	sfSprite	*sp;
	sfTexture	*text;
	sfIntRect	rect;
	sfFloatRect	frect;
	sfClock		*clock;
	class_t		class;
}	cre_sprite_t;

typedef struct		s_menu
{
	sfFloatRect	hitbox;
	sfFont		*police;
	sfText		*text;
	sfTexture	*texture;
	sfSprite	*sprite;
	sfTexture	*bg_menu;
	sfSprite	*bg_m;
	sfTexture	*sword;
	sfSprite	*sw;
	sfClock		*clock;
	sfTime		time;
	int		x_pos;
	int		y_pos;
	float		x_sca;
	float		y_sca;
	sfIntRect	rbut;
}	menu_t;

typedef struct		s_options
{
	sfSprite	*sprite;
	sfTexture	*texture;
	sfText		*minus;
	sfText		*plus;
	int		pos;
}	opt_t;

typedef struct		s_pause
{
	sfSprite	*sprite;
	sfTexture	*texture;
}	pause_t;

typedef struct		s_music
{
	sfMusic		*music;
	sfTexture	*s_on;
	sfSprite	*on;
	sfTexture	*s_off;
	sfSprite	*off;
	int		bs;
	float		vol;
}	music_t;

typedef struct		s_status
{
	sfText	*hp;
	sfText	*def;
	sfText	*dmg;
	sfText	*agi;
	sfText	*mag;
}	status_t;

typedef struct		s_game
{
	int		fight_bool;
	int		bool_pos;
	char		*hero_path;
	win_t		video;
	list_t		*map_opt;
	bounds_t	*bounds;
	intro_t		intro;
	escape_t	escape;
	cre_pnj_t	pnj[2];
	cre_grass_t	ground[8];
	cre_sprite_t	graph[3];
	inv_t		inv;
	champ_t		champ;
	dialog_t	dialog[4];
	check_class_t	init_class[4];
	int		get_bounds;
	menu_t		menu[20];
	status_t	status;
	opt_t		opt;
	music_t		msc;
	pause_t		pause;
}	game_t;

/************************************/
/* Structure principale referançant */
/* toutes les autres structures	    */
/* du jeu			    */
/************************************/

#endif /* !STRUCT_H_ */

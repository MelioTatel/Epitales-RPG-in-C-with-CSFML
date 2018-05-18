/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** header for my rpg
*/

#ifndef	MY_RPG_H_
#define MY_RPG_H_

#include <SFML/Graphics.h>
#include "pnj.h"
#include "struct.h"
#include "linked_list.h"
#include "battle_ges.h"

#define MAP_Y	30
#define MAP_X	50
#define SCALING_X 40
#define SCALING_Y 40
#define SCALING_Z 50

#define is_number(a)	(a <= '9' && a >= '0')
#define Clock1	sfTime_asMilliseconds(sfClock_getElapsedTime(g->graph[1].clock))
#define Clock2	sfTime_asMilliseconds(sfClock_getElapsedTime(f->clock))
#define Clock3	sfTime_asMilliseconds(sfClock_getElapsedTime(g->graph[2].clock))

cre_pnj_t	init_pnj_sprite(char *, sfIntRect);
cre_sprite_t	init_sprite(char *);
cre_grass_t	init_grass_sprite(char *);
dialog_t	init_dialog(char *);
int	init_pnj(game_t *);

int	check(int, char **, char **);

void		do_save(game_t *);
void		my_put_in_list(bounds_t **, sfFloatRect);
int		my_putstr(char *);
void		my_put_in_listl(char **, list_conf_t **);
void		verif_save(game_t *, sfEvent);

char		*my_strdup(char *str);
float		my_atof(char *);

int		nbrlen(int);
int		my_strlen(char *);

int	move_up(game_t *, bounds_t *, sfEvent ev);
int	move_down(game_t *, bounds_t *, sfEvent ev);
int	move_left(game_t *, bounds_t *, sfEvent ev);
int	move_right(game_t *, bounds_t *, sfEvent ev);

void	destroy_ev(game_t *, int **);
int	**create_3d_map(void);
void	anim_water(game_t *, bounds_t *);
int	verif_dialog(game_t *, int **, sfVector2f **);
int	display(game_t *);
int	do_boucle_cut(game_t *, sfVector2f **, int **);
int	do_boucle(game_t *, sfVector2f **, int **, bounds_t *);


char		*int_to_char(int);
char		*my_revstr(char *);
char		*my_strdup(char *);
char		*my_strcat(char *, char *);

sfVector2f	d_v(float, float);
sfFloatRect	do_rect(float, float, float, float);
sfIntRect	do_irect(int, int, int, int);
sfColor		d_c(unsigned char, unsigned char, char, char);

void		draw_status(game_t *, int *);
void		init_status(game_t *);
void		create_music(game_t *);
int		create_data(game_t *, int, list_conf_t *);
void		init_skills_sprites(fight_t *);
int		set_data(game_t *, int, list_conf_t *);

/*
**===================================
**	   Inventory Function
**===================================
*/

int	inventory(game_t *);
int	inv_event(game_t *, item_t *, sfEvent);
int	init_inv(game_t *);
void	add_item(int, char *, sfVector2f, item_t **);

/*
**===================================
**	   Vertex Functions
**===================================
*/

void		draw_xy_map(int, int, sfVector2f **, game_t *);

sfVector2f	**create_2d_map(int **);
sfVector2f	project_iso_point(int, int, int);
sfVertexArray	*create_tile(sfVector2f *, sfVector2f *,
sfVector2f *, sfVector2f *);

int		draw_2d_map(sfVector2f **, int **, game_t *);

/*
**===================================
**	 Set Classes Functions
**===================================
*/

class_t	mage(void);
class_t	filip(void);
class_t	voleur(void);
class_t	guerrier(void);
class_t	mag_monster(void);

void	init_class(check_class_t *);

/*
**===================================
**	 GESTION MAP FUNCTIONS
**===================================
*/

void	modif_map(list_t **, int **);
void	map_y_first(list_t **, int **);
void	map_x_first(list_t **, int **);

void	sub_map_y(list_t **, int **);
void	sub_map_x(list_t **, int **);
void	add_map_y(list_t **, int **);
void	add_map_x(list_t **, int **);

int	verif_line(char *);
int	get_map_file(list_t **);
int	my_map_get_nbr(char *, int *);
int	parse_map_file(char *, list_t **);
int	my_map_in_list(char *, list_t **);

/*
**============================
**          EVENTS
**============================
*/

int	my_event(game_t *, bounds_t *);
void	introduction(game_t *);


/*
**============================
**	  CHAMP SELECT
**============================
*/

int	champ_select(game_t *);
int	champ_anim(game_t *, int *, sfIntRect *, sfClock *);
int	init_select(game_t *);
int	set_select(game_t *);
char	**path_champ(void);
int	champ_loop(game_t *, sfIntRect *, sfClock *, int *);
int	champ_event(game_t *, int *, sfIntRect *);
int	champ_mouse_event(game_t *, int *, sfEvent);

/*
**=============================
**	 INITIALISATION
**=============================
*/

int		init_win(win_t *);
int		init_all(game_t *);
int		init_select(game_t *);
int		init_pnj(game_t *);
int		init_graph(game_t *);
int		init_intro(game_t *);

dialog_t	init_dialog(char *);
cre_sprite_t	init_sprite(char *);
cre_pnj_t	init_pnj_sprite(char *, sfIntRect);

/*
**=============================
**	     TOOLS
**=============================
*/

char	**my_str_to_wordtab(char *, char);
char	*get_next_line(int);
int	my_getnbr(char *);
char	*int_to_char(int);

/*
**=============================
**	     MENU
**=============================
*/

void	init_pause(game_t *);
void	init_options(game_t *);
void	reset_size(game_t *, sfEvent);
void	change_state(game_t *, sfEvent);
void	in_menu(game_t *, sfEvent);
void	in_options(game_t *, sfEvent);
void	check_for_visual(game_t *, sfEvent);
void	draw_menu(game_t *);
void	draw_options(game_t *);
void	draw_opt_ig(game_t *);
void	draw_pause(game_t *);
void	draw_pause_ingame(game_t *);
void	ask_quit_ig(game_t *);
int	my_menu(game_t *);
void	reset_all(game_t *);
void	in_quit(game_t *, sfEvent);
void	pause_in_game(game_t *, sfEvent);
void	key_event(game_t *, sfEvent);
void	event_key_pressed(game_t *, sfEvent, sfIntRect *);

int	init_intro(game_t *);

#endif /* !MY_RPG_H_ */

##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

SRC	=	./src/linked_list/put_bound_list.c			\
		./src/linked_list/put_in_list.c				\
		./src/event/move_player.c				\
		./src/event/in_menu.c					\
		./src/event/in_options.c				\
		./src/do_save.c						\
		./src/init_class.c					\
		./src/fight/init_fight.c				\
		./src/fight/draw_fight.c				\
		./src/tools/atof.c					\
		./src/fight/draw_mage_skill.c				\
		./src/fight/fight_scene.c				\
		./src/fight/gest_spells.c				\
		./src/fight/menu_choice.c				\
		./src/fight/skill_choice.c				\
		./src/pnj/old_pnj_move.c				\
		./src/pnj/old_pnj_set.c					\
		./src/pnj/old_pnj_dialog.c				\
		./src/map/check_bfr_put_on_map.c			\
		./src/map/get_map_option.c				\
		./src/map/put_on_map.c					\
		./src/tools/draw_tools.c				\
		./src/tools/string_tools.c				\
		./src/pnj/goblinc_png.c					\
		./src/tools/int_to_char.c				\
		./src/tools/my_getnbr.c					\
		./src/tools/my_putstr.c					\
		./src/init_struct.c					\
		./src/vertex.c						\
		./src/map.c						\
		./src/init_struct_2.c					\
		./src/class.c						\
		./src/intro/intro.c					\
		./src/get_next_line/get_next_line.c			\
		./src/menu/my_str_to_wordtab.c				\
		./src/menu/analyse_file.c				\
		./src/menu/check_visual.c				\
		./src/menu/draw_menu.c					\
		./src/champ_select/champ_select.c			\
		./src/champ_select/champ_event.c			\
		./src/champ_select/key_pressed.c			\
		./src/champ_select/init_and_anim_champ.c		\
		./src/menu/init_options.c				\
		./src/menu/draw_options.c				\
		./src/event/change_state.c				\
		./src/event/side_move.c					\
		./src/event/in_pause.c					\
		./src/event/reset_state.c				\
		./src/menu/draw_pause.c					\
		./src/menu/init_menu.c					\
		./src/menu/draw_status.c				\
		./src/menu/init_pause.c					\
		./src/music/create_music.c				\
		./src/inventory/init_invent.c				\
		./src/status/init_status.c				\
		./src/my_rpg.c						\
		./src/junc_funt.c					\
		./src/check.c						\
		./src/main.c

OBJ	=	$(SRC:.c=.o)

INC	=	-I ./include

CFLAGS	=	-g $(INC)

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(INC) -lm -lc_graph_prog

tests_run:
		@make -sC ./tests
		./tests/units-tests

clean:
	@make -sC ./tests clean
	rm -f $(OBJ)

fclean:	clean
	@make -sC ./tests fclean
	rm -f $(NAME)

re:	make clean fclean all

.PHONY:	make all clean fclean re

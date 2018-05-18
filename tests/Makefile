##
## EPITECH PROJECT, 2018
## Unit test
## File description:
## makefile for unit test
##

SRC_DIR		=	../src/

SRC	=	$(SRC_DIR)linked_list/put_bound_list.c			\
		$(SRC_DIR)linked_list/put_in_list.c			\
		$(SRC_DIR)event/move_player.c				\
		$(SRC_DIR)event/in_menu.c				\
		$(SRC_DIR)event/in_options.c				\
		$(SRC_DIR)do_save.c					\
		$(SRC_DIR)init_class.c					\
		$(SRC_DIR)fight/init_fight.c				\
		$(SRC_DIR)fight/draw_fight.c				\
		$(SRC_DIR)tools/atof.c					\
		$(SRC_DIR)fight/draw_mage_skill.c			\
		$(SRC_DIR)fight/fight_scene.c				\
		$(SRC_DIR)fight/gest_spells.c				\
		$(SRC_DIR)fight/menu_choice.c				\
		$(SRC_DIR)fight/skill_choice.c				\
		$(SRC_DIR)pnj/old_pnj_move.c				\
		$(SRC_DIR)pnj/old_pnj_set.c				\
		$(SRC_DIR)pnj/old_pnj_dialog.c				\
		$(SRC_DIR)map/check_bfr_put_on_map.c			\
		$(SRC_DIR)map/get_map_option.c				\
		$(SRC_DIR)map/put_on_map.c				\
		$(SRC_DIR)tools/draw_tools.c				\
		$(SRC_DIR)tools/string_tools.c				\
		$(SRC_DIR)pnj/goblinc_png.c				\
		$(SRC_DIR)tools/int_to_char.c				\
		$(SRC_DIR)tools/my_getnbr.c				\
		$(SRC_DIR)tools/my_putstr.c				\
		$(SRC_DIR)init_struct.c					\
		$(SRC_DIR)vertex.c					\
		$(SRC_DIR)map.c						\
		$(SRC_DIR)init_struct_2.c				\
		$(SRC_DIR)class.c					\
		$(SRC_DIR)intro/intro.c					\
		$(SRC_DIR)get_next_line/get_next_line.c			\
		$(SRC_DIR)menu/my_str_to_wordtab.c			\
		$(SRC_DIR)menu/analyse_file.c				\
		$(SRC_DIR)menu/check_visual.c				\
		$(SRC_DIR)menu/draw_menu.c				\
		$(SRC_DIR)champ_select/champ_select.c			\
		$(SRC_DIR)champ_select/champ_event.c			\
		$(SRC_DIR)champ_select/key_pressed.c			\
		$(SRC_DIR)champ_select/init_and_anim_champ.c		\
		$(SRC_DIR)menu/init_options.c				\
		$(SRC_DIR)menu/draw_options.c				\
		$(SRC_DIR)event/change_state.c				\
		$(SRC_DIR)event/side_move.c				\
		$(SRC_DIR)event/in_pause.c				\
		$(SRC_DIR)event/reset_state.c				\
		$(SRC_DIR)menu/draw_pause.c				\
		$(SRC_DIR)menu/init_menu.c				\
		$(SRC_DIR)menu/draw_status.c				\
		$(SRC_DIR)menu/init_pause.c				\
		$(SRC_DIR)music/create_music.c				\
		$(SRC_DIR)inventory/init_invent.c			\
		$(SRC_DIR)status/init_status.c				\
		$(SRC_DIR)my_rpg.c					\
		$(SRC_DIR)junc_funt.c

SRC_UT_DIR	=	./src/

SRC_UT		=	$(SRC_UT_DIR)tests.c			\

OBJ		=	$(SRC:.c=.o)	$(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage -I../include

LDFLAGS		=	-lcriterion -lgcov $(LIB)

NAME		=	units-tests

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@cc -o $(NAME) $(OBJ) $(LDFLAGS) -lc_graph_prog

clean	:
		@rm -f $(OBJ)
		@rm -f $(SRC:.c=.gcno)
		@rm -f $(SRC_UT:.c=.gcno)
		@rm -f $(SRC:.c=.gcda)
		@rm -f $(SRC_UT:.c=.gcda)

fclean	:	clean
		@rm -f ./$(NAME)

re	:	fclean all

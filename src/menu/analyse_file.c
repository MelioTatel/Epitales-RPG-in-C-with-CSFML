/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** analyse file to get args
*/

#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "linked_list.h"
#include "struct.h"
#include "my_rpg.h"

int	check_file(list_conf_t *list)
{
	int	i = 0;
	int	j = 0;

	while (list != NULL) {
		while (list->data[j] != NULL)
			j++;
		if (j != 5)
			return (1);
		i++;
		list = list->next;
	}
	return (i);
}

list_conf_t	*get_args_config(void)
{
	char	*str;
	char	**tab;
	int	fd = open("src/menu/menu_config", O_RDONLY);
	list_conf_t	*list = NULL;

	str = get_next_line(fd);
	while (str) {
		tab = my_str_to_wordtab(str, '\t');
		str = get_next_line(fd);
		my_put_in_listl(tab, &list);
	}
	return (list);
}

int	analyse_data(list_conf_t *list, game_t *g)
{
	list_conf_t	*tmp = list;
	int		i = 0;

	g->menu[0].police = sfFont_createFromFile("./src/assets/Pixel.otf");
	if (check_file(tmp) == 1) {
		write(2, "Error file format\n", 18);
		return (1);
	}
	while (tmp != NULL) {
		create_data(g, i, tmp);
		set_data(g, i, tmp);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	my_menu(game_t *g)
{
	list_conf_t	*list = NULL;

	g->bool_pos = 0;
	list = get_args_config();
	init_options(g);
	init_pause(g);
	create_music(g);
	sfMusic_setLoop(g->msc.music, 1);
	sfMusic_play(g->msc.music);
	if (analyse_data(list, g) == 1)
		return (1);
	init_status(g);
	return (0);
}

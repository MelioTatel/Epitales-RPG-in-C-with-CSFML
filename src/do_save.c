/*
** EPITECH PROJECT, 2018
** do save
** File description:
** do save
*/

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my_rpg.h"

void	do_save(game_t *g)
{
	int	fd;
	char	*file;
	char	save[] = "./game_config/save";
	mode_t	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	file = my_strcat(save, int_to_char(1));
	fd = open(file, O_RDWR | O_CREAT | O_EXCL, mode);
	for (int i = 2; fd < 0 && errno == EEXIST; i += 1) {
		file = my_strcat(save, int_to_char(i));
		fd = open(file, O_RDWR | O_CREAT | O_EXCL, mode);
	}
	return;
}

void	verif_save(game_t *g, sfEvent ev)
{
	if (ev.type == sfEvtKeyPressed && ev.key.code == sfKeyF1)
		do_save(g);
}
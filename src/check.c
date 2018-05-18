/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** function of check
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "my_rpg.h"

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int	i = 0;
	int	nchar_i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
		if (nchar_i < n - 1)
			nchar_i++;
		i++;
		return (s2[i] - s1[i]);
	}
}

char	*my_strcpy(char *dest, char const *src)
{
	int	i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	display_ashe(void)
{
	int	fd = open("./src/assets/usage", O_RDONLY);
	int	bytes;
	char	str[11];

	if (fd == -1) {
		my_putstr("Missing usage file\n");
		return (84);
	}
	bytes = read(fd, str, 10);
	while (bytes) {
		if (bytes == -1)
			return (84);
		str[bytes] = '\0';
		my_putstr(str);
		bytes = read(fd, str, 10);
	}
	close(fd);
	return (0);
}

char	**get_name(char **env)
{
	int	a = 0;

	while (env[a] != NULL && my_strncmp("DISPLAY", env[a], 7) != 0)
		a++;
	if (env[a] == NULL)
		return (NULL);
	env[a] = my_strdup("DISPLAY=:0.0");
	return (env);
}

int	check(int ac, char **av, char **env)
{
	if (ac != 1 && ac != 2)
		return (-1);
	if (av[1] && my_strncmp(av[1], "-h", 2) == 0) {
		display_ashe();
		return (1);
	}
	if (env && env[0] != NULL)
		env = get_name(env);
	if (env == NULL || env[0] == NULL)
		return (-1);
	if (av[1] != NULL)
		return (-1);
	return (0);
}
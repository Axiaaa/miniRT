/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:48:54 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/27 18:05:46 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	pre_read(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		free(line);
	}
	close_file(fd);
	return (++i);
}

char	**read_file(int fd, int nb_lines)
{
	char	**res;
	char	*line;
	int		i;

	i = 0;
	res = f_malloc(sizeof(char *) * (nb_lines + 1));
	if (!res)
		exit_error("Error\nMalloc failed (read.c:40)\n");
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		res[i] = line;
		i++;
	}
	res[i] = NULL;
	close_file(fd);
	return (res);
}

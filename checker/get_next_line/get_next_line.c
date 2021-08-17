/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:20:08 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/05 21:45:04 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int64_t		ft_set(int64_t *a, int64_t b)
{
	*a = b;
	return (b);
}

int64_t		ft_ternary(int flag, int64_t a, int64_t b)
{
	if (flag)
		return (a);
	return (b);
}

static char	*rem_line(char **saved)
{
	size_t	end;
	char	*ret;
	char	*temp;

	if (!*saved)
		return (ft_substr("", 0, 0));
	if (ft_strchr(*saved, '\n'))
		end = ft_strchr(*saved, '\n') - *saved;
	else
		end = (size_t)-1;
	ret = ft_substr(*saved, 0, end);
	if (end != (size_t)-1)
		temp = ft_substr(*saved, end + 1, (size_t)-1);
	else
		temp = ft_substr("", 0, 0);
	free(*saved);
	*saved = temp;
	return (ret);
}

static int	get_line(int fd, char **saved, char **line)
{
	char	*buff;
	int64_t	aux;
	char	*temp;

	aux = 1;
	while (!ft_strchr(saved[fd], '\n') && aux)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (ft_set(&aux, (int64_t)read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[aux] = '\0';
			temp = ft_strjoin(saved[fd], buff);
			free(saved[fd]);
			saved[fd] = temp;
		}
		else if (aux == -1)
		{
			free(buff);
			*line = NULL;
			return (-1);
		}
		free(buff);
	}
	*line = rem_line(&(saved[fd]));
	return ((saved[fd] && ft_strlen(saved[fd]) != 0) || aux);
}

int			get_next_line(int fd, char **line)
{
	static char	*saved[FD_MAX_COUNT];

	if (fd < 0 || fd == 1 || fd == 2 || fd >= FD_MAX_COUNT || !line)
		return (-1);
	return (get_line(fd, saved, line));
}

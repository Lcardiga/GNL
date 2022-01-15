/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcardiga <lcardiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:21:27 by lcardiga          #+#    #+#             */
/*   Updated: 2021/11/29 18:29:50 by lcardiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	NAME:
** 		get_next_line
**	PROTOTYPE:
**		char *get_next_line(int fd);
**	TURN IN FILES:
** 		get_next_line.c, get_next_line_utils.c, get_next_line.h
**	PARAMETERS:
**		File descriptor to read from
**	RETURN VALUE:
** 		Read line: correct behavior
**    	NULL: nothing else to read or an error occurred
**	EXTERNAL FUNCTIONS:
** 		read, malloc, free
**	DESCRIPTION:
**		Write a function which returns a line read from a
**    	file descriptor
*/

#include "get_next_line.h"

char	*getline(int fd, char *buff, char *ostatoc)
{
	long	count;
	char	*tmp;

	count = 1;
	while (count)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
			return (0);
		if (count == 0)
			break ;
		buff[count] = '\0';
		if (!ostatoc)
			ostatoc = ft_strdup("");
		tmp = ostatoc;
		ostatoc = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ostatoc);
}

char	*save_ostatoc(char *line)
{
	long	count;
	char	*ost;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (0);
	ost = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*ost == '\0')
	{
		free (ost);
		ost = NULL;
	}
	return (ost);
}

void	result_line(char *line)
{
	long	count;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	line[count + 1] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*ostatoc;
	char		*buff;
	char		*line;

	buff = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	line = getline(fd, buff, ostatoc);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	ostatoc = save_ostatoc(line);
	result_line(line);
	return (line);
}

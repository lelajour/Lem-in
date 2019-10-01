/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 15:34:42 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/01 07:16:02 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/get_next_line.h"

char	*new_tmp(char *tmp)
{
	int		i;
	char	*new_tmp;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i] || (tmp[i] && !tmp[i + 1]))
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	new_tmp = ft_strdup(&tmp[i + 1]);
	ft_strdel(&tmp);
	return (new_tmp);
}

void	line_return(char *tmp, char **line)
{
	int	i;

	i = 0;
	if (tmp != NULL)
	{
		while (tmp[i] && (tmp[i] != '\n'))
			i++;
		*line = ft_strnew(i);
		ft_strncpy(*line, tmp, i);
	}
	else
		*line = NULL;
}

char	*save_buff(char *buff, char *tmp)
{
	char	*new_tmp;

	new_tmp = ft_strjoin(tmp, buff);
	ft_strdel(&tmp);
	return (new_tmp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tmp[FD_MAX];
	char		buff[BUFF_SIZE + 1];
	int			i;

	if (!line || fd < 0 || BUFF_SIZE < 0 || fd > 30000)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(1);
	while (!ft_strchr(tmp[fd], '\n'))
	{
		if ((i = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[i] = '\0';
		tmp[fd] = save_buff(buff, tmp[fd]);
		if (i == 0 && ft_strlen(tmp[fd]) == 0)
			return (0);
		if (i == 0)
			break ;
	}
	line_return(tmp[fd], line);
	tmp[fd] = new_tmp(tmp[fd]);
	return (1);
}

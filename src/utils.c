
#include "../header/lemin.h"

int		ft_start_chr(int *link, int nb)
{
	int	j;
	int	tmp;

	j = 0;
	tmp = 0;
	while (j < nb)
	{
		if (link[j] == 1)
			tmp++;
		else if (link[j] == 2 || link[j] == 3)
			return (-1);
		j++;
	}
	return (tmp);
}

int		look_for_end(t_room *room)
{
	int i;

	i = 0;
	while (i < room->nb)
	{
		if (ft_memchr((room->link[i]), 3, room->nb) != NULL)
			return (i);
		i++;
	}
	return (-1);
}

#include "fdf.h"

static int		is_integer_convertible(char *str)
{
	size_t		i;

	i = -1;
	while (str[++i])
	{
		if ((i == 0 && !(ft_isdigit(str[i])) && str[i] != '-' && str[i] != '+')
			|| (i > 0 && !(ft_isdigit(str[i]))))
			return (0);
	}
	return (1);
}

static size_t	column_count(char **coord_line)
{
	size_t		count;

	count = 0;
	while (coord_line[count])
		count++;
	return (count);
}

static t_map	*convert_coord_line(char **coord_line)
{
	t_map		*line;
	int			*z_coord_list;
	size_t		i;
	size_t		count;

	count = column_count(coord_line);
	i = -1;
	if (!(line = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(z_coord_list = (int*)malloc(sizeof(int) * count)))
		return (NULL);
	while (++i < count)
	{
		if (!(is_integer_convertible(coord_line[i])))
			return (NULL);
		z_coord_list[i] = ft_atoi(coord_line[i]);
	}
	line->coord_list = z_coord_list;
	line->width = count;
	line->next = NULL;
	return (line);
}

static void		append_node(t_map **map, t_map *new_node)
{
	t_map	*current;

	current = *map;
	if (current == NULL)
		*map = new_node;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

t_map			**read_map_from(char *file)
{
	int		fd;
	char	**tmp;
	char	**coord_line;
	t_map	**map;
	t_map	*new_node;

	if ((fd = open(file, O_RDONLY)) < 3)
		return (NULL);
	if (!(tmp = (char **)malloc(sizeof(char *))))
		return (NULL);
	if (!(map = (t_map**)malloc(sizeof(t_map*))))
		return (NULL);
	*map = NULL;
	while ((get_next_line(fd, tmp)))
	{
		if (!(coord_line = ft_strsplit(*tmp, ' ')) ||
			!(new_node = convert_coord_line(coord_line)))
			return (NULL);
		append_node(map, new_node);
	}
	ft_strdel(tmp);
	close(fd);
	return (map);
}

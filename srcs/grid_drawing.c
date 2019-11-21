#include "fdf.h"

int		count_map_height(t_map **map)
{
	t_map	*current;
	int		count;

	count = 0;
	current = *map;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	horizontal_line_fill(t_map **map, t_view view)
{
	t_map		*current;
	int			x;
	int			y;
	t_point		start;
	t_point		end;

	current = *map;
	y = 0;
	if (current != NULL)
	{
		while (current)
		{
			x = -1;
			while (++x < view.map_width - 1)
			{
				start = point_from((double)x, (double)y,
						(double)current->coord_list[x], view);
				end = point_from((double)(x + 1), (double)y,
						(double)current->coord_list[x + 1], view);
				draw_line(start, end, view);
			}
			y++;
			current = current->next;
		}
	}
}

void	vertical_line_fill(t_map **map, t_view view)
{
	t_map		*current;
	int			x;
	int			y;
	t_point		start;
	t_point		end;

	current = *map;
	y = 0;
	if (current != NULL)
	{
		while (current->next)
		{
			x = -1;
			while (++x < view.map_width)
			{
				start = point_from((double)x, (double)y,
						(double)current->coord_list[x], view);
				end = point_from((double)x, (double)(y + 1),
						current->next->coord_list[x], view);
				draw_line(start, end, view);
			}
			y++;
			current = current->next;
		}
	}
}

int		display_map(t_map **map, t_view *view)
{
	void	*ptr_img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;

	if (view->img_ptr)
		mlx_destroy_image(view->mlx_ptr, view->img_ptr);
	if (!(ptr_img = mlx_new_image(view->mlx_ptr, view->win_width,
					view->win_height)))
		return (0);
	view->img_width = view->win_width;
	view->img_height = view->win_height;
	view->img_ptr = ptr_img;
	view->nbr_pixels = (double)(((view->zoom) * (view->img_width)) / ((*map)->width));
	img_str = mlx_get_data_addr(ptr_img, &bpp, &s_l, &endian);
	view->img_str = (unsigned char *)img_str;
	view->line_size = s_l / 4; //on convertit de octet à pixels
	horizontal_line_fill(map, *view);
	vertical_line_fill(map, *view);
	mlx_put_image_to_window((void *)view, view->win_ptr, ptr_img, 0, 0);
	return (0);
}

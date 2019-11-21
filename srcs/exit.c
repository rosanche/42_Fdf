#include "fdf.h"

static void		clear_map(t_map **map)
{
	t_map	*current;
	t_map	*next;

	if (map != NULL)
	{
		next = *map;
		while (next)
		{
			current = next;
			next = current->next;
			ft_memdel((void**)(&(current->coord_list)));
			ft_memdel((void**)&current);
		}
	}
}

void			exit_error(t_view *view)
{
	ft_putendl("An error has occured.");
	if (view->img_ptr)
		mlx_destroy_image(view->mlx_ptr, view->img_ptr);
	if (view->win_ptr && view->mlx_ptr)
		mlx_destroy_window(view->mlx_ptr, view->win_ptr);
	clear_map(view->map);
	ft_memdel((void**)(&view));
	exit(0);
}

void			exit_normally(t_view *view)
{
	if (view->img_ptr)
		mlx_destroy_image(view->mlx_ptr, view->img_ptr);
	if (view->win_ptr && view->mlx_ptr)
		mlx_destroy_window(view->mlx_ptr, view->win_ptr);
	clear_map(view->map);
	ft_memdel((void**)(&view));
	exit(0);
}

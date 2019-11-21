#include "fdf.h"

void		display_instructions(void)
{
	ft_putstr("Arrow Up : rotate up\n\
Arrow Down : rotate down\n\
Arrow left : rotate left\n\
Arrow right : rotate right\n\
W : Scale+\n\
C : Scale-\n\
A : Zoom up\n\
E : Zoom down\n\
Z : Move forward\n\
S : Move backward\n\
Q : Move left\n\
D : Move right\n");
}

t_view		*init_environment(void)
{
	t_view		*view;

	if (!(view = (t_view *)malloc(sizeof(t_view))))
		return (NULL);
	view->mlx_ptr = NULL;
	view->win_ptr = NULL;
	view->img_ptr = NULL;
	view->img_str = NULL;
	view->map = NULL;
	view->zoom = 0.7;
	view->view_angle = M_PI_2;
	view->view_rotation = 0;
	view->z_scale = 10;
	return (view);
}

int			deal_key(int key, void *param)
{
	t_view		*view;

	view = (t_view *)param;
	if (key == 53)
		exit_normally(view);
	else if (key == 12 || key == 14 || key == 13 || key == 1 || key == 0 ||
		key == 2 || key == 6 || key == 8 || key == 126 || key == 125 ||
		key == 123 || key == 124)
	{
		handle_key(key, view);
		display_map(view->map, view);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_map		**map;
	t_view		*view;

	view = init_environment();
	if (ac != 2)
		return (0);
	map = read_map_from(av[1]);
	if (map == NULL || *map == NULL)
		exit_error(view);
	view->map = map;
	view->map_width = (*map)->width;
	view->map_height = count_map_height(map);
	view->mlx_ptr = mlx_init();
	view->win_ptr = mlx_new_window(view->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
		"mlx 42");
	view->win_width = WIN_WIDTH;
	view->win_height = WIN_HEIGHT;
	view->center_x = view->win_width / 2;
	view->center_y = view->win_height / 2;
	display_map(map, view);
	display_instructions();
	mlx_key_hook(view->win_ptr, deal_key, (void *)view);
	mlx_loop(view->mlx_ptr);
	return (0);
}

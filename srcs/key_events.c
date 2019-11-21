#include "fdf.h"

static void	handle_key_next(int key, t_view *view)
{
	if (key == 126)
		view->view_angle += M_PI_4 / 6;
	else if (key == 125)
		view->view_angle -= M_PI_4 / 6;
	else if (key == 123)
		view->view_rotation -= M_PI_4 / 6;
	else if (key == 124)
		view->view_rotation += M_PI_4 / 6;
}

void		handle_key(int key, t_view *view)
{
	if (key == 12)
		view->zoom += 0.1;
	else if (key == 14)
		view->zoom -= 0.1;
	else if (key == 13)
		view->center_y -= sin(view->view_angle) * 0.1 *
			(double)(view->img_height);
	else if (key == 1)
		view->center_y += sin(view->view_angle) * 0.1 *
			(double)(view->img_height);
	else if (key == 0)
		view->center_x -= 0.1 * (double)(view->img_width);
	else if (key == 2)
		view->center_x += 0.1 * (double)(view->img_width);
	else if (key == 6)
		view->z_scale *= 1.4;
	else if (key == 8)
		view->z_scale /= 1.4;
	else
		handle_key_next(key, view);
}

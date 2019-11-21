#include "fdf.h"

static void		draw_x_points(t_point start, t_point end, t_view view)
{
	int			dx;
	int			dy;
	int			x;
	int			y;
	t_point		point;

	dx = end.x - start.x;
	dy = end.y - start.y;
	x = start.x - 1;
	while (++x <= end.x)
	{
		y = start.y + dy * (x - start.x) / dx;
		point.x = x;
		point.y = y;
		fill_pixel(view, point, color_from(255, 255, 255));
	}
}

static void		draw_y_points(t_point start, t_point end, t_view view)
{
	int			dx;
	int			dy;
	int			x;
	int			y;
	t_point		point;

	dx = end.x - start.x;
	dy = end.y - start.y;
	y = start.y - 1;
	while (++y <= end.y)
	{
		x = start.x + dx * (y - start.y) / dy;
		point.x = x;
		point.y = y;
		fill_pixel(view, point, color_from(255, 255, 255));
	}
}

void			draw_line(t_point start, t_point end, t_view view)
{
	int		dx;
	int		dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	if (!(dx == 0 && dy == 0))
	{
		if (abs(dx) >= abs(dy) && dx != 0)
		{
			if (start.x > end.x)
				draw_x_points(end, start, view);
			else
				draw_x_points(start, end, view);
		}
		else if (abs(dx) < abs(dy) && dy != 0)
		{
			if (start.y > end.y)
				draw_y_points(end, start, view);
			else
				draw_y_points(start, end, view);
		}
	}
}

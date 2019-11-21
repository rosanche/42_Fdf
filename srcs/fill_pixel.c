#include "fdf.h"

void	fill_pixel(t_view view, t_point point, t_color color)
{
	int		i;

	if (!((point.x < 0 || point.x >= view.img_width) ||
		(point.y < 0 || point.y >= view.img_height)))
	{
		i = (point.y * view.line_size) * 4 + point.x * 4;
		view.img_str[i] = color.r;
		view.img_str[i + 1] = color.g;
		view.img_str[i + 2] = color.b;
		view.img_str[i + 3] = color.a;
	}
}

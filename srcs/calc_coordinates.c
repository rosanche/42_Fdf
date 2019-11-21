#include "fdf.h"

/*
** Will calculate the 2D-coordinates of a point (a node of the wireframe)
** based on its 3D-coordinates, the view angle, rotation, zoom and center.
*/

static t_coordinate		apply_x_rotation(t_coordinate coord, t_view view)
{
	double		y;
	double		z;

	y = coord.y;
	z = coord.z;
	coord.y = y * cos(view.view_angle) - z * sin(view.view_angle);
	coord.z = y * sin(view.view_angle) + z * cos(view.view_angle);
	return (coord);
}

static t_coordinate		apply_z_rotation(t_coordinate coord, t_view view)
{
	double		x;
	double		y;

	x = coord.x;
	y = coord.y;
	coord.x = x * cos(view.view_rotation) - y * sin(view.view_rotation);
	coord.y = x * sin(view.view_rotation) + y * cos(view.view_rotation);
	return (coord);
}

t_point				point_from(double i, double j, double z, t_view view)
{
	t_point			a;
	t_coordinate		coord;

	coord.x = (i - ((double)view.map_width) / 2) * view.nbr_pixels;
	coord.y = (j - ((double)view.map_height) / 2) * view.nbr_pixels;
	coord.z = z * view.z_scale;
	coord = apply_z_rotation(coord, view);
	coord = apply_x_rotation(coord, view);
	a.x = (int)(coord.x + view.center_x);
	a.y = (int)(coord.y + view.center_y);
	return (a);
}

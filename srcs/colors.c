#include "fdf.h"

t_color		color_from(unsigned char r, unsigned char g, unsigned char b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 0;
	return (color);
}

int			get_endian_color(unsigned int r, unsigned int g, unsigned int b)
{
	int		endian_color;

	endian_color = 0;
	endian_color = ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
	return (endian_color);
}

#include "../includes/fractol.h"

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	ft_rgb(t_fr *fr, int k)
{
	fr->rgb[0] = ((k / 8) * 32);
	fr->rgb[1] = ((k / 8) * 13);
	fr->rgb[2] = ((k % 16) * 16);
	if (k > 600)
		return (0x000000ff);
	return (get_rgba(fr->rgb[0], fr->rgb[1], fr->rgb[2], 255));
}
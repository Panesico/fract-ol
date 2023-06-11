/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:29:09 by panesico          #+#    #+#             */
/*   Updated: 2023/06/11 16:42:02 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_put_pixel(t_fr *fr, int k, int x, int y)
{
	mlx_put_pixel(fr->img, y, x, ft_rgb(fr, k));
}

void	ft_complex_mandel(t_fr *fr, double swap, int x, int y)
{
	int	k;

	k = 1;
	while (k <= 400)
	{
		swap = fr->r;
		fr->r = (fr->r * fr->r) - (fr->i * fr->i) + fr->n2;
		fr->i = (2 * swap * fr->i) + fr->n1;
		fr->res = (fr->r * fr->r) + (fr->i * fr->i);
		if (fr->res > 4)
			break ;
		k++;
	}
	ft_put_pixel(fr, k, x, y);
}

void	ft_fractal_math_mandel(t_fr *fr)
{
	double	i;
	double	j;
	double	swap;

	i = 0;
	swap = 0;
	while (i < HEIGHT)
	{
		fr->n1 = fr->y + (i / (HEIGHT / fr->reso_h));
		j = 0;
		while (j < WIDTH)
		{
			fr->n2 = fr->x + (j / (WIDTH / fr->reso_w));
			fr->r = 0;
			fr->i = 0;
			ft_complex_mandel(fr, swap, i, j);
			j++;
		}
		i++;
	}
	if (fr->color_offset < 256)
		fr->color_offset += 4;
	else
		fr->color_offset = 0;
}

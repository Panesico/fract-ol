/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:40:06 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 16:40:13 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fractal_math_julia(t_fr *fr)
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
			fr->r = fr->n1;
			fr->i = fr->n2;
			ft_complex_julia(fr, swap, i, j);
			j++;
		}
		i++;
	}
	if (fr->color_offset < 256)
		fr->color_offset += 4;
	else
		fr->color_offset = 0;
}

void	ft_complex_julia(t_fr *fr, double swap, int x, int y)
{
	int	k;

	k = 1;
	while (k <= 400)
	{
		swap = fr->r;
		fr->r = (fr->r * fr->r) - (fr->i * fr->i) + fr->julia_cons1;
		fr->i = (2 * swap * fr->i) + fr->julia_cons2;
		fr->res = (fr->r * fr->r) + (fr->i * fr->i);
		if (fr->res > 4)
			break ;
		k++;
	}
	ft_put_pixel(fr, k, x, y);
}

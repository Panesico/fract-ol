/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:42:19 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 16:42:19 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	ft_rgb(t_fr *fr, int k)
{
	int	rgb1;
	int	rgb2;
	int	rgb3;

	rgb1 = ((k % 8) * 32 + fr->color_offset);
	rgb2 = ((k % 16) * 16 + fr->color_offset);
	rgb3 = ((k % 32) * 8 + fr->color_offset);
	if (k > 400)
		return (0x000000ff);
	return (get_rgba(rgb1, rgb2, rgb3, 255));
}

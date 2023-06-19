/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:40:49 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 16:40:49 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fr	*fr;

	(void)xdelta;
	fr = (t_fr *)param;
	if (ydelta > 0)
	{
		fr->reso_w = fr->reso_w / 1.5;
		fr->reso_h = fr->reso_h / 1.5;
		mlx_get_mouse_pos(fr->mlx, &fr->m_x, &fr->m_y);
		fr->x = fr->x + ((fr->m_x / (fr->rel_w / fr->reso_w) / 2));
		fr->y = fr->y + ((fr->m_y / (fr->rel_h / fr->reso_h) / 2));
		fr->fractal_type(fr);
	}
	else if (ydelta < 0)
	{
		fr->reso_w = fr->reso_w * 1.5;
		fr->reso_h = fr->reso_h * 1.5;
		mlx_get_mouse_pos(fr->mlx, &fr->m_x, &fr->m_y);
		fr->x = fr->x + ((fr->m_x / (fr->rel_w / fr->reso_w) / -2));
		fr->y = fr->y + ((fr->m_y / (fr->rel_h / fr->reso_h) / -2));
		fr->fractal_type(fr);
	}
}

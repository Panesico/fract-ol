/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:46 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 16:40:58 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	hook(struct mlx_key_data keydata, void *param)
{
	t_fr	*fr;

	fr = (t_fr *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(fr->mlx);
		ft_free_struc(fr);
		exit(EXIT_SUCCESS);
	}
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_UP)
			fr->y = fr->y + ((500 / (fr->rel_h / fr->reso_h) / -2));
		else if (keydata.key == MLX_KEY_DOWN)
			fr->y = fr->y + ((500 / (fr->rel_h / fr->reso_h) / 2));
		else if (keydata.key == MLX_KEY_LEFT)
			fr->x = fr->x + ((500 / (fr->rel_w / fr->reso_w) / -2));
		else if (keydata.key == MLX_KEY_RIGHT)
			fr->x = fr->x + ((500 / (fr->rel_w / fr->reso_w) / 2));
		fr->fractal_type(fr);
	}
}

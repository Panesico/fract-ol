/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:02:56 by panesico          #+#    #+#             */
/*   Updated: 2023/06/02 02:02:56 by panesico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_free_struc(t_fr *fr)
{
	if (!fr->rgb)
		free(fr->rgb);
	if (!fr->mlx)
		free(fr->mlx);
	free (fr);
}

t_fr	*ft_create_struc()
{
	t_fr	*fr;

	fr = (t_fr *)ft_calloc(1, sizeof(t_fr));
	if (!fr)
		return (0);
	fr->cons = 200;
	fr->n1 = 0;
	fr->n2 = 0;
	fr->r = 0;
	fr->i = 0;
	fr->res = 0;
	fr->iter = 0;
	fr->x = -2.3;
	fr->y = -1.1;
	fr->m_x = 0;
	fr->m_y = 0;
	fr->reso_h = 2.25;
	fr->reso_w = 4;
	fr->rel_w = WIDTH;
	fr->rel_h = HEIGHT;
	fr->rgb = (int *)ft_calloc(4, sizeof(int));
	fr->mlx = mlx_init(WIDTH, HEIGHT, "Fract-Ol", false);
	fr->img = mlx_new_image(fr->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fr->mlx, fr->img, 0, 0);
	return (fr);
}
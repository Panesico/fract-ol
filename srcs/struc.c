/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panesico <panesico@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:02:56 by panesico          #+#    #+#             */
/*   Updated: 2023/06/11 18:03:56 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_free_struc(t_fr *fr)
{
	free (fr);
}

void	ft_declare_struc(t_fr *fr)
{
	fr->n1 = 0;
	fr->n2 = 0;
	fr->r = 0;
	fr->i = 0;
	fr->res = 0;
	fr->x = -2.3;
	fr->y = -1.1;
	fr->m_x = 0;
	fr->m_y = 0;
	fr->reso_h = 2.25;
	fr->reso_w = 4;
	fr->color_offset = 0;
	fr->rel_w = WIDTH;
	fr->rel_h = HEIGHT;
}

t_fr	*ft_create_struc(int argc, char **argv)
{
	t_fr	*fr;

	fr = (t_fr *)ft_calloc(1, sizeof(t_fr));
	if (!fr)
		return (0);
	ft_declare_struc(fr);
	if (argc == 4)
	{
		fr->julia_cons1 = ft_atod(argv[2]);
		fr->julia_cons2 = ft_atod(argv[3]);
	}
	else
	{
		fr->julia_cons1 = 0;
		fr->julia_cons2 = 0;
	}
	fr->mlx = mlx_init(WIDTH, HEIGHT, "Fract-Ol", false);
	fr->img = mlx_new_image(fr->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fr->mlx, fr->img, 0, 0);
	return (fr);
}

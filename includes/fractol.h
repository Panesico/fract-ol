/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:42:19 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/19 20:44:01 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# define WIDTH 1280.0
# define HEIGHT 720.0

// Leaks de MLX

typedef struct s_fract
{
	double		n1;
	double		n2;
	double		r;
	double		i;
	double		res;
	double		x;
	double		y;
	double		reso_h;
	double		reso_w;
	double		rel_w;
	double		rel_h;
	double		julia_cons1;
	double		julia_cons2;
	int			color_offset;
	void		(*fractal_type)(struct s_fract *fr);
	int32_t		m_x;
	int32_t		m_y;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fr;

void		ft_fractal_math_mandel(t_fr *fr);
void		ft_complex_mandel(t_fr *fr, double swap, int x, int y);
void		ft_complex_julia(t_fr *fr, double swap, int x, int y);
void		ft_fractal_math_julia(t_fr *fr);
void		ft_complex_tricorn(t_fr *fr, double swap, int x, int y);
void		ft_fractal_math_tricorn(t_fr *fr);
void		ft_scrollhook(void (*fractal)(t_fr *fr),
				double ydelta, void *param);
t_fr		*ft_create_struc(int argc, char **argv);
uint32_t	ft_rgb(t_fr *fr, int k);
void		hook(struct mlx_key_data keydata, void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		ft_put_pixel(t_fr *fr, int k, int x, int y);
void		ft_free_struc(t_fr *fr);
int			ft_is_num(int argc, char **argv);

#endif
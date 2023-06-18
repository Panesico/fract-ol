/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:42:24 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 17:50:50 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_if_julia(void (**ptr)(t_fr *), int argc)
{
	if (argc == 4)
		*ptr = ft_fractal_math_julia;
	else
	{
		ft_printf("Expected ONLY BOTH x value and y value for Julia set\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_fr	*fr;
	void	(*ptr)(t_fr *);

	if (argc > 1)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")))
			ptr = ft_fractal_math_mandel;
		else if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia")))
			ft_if_julia(&ptr, argc);
		else if (!ft_strncmp(argv[1], "Tricorn", ft_strlen("Tricorn")))
			ptr = ft_fractal_math_tricorn;
		else
			return (ft_printf("Fractals: Mandelbrot, Julia and Tricorn\n"), 0);
	}
	else
		return (ft_printf("Fractals: Mandelbrot, Julia and Tricorn\n"), 0);
	fr = ft_create_struc(argc, argv);
	if (!fr)
		return (-1);
	fr->fractal_type = ptr;
	mlx_scroll_hook(fr->mlx, &my_scrollhook, fr);
	mlx_key_hook(fr->mlx, &hook, fr);
	fr->fractal_type(fr);
	mlx_loop(fr->mlx);
	mlx_terminate(fr->mlx);
	ft_free_struc(fr);
}

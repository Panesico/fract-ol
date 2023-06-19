/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:42:24 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/19 21:09:33 by jorgfern         ###   ########.fr       */
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

void	ft_if_mandelbrot(void (**ptr)(t_fr *), int argc)
{
	if (argc == 2)
		*ptr = ft_fractal_math_mandel;
	else
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void	ft_if_tricorn(void (**ptr)(t_fr *), int argc)
{
	if (argc == 2)
		*ptr = ft_fractal_math_tricorn;
	else
	{
		ft_printf("Error\n");
		exit(0);
	}
}

int	ft_main2(int argc, char **argv, void (**ptr)(t_fr *))
{
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot") + 1))
		ft_if_mandelbrot(&(*ptr), argc);
	else if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia") + 1))
		ft_if_julia(&(*ptr), argc);
	else if (!ft_strncmp(argv[1], "Tricorn", ft_strlen("Tricorn") + 1))
		ft_if_tricorn(&(*ptr), argc);
	else
	{
		ft_printf("Fractals: Mandelbrot, Julia and Tricorn\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_fr	*fr;
	void	(*ptr)(t_fr *);

	ptr = 0;
	if (argc > 1)
	{
		if (!ft_main2(argc, argv, &ptr))
			return (0);
	}
	else
		return (ft_printf("Fractals: Mandelbrot, Julia and Tricorn\n"), 0);
	fr = ft_create_struc(argc, argv);
	if (!fr || !ft_is_num(argc, argv))
		return (ft_printf("Error\n"));
	fr->fractal_type = ptr;
	mlx_scroll_hook(fr->mlx, &my_scrollhook, fr);
	mlx_key_hook(fr->mlx, &hook, fr);
	fr->fractal_type(fr);
	mlx_loop(fr->mlx);
	mlx_terminate(fr->mlx);
	ft_free_struc(fr);
}

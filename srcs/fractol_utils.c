/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:42:24 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/19 21:04:20 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_is_num_util(int i, int *j, char **argv, int *boole)
{
	*boole = 0;
	if (argv[i][0] == '-')
	{
		*j += 1;
		if (argv[i][1] == 0)
			return (0);
	}
	return (1);
}

int	ft_is_num(int argc, char **argv)
{
	int	i;
	int	j;
	int	boole;

	i = 1;
	if (argc > 2)
	{
		while (++i < argc)
		{
			j = -1;
			if (!ft_is_num_util(i, &j, argv, &boole))
				return (0);
			while (argv[i][++j])
			{
				if (!ft_isdigit(argv[i][j]))
				{
					if (argv[i][j] != '.' || (boole == 1 && argv[i][j] == '.'))
						return (0);
					else
						boole++;
				}
			}
		}
	}
	return (1);
}

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
	t_fr	*fr;

	(void)argc;
	(void)argv;
	fr = ft_create_struc();
	mlx_scroll_hook(fr->mlx, &my_scrollhook, fr);
	mlx_key_hook(fr->mlx, &hook, fr);
	ft_fractal_math(fr);
	mlx_loop(fr->mlx);
	mlx_terminate(fr->mlx);
}
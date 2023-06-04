#include "fractol.h"

void	hook(struct mlx_key_data keydata, void *param)
{
	t_fr	*fr;

	fr = (t_fr *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(fr->mlx);
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
		ft_fractal_math(fr);
	}
}

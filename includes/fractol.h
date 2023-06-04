#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <memory.h>
# include <GLFW/glfw3.h>
# define WIDTH 1280.0
# define HEIGHT 720.0

typedef struct s_fract
{
	double cons;
	double n1;
	double n2;
	double r;
	double i;
	double res;
	int iter;
	int *rgb;
	double x;
	double y;
	double reso_h;
	double reso_w;
	double rel_w;
	double rel_h;
	int32_t	m_x;
	int32_t	m_y;
	mlx_t *mlx;
	mlx_image_t	*img;
}	t_fr;

void	ft_fractal_math(t_fr *fr);
t_fr	*ft_create_struc();
uint32_t	ft_rgb(t_fr *fr, int k);
void	hook(struct mlx_key_data keydata, void *param);
void my_scrollhook(double xdelta, double ydelta, void* param);

#endif
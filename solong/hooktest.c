#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	char	*addr1;
	char	*addr2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_vars;

void	my_mlx_pixel_put1(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr1 + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	my_mlx_pixel_put1(t_vars *vars, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = vars->addr1 + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	closewin(int keycode, t_vars *vars)
{
	int		i;
	int		j;

	i = 500;
	j = 300;
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 65363)
	{
		while (i < 1000)
		{
			my_mlx_pixel_put1(&*vars, i++, j, 0x00FF0000);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 0, 0);
		}
	}
	if (keycode == 65364)
	{
		i = 999;
		j = 300;
		while (j < 1000)
		{
			my_mlx_pixel_put1(&*vars, i, j++, 0x00FF0000);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 0, 0);
		} 
	}
	if (keycode == 65362)
	{
		j = 999;
		i = 501;
		while (j > 300)
		{
			my_mlx_pixel_put1(&*vars, i, j--, 0x00FF0000);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 0, 0);
		}
	}
	if (keycode == 65361)
	{
		i = 999;
		j = 999;
		while (i > 500)
		{
			my_mlx_pixel_put1(&*vars, i--, j, 0x00FF0000);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 0, 0);
		}
	}
	else
		printf("%i\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;
	int		j;

	i = 500;
	j = 300;
	vars.mlx = mlx_init();
	vars.img1 = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img2 = mlx_new_image(vars.mlx, 1920, 1080);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.addr1 = mlx_get_data_addr(vars.img1, &vars.bits_per_pixel, &vars.line_length,&vars.endian);
	//vars.addr2 = mlx_get_data_addr(vars.img2, &vars.bits_per_pixel, &vars.line_length,&vars.endian);
	// while (i < 1000)
	// {
	// 	my_mlx_pixel_put1(&vars, i++, 300, 0x00FF0000);
	// 	mlx_put_image_to_window(vars.mlx, vars.win, vars.img1, 0, 0);
	// }
	// 	while (j < 1000)
	// {
	// 	my_mlx_pixel_put1(&vars, i, j++, 0x00FF0000);
	// 	mlx_put_image_to_window(vars.mlx, vars.win, vars.img1, 0, 0);
	// }
	// 	while (i > 500)
	// {
	// 	my_mlx_pixel_put1(&vars, i--, j, 0x00FF0000);
	// 	mlx_put_image_to_window(vars.mlx, vars.win, vars.img1, 0, 0);
	// }
	// 	while (j > 300)
	// {
	// 	my_mlx_pixel_put1(&vars, i, j--, 0x00FF0000);
	// 	mlx_put_image_to_window(vars.mlx, vars.win, vars.img1, 0, 0);
	// }
	mlx_key_hook(vars.win, closewin, &vars);
	//mlx_put_image_to_window(vars.mlx, vars.win, vars.img1, 0, 0);
	mlx_loop(vars.mlx);
}

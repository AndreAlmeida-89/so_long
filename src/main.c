//
//  main.c
//  so_long
//
//  Created by Andre Almeida on 10/01/23.
//

#include "so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int handle_on_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_putendl_fd("Game closed", 1);
	exit(1);
}

int	handle_key_pressed(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 126)
		printf("Go up. ");
	if (keycode == 0 || keycode == 123)
		printf("Go left. ");
	if (keycode == 1 || keycode == 125)
		printf("Go down. ");
	if (keycode == 2 || keycode == 124)
		printf("Go right. ");
	if (keycode == 53)
		handle_on_destroy(vars);
	printf("Keycode: %d\n", keycode);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char **map = read_file(argv[1]);
	if (!*map)
		return (1);
	printf("MAP IS VALID: %d\n", is_valid_map(map));

	t_vars vars;
	t_data img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img,
								 &img.bits_per_pixel,
								 &img.line_length,
								 &img.endian);
	int x = 0;
	while (x < 1920)
	{
		int y = 0;
		while (y < 1080)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, handle_key_pressed, &vars);
	mlx_hook(vars.win, ON_DESTROY, 1L<<0, handle_on_destroy, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

//
//  main.c
//  so_long
//
//  Created by Andre Almeida on 10/01/23.
//

#include "so_long.h"



#define WIDTH 1000
#define HEIGHT 1000


void my_mlx_pixel_put(t_data *data, t_point p, int color)
{
	char *dst;

	dst = data->addr + (p.y * data->line_length + p.x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_p(t_data *img, t_point p)
{
	if (p.x < 0 && p.x > WIDTH)
		return;
	if (p.y < 0 && p.x > HEIGHT)
		return;
	my_mlx_pixel_put(img, p, 0x00FF0000);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char **map = read_file(argv[1]);
	if (!*map)
		return (1);

	printf("MAP IS VALID: %d\n", is_valid_map(map));

	void *mlx;
	void *mlx_win;
	t_data img;

	int width = ft_strlen(*map) * 50;
	int height = str_tab_len(map) * 50;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Hello world!");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	t_point origin = {width / 2, height / 2};

	draw_p(&img, origin);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	return (0);
}

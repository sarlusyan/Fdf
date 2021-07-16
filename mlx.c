#include "fdf.h"

int	key_hook(int keycode)
{
	if (keycode == 53)
        exit(0);
    return 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    connect_points(get_arg *data)
{
    int	x;
	int	y;

	y = 0;
	t_data	img;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data, img);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, key_hook, img.mlx);
	mlx_loop(img.mlx);
}

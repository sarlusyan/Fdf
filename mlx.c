#include "fdf.h"

void	clear(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			mlx_pixel_put(img->mlx, img->mlx_win, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

int	key_hook_my(int keycode, t_data *img)
{
	if (keycode == 53)
        exit(0);
	if (keycode == 0) //a
		img->move_x -= 10;
	if (keycode == 2)// d
		img->move_x += 10;
	if (keycode == 13) // w
		img->move_y -= 10;
	if (keycode == 1) // s
		img->move_y += 10;
	// clear(img);
	connect_points(img);
    return 0;
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    connect_points(t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if (x < img->width - 1)
				bresenham(x, y, x + 1, y, img);
			if (y < img->height - 1)
				bresenham(x, y, x, y + 1, img);
			x++;
		}
		y++;
	}
}

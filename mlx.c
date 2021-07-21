#include "fdf.h"

void	clear()
{
	int	i;
	int	j;

	i = 0;
	while (i < data.height)
	{
		while (j < data.width)
		{
			my_mlx_pixel_put(&img, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

int	key_hook_my(int keycode, t_data *img, get_arg *data)
{
	if (keycode == 53)
        exit(0);
	 if (keycode == 0) //a
		img->x -= 10;
	 if (keycode == 2)
	 	{   printf("HELLO\n");             			// d
			img->x -= 10;
		 }
	 if (keycode == 13) // w
		img->y -= 10;
	if (keycode == 1) // s
		img->y += 10;
	connect_points(data);
	// printf("%d\n", img->x);
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
	while (img.y < data->height)
	{
		img.x = 0;
		while (img.x < data->width)
		{
			if (img.x < data->width - 1)
				bresenham(img.x, img.y, img.x + 1, img.y, data, img);
			if (img.y < data->height - 1)
				bresenham(img.x, img.y, img.x, img.y + 1, data, img);
			img.x++;
		}
		img.y++;
	}
}

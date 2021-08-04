#include "fdf.h"

void	clean(t_data *img)
{
	int i;
	int j;

	i = 0;
	while (i < img->height_w)
	{
		j = 0;
		while (j < img->width_w)
		{
			my_mlx_pixel_put(img, j, i, 0);
			j++;
		}
		i++;
	}
}

// int	key_hook_my(int keycode, t_data *img)
// {
// 	if (keycode == 53)
//         exit(0);
// 	if (keycode == 0 || keycode == 123) //a
// 		img->move_x -= 10;
// 	if (keycode == 2 || keycode == 124)// d
// 		img->move_x += 10;
// 	if (keycode == 13 || keycode == 126) // w
// 		img->move_y -= 10;
// 	if (keycode == 1 || keycode == 125) // s
// 		img->move_y += 10;
// 	if (keycode == 69 || keycode == 24) //+
// 		if (img->zoom < 1291401630)
// 			img->zoom += 3;
// 	if (keycode == 78 || keycode == 27)// -
// 		if (img->zoom > 1)
// 			img->zoom -= 3;
// 	clean(img);
// 	connect_points(img);
//     return 0;
// }

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int    connect_points(t_data *img)
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
	mlx_key_hook(img->mlx_win, key_hook_my, img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_loop(img->mlx);
	return 0;   
}

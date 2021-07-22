#include "fdf.h"

int main(int argc, char **argv)
{
	t_data	img;

    file_parameters(argv[1], &img);
	img.width_w = 1920;
	img.height_w = 1080;
    img.move_x = img.width_w / 2;
    img.move_y = img.height_w / 2;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width_w, img.height_w, "FDF");
	img.img = mlx_new_image(img.mlx, img.width_w, img.height_w);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	connect_points(&img);
    mlx_key_hook(img.mlx_win, key_hook_my, &img);
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
#include "fdf.h"

int main(int argc, char **argv)
{   
   file_parameters(argv[1], &data);
    
    // int i = 0;
    // int j;

    // while (i < data.height)
    // {      
    //   j = 0;
    //     while (j <  data.width)
    //     {
    //         printf("%3d ", data.matrix[i][j]);
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    // }

    img.y = 0;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    mlx_key_hook(img.mlx_win, key_hook_my, img.mlx);
    connect_points(&data);
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
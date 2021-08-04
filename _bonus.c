#include "fdf.h"

int	key_hook_my(int keycode, t_data *img)
{
	if (keycode == 53)
        exit(0);
	if (keycode == 0 || keycode == 123) //a
		img->move_x -= 10;
	if (keycode == 2 || keycode == 124)// d
		img->move_x += 10;
	if (keycode == 13 || keycode == 126) // w
		img->move_y -= 10;
	if (keycode == 1 || keycode == 125) // s
		img->move_y += 10;
	if (keycode == 69 || keycode == 24) //+
		if (img->zoom < 1291401630)
			img->zoom += 3;
	if (keycode == 78 || keycode == 27)// -
		if (img->zoom > 1)
			img->zoom -= 3;
	clean(img);
	connect_points(img);
    return 0;
}
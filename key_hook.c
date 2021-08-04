#include "fdf.h"

int	key_hook_my(int keycode, t_data *img)
{
	if (keycode == 53)
        exit(0);
	clean(img);
	connect_points(img);
    return 0;
}
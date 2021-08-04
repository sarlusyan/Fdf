#include "fdf.h"

float   max_n(float a, float b)
{
    return (a > b) ? a : b;
}

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void    shifting(float *x, float *x1, float *y, float *y1, t_data *img)
{
    *x += img->move_x;
	*x1 += img->move_x;
    *y += img->move_y;
	*y1 += img->move_y;
}

void    _3D_maker(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    bresenham(float x, float y, float x1, float y1, t_data *img)
{
    int     z;
    int     z1;
    int     max;
    float   x_step;
    float   y_step;
   
    z = img->matrix[(int)y][(int)x];  
    z1 = img->matrix[(int)y1][(int)x1];
    x *= img->zoom;
    y *= img->zoom;
    x1 *= img->zoom;
    y1 *= img->zoom;
    img->color = (z || z1) ? 0xffb1b3 : 0xbac9d8;
    _3D_maker(&x, &y, z);
    _3D_maker(&x1, &y1, z1);
    shifting(&x, &x1, &y, &y1, img);
    x_step = x1 - x;
    y_step = y1 - y;
    max = max_n(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;
    while (((int)(x - x1) || (int)(y - y1)) && x > 0)
    {
        if (x > img->width_w || y > img->height_w || y < 0 || x < 0)
			break ;
		my_mlx_pixel_put(img, x, y, img->color);
        x += x_step;
        y += y_step;
    }
}
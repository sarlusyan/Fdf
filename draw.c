#include "fdf.h"

float   max_n(float a, float b)
{
    return (a > b) ? a : b;
}

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void    shifting(float *x, float *x1)
{
	*x += 960;
	*x1 += 960;
}

void    bresenham(float x, float y, float x1, float y1, get_arg *data, t_data img)
{
    int     z;
    int     z1;
    int     max;
    float   x_step;
    float   y_step;
    

    img.zoom = 20;
    z = data->matrix[(int)y][(int)x];  
    z1 = data->matrix[(int)y1][(int)x1];
    x *= img.zoom;
    y *= img.zoom;
    x1 *= img.zoom;
    y1 *= img.zoom;
    img.color = (z) ? 0xffb1b3 : 0xbac9d8;
	shifting(&x, &x1);
    _3D_maker(&x, &y, z);
    _3D_maker(&x1, &y1, z1);
    x_step = x1 - x;
    y_step = y1 - y;
    max = max_n(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;
    
    while (((int)(x - x1) || (int)(y - y1)) && x > 0)
    {
		if (x1 <= 1920 && y1 <= 1080)
			if (x1 >= 0 && y1 >= 0)
		   		my_mlx_pixel_put(&img, x, y, img.color);
        x += x_step;
        y += y_step;
    }
    
}

void    _3D_maker(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}
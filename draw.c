#include "fdf.h"

float   max_n(float a, float b)
{
    return (a > b) ? a : b;
}

float   mod(float i)
{
    return (i < 0) ? -i : i;
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
    img.color = (z) ? 0xe5d5d9 : 0xd5e5e1;
    x_step = x1 - x;
    y_step = y1 - y;
    max = max_n(mod(x_step), mod(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        my_mlx_pixel_put(&img, x, y, img.color);
        x += x_step;
        y += y_step;
    }
}

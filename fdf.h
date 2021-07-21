#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		zoom;
	int		color;
	int		x;
	int		y;
}	t_data;

t_data	img;

typedef struct get_arguments
{
    int height;
    int width;
    int **matrix;

}   get_arg;

get_arg data;

int     get_next_line(int fd, char **line);
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
size_t	get_cnt(char *s, char c);
int     free_machine_str(char **s, size_t idx);
int		ft_strsplit(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
char	**free_machine(char **s, size_t idx);
char	*ft_strdup(char *s1);
void	*ft_memcpy(void *dst, void *src, size_t n);
void    file_parameters(char *file_name, get_arg *data);
int     key_hook_my(int keycode, t_data *img,  get_arg *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    put_pixel(get_arg *data);
void    bresenham(float x, float y, float x1, float y1, get_arg *data, t_data img);
void    connect_points(get_arg *data);
void    _3D_maker(float *x, float *y, int z);
void    shifting();
void	clear();

#endif
#include "fdf.h"

int     get_height(char *file_name)
{
    char    *line;
    int     height;
    int     fd;

    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int     get_width(char *file_name)
{
    char    *line;
    int     width;
    int     fd;

    width = 0;
    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_strsplit(line, ' ');
    free(line);
    close(fd);
    return(width);
}

void    fill_matrix(int *matrix, char *line)
{
    char    **num;
    int     i;

    i = 0;
    num = ft_split(line, ' ');
    while (num[i])
    {
        matrix[i] = ft_atoi(num[i]);
        i++;
    }
    free(num);
}

void    file_parameters(char *file_name, get_arg *data)
{
    int     fd;
    int     i;
    char    *line;

    i = 0;
    data->height = get_height(file_name);
    data->width = get_width(file_name);
    
    data->matrix = (int**)malloc(sizeof(int *) * (data->height));
    while (i <= data->height)
        data->matrix[i++] = (int*)malloc(sizeof(int) * (data->width));
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_matrix(data->matrix[i], line);
        free(line);
        i++;
    }
    close(fd);
 }
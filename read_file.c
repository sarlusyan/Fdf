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
    int     mnacac_width;

    width = 0;
    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_strsplit(line, ' ');
    while (get_next_line(fd, &line))
    {
        
        mnacac_width = ft_strsplit(line, ' '); ;
        if (mnacac_width != width)
        {
            write(1, "ERROR\n", 6);
            exit(0);
        }
        free(line);
    }
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

void    file_parameters(char *file_name, t_data *img)
{
    int     fd;
    int     i;
    char    *line;

    i = 0;
    img->height = get_height(file_name);
    img->width = get_width(file_name);
    
    img->matrix = (int**)malloc(sizeof(int *) * (img->height));
    while (i <= img->height)
        img->matrix[i++] = (int*)malloc(sizeof(int) * (img->width));
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_matrix(img->matrix[i], line);
        free(line);
        i++;
    }
    close(fd);
 }
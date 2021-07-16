#include "fdf.h"

int main(int argc, char **argv)
{
    get_arg data;
    
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
    connect_points(&data);
}
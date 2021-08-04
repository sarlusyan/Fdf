#include "fdf.h"

void    check(int argc, char **argv)
{
    if (argc != 2 || open(argv[argc - 1], O_RDONLY) < 0)
    {
        write(1, "ERROR\n", 6);
        exit(0);
    }
}
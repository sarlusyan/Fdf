#include "fdf.h"

int		get_next_line(int fd, char **line)
{
	int		i;
	int		r;
	char	buffer;
	char	*str;

	if (!(str = (char *)malloc(10000)) || !line)
		return (-1);
	i = 0;
	while ((r = read(fd, &buffer, 1)) && buffer != '\n' && buffer != '\0')
	{
		if (buffer != '\n' && buffer != '\0')
			str[i] = buffer;
		i++;
	}
	str[i] = '\0';
	*line = str;
	return (r);
}
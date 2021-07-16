#include "fdf.h"

int		ft_atoi(char *str)
{
	int sign;
	int ret;

	sign = 1;
	ret = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = -1;
			str++;
		}
		else
			str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * sign);
}
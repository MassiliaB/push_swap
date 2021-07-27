#include "libps.h"

int	is_double(char **all_s, char *str, int i)
{
	int	j;

	j = 0;
	while (all_s[j] && j < i)
	{
		if (!ft_strcmp(all_s[j], str))
			return (0);
		j++;
	}
	return (1);
}

int	number_arg(char **arg)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j] && j < ft_strlen(arg[i]))
		{
			while (ft_isdigit(arg[i][j]))
				j++;
			if (ft_isdigit(arg[i][j - 1]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	len_num(char *arg)
{
	int	i;

	i = 0;
	while (ft_isdigit(arg[i]))
		i++;
	return (i);
}

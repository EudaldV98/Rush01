#include <stdio.h>

int		parser(char *str)
{
	int	i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 4)
		{
			if (str[i] >= '1' && str[i] <= '4')
			{
				j++;
			}
			else if (str[i] != ' ')
				return 1;
			i++;
		}
	}
	return 0;
}

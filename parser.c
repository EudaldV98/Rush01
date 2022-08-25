#include <stdio.h>

int	parser(char *str)
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
				//printf("%c", str[i]);
				j++;
			}
			else if (str[i] != ' ')
				return 1;
			i++;
		}
		// printf("\n");
	}
	//printf("%s\n", str);
	return 0;
}

#include "main.h"

void ft_fill_board(t_data *data, int *i_av, int i, int j)
{
	if ((i > 0 && i < 5) && j == 0)
	{
		data->board[i][j] = data->av[i_av[2]] - '0';
		i_av[2] += 2;
	}
	else if ((i > 0 && i < 5) && j == 5)
	{
		data->board[i][j] = data->av[i_av[3]] - '0';
		i_av[3] += 2;
	}
	else if (i == 0 && (j > 0 && j < 5))
	{
		data->board[i][j] = data->av[i_av[0]] - '0';
		i_av[0] += 2;
	}
	else if (i == 5 && (j > 0 && j < 5))
	{
		data->board[i][j] = data->av[i_av[1]] - '0';
		i_av[1] += 2;
	}
	else if ((i == 0 && j == 0) || (i == 0 && j == 5) ||
			 (i == 5 && j == 0) || (i == 5 && j == 5))
		data->board[i][j] = 8;
	else
		data->board[i][j] = 0;
}	

int		init_board(t_data *data)
{
	int i_av[4];
	int i;

	i_av[0] = 0;
	i_av[1] = 8;
	i_av[2] = 16;
	i_av[3] = 24;
	if (!(data->board = malloc((data->size + 1) * sizeof(int *))))
		return 1;
	data->board[6] = NULL;
	i = 0;
	while (i < data->size)
	{
		if (!(data->board[i] = malloc((data->size + 1) * sizeof(int))))
			return 1;
		int j = 0;
		while(j < data->size)
		{
			ft_fill_board(data, i_av, i, j);
			j++;
		}
		data->board[i][j] = '\n';
		i++;
	}
	return 0;
}

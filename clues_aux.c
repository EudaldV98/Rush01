#include "main.h"

void	fill_col_down(t_data *data, int j)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	while (i < 5)
	{
		if (i > 0)
		{
			data->board[i][j] = x;
			x++;
		}
		i++;
	}
}

void	fill_col_top(t_data *data, int j)
{
	int	i;
	int x;

	i = 5;
	x = 1;
	while (i > 0)
	{
		if (i < 5)
		{
			data->board[i][j] = x;
			x++;
		}
		i--;
	}
}

void	fill_row_right(t_data *data, int i)
{
	int	j;
	int	x;

	j = 0;
	x = 1;
	while (j < 5)
	{
		if (j > 0)
		{
			data->board[i][j] = x;
			x++;
		}
		j++;
	}
}

void	fill_row_left(t_data *data, int i)
{
	int	j;
	int	x;

	j = 5;
	x = 1;
	while (j > 0)
	{
		if (j < 5)
		{
			data->board[i][j] = x;
			x++;
		}
		j--;
	}
}

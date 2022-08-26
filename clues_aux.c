#include "main.h"

void	fill_col_down(t_data *data, int j)
{
	int i = 0;
	char c = '1';

	while (i < 5)
	{
		if (i > 0)
		{
			data->board[i][j] = c;
			c++;
		}
		i++;
	}
}

void	fill_col_top(t_data *data, int j)
{
	int i = 5;
	char c = '1';

	while (i > 0)
	{
		if (i < 5)
		{
			data->board[i][j] = c;
			c++;
		}
		i--;
	}
}

void	fill_row_right(t_data *data, int i)
{
	int j = 0;
	char c = '1';

	while (j < 5)
	{
		if (j > 0)
		{
			data->board[i][j] = c;
			c++;
		}
		j++;
	}
}

void	fill_row_left(t_data *data, int i)
{
	int j = 5;
	char c = '1';

	while (j > 0)
	{
		if (j < 5)
		{
			data->board[i][j] = c;
			c++;
		}
		j--;
	}
}

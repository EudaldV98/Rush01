#include "main.h"

void	clues_of_1(t_data *data, int i, int j)
{
	if (i == 0)
		data->board[i + 1][j] = '4';
	if (i == 5)
		data->board[i - 1][j] = '4';
	if (j == 0)
		data->board[i][j + 1] = '4';
	if (j == 5)
		data->board[i][j - 1] = '4';
}

void	clues_of_N(t_data *data, int i, int j)
{
	if (i == 0)
		fill_col_down(data, j);
	if (i == 5)
		fill_col_top(data, j);
	if (j == 0)
		fill_row_right(data, i);
	if (j == 5)
		fill_row_left(data, i);
}

void	start_clues(t_data *data)
{
	int i = 0;
	int j;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (data->board[i][j] == '1')
				clues_of_1(data, i, j);
			if (data->board[i][j] == '4')
				clues_of_N(data, i, j);
			j++;
		}
		i++;
	}
}

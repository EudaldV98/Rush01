#include "main.h"

int		check_col_up(t_data *data, int col)
{
	int	row;
	int tmp;
	int seen;

	row = 1;
	seen = 0;
	tmp = 0;
	while (row < 5)
	{
		if (data->board[row][col] > tmp)
		{
			seen++;
			tmp = data->board[row][col];
		}
		row++;
	}
	if (seen == data->board[0][col])
		return 1;
	return 0;
}

int		check_col_down(t_data *data, int col)
{
	int	row;
	int tmp;
	int seen;

	row = 4;
	seen = 0;
	tmp = 0;
	while (row >= 1)
	{
		if (data->board[row][col] > tmp)
		{
			seen++;
			tmp = data->board[row][col];
		}
		row--;
	}
	if (seen == data->board[5][col])	
		return 1;
	return 0;
}

int		check_row_left(t_data *data, int row)
{
	int col;
	int tmp;
	int seen;

	col = 1;
	tmp = 0;
	seen = 0;
	while (col < 5)
	{
		if (data->board[row][col] > tmp)
		{
			seen++;
			tmp = data->board[row][col];
		}
		col++;
	}
	if (seen == data->board[row][0])
		return 1;
	return 0;
}

int		check_row_right(t_data *data, int row)
{
	int col;
	int tmp;
	int seen;

	col = 4;
	tmp = 0;
	seen = 0;
	while (col >= 1)
	{
		if (data->board[row][col] > tmp)
		{
			seen++;
			tmp = data->board[row][col];
		}
		col--;
	}
	if (seen == data->board[row][5])
		return 1;
	return 0;
}
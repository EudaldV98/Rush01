#include "main.h"

int     check_row(t_data *data, int pos, int height)
{
	int col;
	int row;
	
	col = 1;
	row = (pos / 4) + 1;
	while (col < 5)
	{
		if (data->board[row][col] == height)
			return 0;
		col++;
	}
	return 1;
}

int     check_col(t_data *data, int pos, int height)
{
	int row;
	int col;

	row = 1;
	col = (pos % 4) + 1;
	while (row < 5)
	{
		if (data->board[row][col] == height)
			return 0;
		row++;
	}
	return 1;
}

int     check(t_data *data, int pos, int height)
{
	if (!check_row(data, pos, height))
		return 0;
	if (!check_col(data, pos, height))
		return 0;
	return 1;
}

#include "main.h"

int     check_clues(t_data *data)
{
    int col;
	int row;

	col = 1;
	while (col < 5)
	{
		if (data->board[0][col] == 4 || data->board[0][col] == 1)
			if (!check_col_up(data, col))
				return 0;
		if (data->board[5][col] == 4 || data->board[5][col] == 1)
			if (!check_col_down(data, col))
				return 0;
		col++;
	}
	row = 1;
	while (row < 5)
	{
		if (data->board[row][0] == 4 || data->board[row][0] == 1)
			if (!check_row_left(data, row))
				return 0;
		if (data->board[row][5] == 4 || data->board[row][5] == 1)
			if(!check_row_right(data, row))
				return 0;
		row++;
	}
    return 1;
}

int     check_sol(t_data *data)
{
    int col;
	int row;

	col = 1;
	while (col < 5)
	{
        if (!check_col_up(data, col))
            return 0;
		if (data->board[5][col] == 4 || data->board[5][col] == 1)
			if (!check_col_down(data, col))
				return 0;
		col++;
	}
	row = 1;
	while (row < 5)
	{
        if (!check_row_left(data, row))
            return 0;
		if (data->board[row][5] == 4 || data->board[row][5] == 1)
			if(!check_row_right(data, row))
				return 0;
		row++;
	}
    return 1;
}

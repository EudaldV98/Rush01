#include "main.h"

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    print_solved(t_data *data)
{
	int row;
	int col;

	row = 1;
	while (row < 5)
	{
		col = 1;
		while (col < 5)
		{
			ft_putchar(data->board[row][col] + '0');
			if (col < 4)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int     backtracking(t_data *data, int pos)
{
	int height;

	if (pos == 16)
	{
		if (check_sol(data))
		{
			print_solved(data);
			return 1;
		}
		return 0;
	}
	height = 1;
	while (height <= 4)
	{
		if (check(data, pos, height))
		{
			data->board[(pos / 4) + 1][(pos % 4) + 1] = height;
			if (!backtracking(data, pos + 1))
				data->board[(pos / 4) + 1][(pos % 4) + 1] = 0;
			else
				return 1;
		}
		height++;
	}
	return 0;
}

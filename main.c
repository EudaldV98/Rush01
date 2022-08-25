#include "main.h"

void ft_fill_board(t_data *data, int *i_av, int i, int j)
{
	if ((i > 0 && i < 5) && j == 0)
	{
		data->board[i][j] = data->av[i_av[2]];
		i_av[2] += 2;
	}
	else if ((i > 0 && i < 5) && j == 5)
	{
		data->board[i][j] = data->av[i_av[3]];
		i_av[3] += 2;
	}
	else if (i == 0 && (j > 0 && j < 5))
	{
		data->board[i][j] = data->av[i_av[0]];
		i_av[0] += 2;
	}
	else if (i == 5 && (j > 0 && j < 5))
	{
		data->board[i][j] = data->av[i_av[1]];
		i_av[1] += 2;
	}
	else if ((i == 0 && j == 0) || (i == 0 && j == 5) || (i == 5 && j == 0) || (i == 5 && j == 5))
		data->board[i][j] = '0';
	else
		data->board[i][j] = '.';
}

int		init_board(t_data *data)
{
	int i_av[4];
	int i;

	i_av[0] = 0;
	i_av[1] = 8;
	i_av[2] = 16;
	i_av[3] = 24;
	if (!(data->board = malloc((data->size + 1) * sizeof(char *))))
		return 1;
	data->board[6] = NULL;
	i = 0;
	while (i < data->size)
	{
		if (!(data->board[i] = malloc((data->size + 1) * sizeof(char))))
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

int		main(int ac, char **av)
{
	t_data data;

	//Parsing
	if (parser(av[1]) == 1)
		return 1;
	
	//Board init
	
	data.size = 6;
	data.av = av[1];
	init_board(&data);

	//Start with simplest clues, N and 1
	
	int i = 0;
	int j;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (data.board[i][j] == '1')
				clues_of_1(&data, i, j);
			if (data.board[i][j] == '4')
				clues_of_N(&data, i, j);
			j++;
		}
		i++;
	}

	//Check after N and 1 clues

	//Bactracking

	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 6; j++)
		{
			printf("%c", data.board[i][j]);	
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}

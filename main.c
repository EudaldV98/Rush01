#include "main.h"

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

	start_clues(&data);

	//Check after N and 1 clues
	
	int i = 0;
	int j;
	char count[4];

	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (i == 0 && data.board[i][j] != '0')
				printf("%c ", data.board[i][j]);
			if (i == 5 && data.board[i][j] != '0')
				printf("%c ", data.board[i][j]);
			if (j == 0 && data.board[i][j] != '0')
				printf("%c ", data.board[i][j]);
			if (j == 5 && data.board[i][j] != '0')
				printf("%c ", data.board[i][j]);
			else
				printf("");
			j++;
		}
		printf("\n");
		i++;
	}

	printf("\n-----------------\n");
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

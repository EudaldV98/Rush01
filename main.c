#include "main.h"

int		main(int ac, char **av)
{
	t_data data;

	//Parsing
	if (ac != 2)
		return 0;
	if (parser(av[1]) == 1)
		return 1;
	
	//Board init
	
	data.size = 6;
	data.av = av[1];
	init_board(&data);

	//Start with simplest clues, N and 1

	// start_clues(&data);

	//Check after N and 1 clues
	// check_clues(&data);

	//Bactracking

	 if (!backtracking(&data, 0))
	 	write(1, "ERROR\n", 6);

	// for (size_t i = 0; i < 6; i++)
	// {
	// 	for (size_t j = 0; j < 6; j++)
	// 	{
	// 		printf("%d", data.board[i][j]);	
	// 		printf(" ");
	// 	}
	// 	printf("\n");
	// }
	return 0;
}

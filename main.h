#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct  g_data
{
	char **board;
	int size;
	char *av;
}               t_data;

//Parser
int	    parser(char *str);

//Board
void    ft_fill_board(t_data *data, int *i_av, int i, int j);
int     init_board(t_data *data);

//Clues
void	clues_of_N(t_data *data, int i, int j);
void	clues_of_1(t_data *data, int i, int j);
void	start_clues(t_data *data);

//Clues_aux
void	fill_col_down(t_data *data, int j);
void    fill_col_top(t_data *data, int j);
void	fill_row_right(t_data *data, int i);
void	fill_row_left(t_data *data, int i);

#endif

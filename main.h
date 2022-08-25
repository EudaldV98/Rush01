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


int	parser(char *str);

#endif
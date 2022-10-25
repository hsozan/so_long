#include "../includes/so_long.h"

void    env_check(t_game *g)
{
    int i;
    int j;

    i = 0;
    
    while (i < g->max_y)
    {
        j = 0;
        while (j < g->max_x)
        {
            if (g->map[i][j] == 'P')
                {   
                    g->player_x = j;
                    g->player_y = i;
                    g->player++;
                }
            if (g->map[i][j] == 'C')
                g->coin++;
            if (g->map[i][j] == 'E')
                g->exit++;
            j++;
        }
        i++;
    }
    if (g->player != 1 || g->coin < 1 || g->exit <1)
        ft_err('h');
}

void    char_check(t_game *g)
{
    int i;
    int j;

    i =0;
    while (i < g->max_y)
    { 
        j = 0;
        while (j < g->max_x && g->map[i][j] != '\0')
        {  
            if (!(ft_strchr("01CEPN", g->map[i][j])))
                ft_err('g');
            j++;
        }
        i++;
    }
}
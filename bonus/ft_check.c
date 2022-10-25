#include "../includes/so_long_bonus.h"

void    check_format(char *str)
{
    char *s;

    s = ft_strrchr(str, '.');
    if (s == NULL || ft_strncmp(s + 1, "ber", 4) != 0)
        ft_err('b');
}

void wall_check(t_game  *g)
{
    int i;
    int y;
    int x;

    i = -1;
    y = g->max_y - 1;
    x = g->max_x - 1;
    while (i++ < y)
        if (g->map[i][0] != '1' || g->map[i][x] != '1')
            ft_err('f');
    i = -1;
    while(i++ < x)
        if(g->map[0][i] != '1' || g->map[y][i] != '1')
            ft_err('f');
}

int map_x(char *s)
{
    int i;

    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    return (i);
}

void rectangle_check(t_game *g)
{
    int i;

    i = 0;
    g->max_x = map_x(g->map[i]);
    if (g->max_x < 3)
        ft_err('e');
    while (i < g->max_y)
    {
        if (g->max_x != map_x(g->map[i]))
            ft_err('e');
        g->map[i][g->max_x] = '\0';
        i++;
    }
}

void    check_map(t_game    *g)
{
    g->player = 0;
    g->exit = 0;
    g->coin = 0;
    rectangle_check(g);
    wall_check(g);
    char_check(g);
    env_check(g);
    valid_path(g);
}
#include "../includes/so_long.h"
static void up(t_game *g)
{
    if (g->map[g->player_y - 1][g->player_x] != '1')
    {
        if (g->map[g->player_y - 1][g->player_x] == '0')
        {
            g->map[g->player_y - 1][g->player_x] = 'P';
            g->map[g->player_y][g->player_x] = '0';
        }
        if (g->map[g->player_y - 1][g->player_x] == 'C')
        {
            g->map[g->player_y - 1][g->player_x] = 'P';
            g->map[g->player_y][g->player_x] = '0';
            g->coin--;
        }
        if (g->map[g->player_y - 1][g->player_x] == 'E' && g->coin == 0)
        {
            mlx_clear_window(g->mlx, g->window);
            exit(0);
        }
        if (g->map[g->player_y - 1][g->player_x] != 'E')
            g->player_y--;
    }
}

static void down(t_game *g)
{
    if (g->map[g->player_y + 1][g->player_x] != '1')
    {
        if (g->map[g->player_y + 1][g->player_x] == '0')
        {
            g->map[g->player_y + 1][g->player_x] = 'P';
            g->map[g->player_y][g->player_x] = '0';
        }
        if (g->map[g->player_y + 1][g->player_x] == 'C')
        {
            g->map[g->player_y + 1][g->player_x] = 'P';
            g->map[g->player_y][g->player_x] = '0';
            g->coin--;
        }
        if (g->map[g->player_y + 1][g->player_x] == 'E' && g->coin == 0)
        {
            mlx_clear_window(g->mlx, g->window);
            exit(0);
        }
        if (g->map[g->player_y + 1][g->player_x] != 'E')
            g->player_y++;
    }
}

static void left(t_game *g)
{
    if (g->map[g->player_y][g->player_x - 1] != '1')
    {
        if (g->map[g->player_y][g->player_x - 1] == '0')
        {
            g->map[g->player_y][g->player_x - 1] = 'P';
            g->map[g->player_y][g->player_x] = '0';
        }
        if (g->map[g->player_y][g->player_x - 1] == 'C')
        {
            g->map[g->player_y][g->player_x - 1] = 'P';
            g->map[g->player_y][g->player_x] = '0';
            g->coin--;
        }
        if (g->map[g->player_y][g->player_x - 1] == 'E' && g->coin == 0)
        {
            mlx_clear_window(g->mlx, g->window);
            exit(0);
        }
        if (g->map[g->player_y][g->player_x - 1] != 'E')
            g->player_x--;
    }
}

static void right(t_game *g)
{
    if (g->map[g->player_y][g->player_x + 1] != '1')
    {
        if (g->map[g->player_y][g->player_x + 1] == '0')
        {
            g->map[g->player_y][g->player_x + 1] = 'P';
            g->map[g->player_y][g->player_x] = '0';
        }
        if (g->map[g->player_y][g->player_x + 1] == 'C')
        {
            g->map[g->player_y][g->player_x + 1] = 'P';
            g->map[g->player_y][g->player_x] = '0';
            g->coin--;
        }
        if (g->map[g->player_y][g->player_x + 1] == 'E' && g->coin == 0)
        {
            mlx_clear_window(g->mlx, g->window);
            exit(0);
        }
        if (g->map[g->player_y][g->player_x + 1] != 'E')
            g->player_x++;
    }
}

int redraw_map(t_game *g)
{
    mlx_clear_window(g->mlx, g->window);
    draw_img(g);
    return (0);
}


int key_func(int code, t_game *g)
{
    if (code == 13)
        up(g);
    if (code == 1)
        down(g);
    if (code == 0)
        left(g);
    if (code == 2)
        right(g);
    if (code == 53)
       {
        free(g);
        exit (1);
       }
    return (0);
}
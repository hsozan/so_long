#include "../includes/so_long_bonus.h"

void put_img(t_game *g)
{
    int x;
    int y;

    x = 70;
    y = 73;
    g->img = malloc(sizeof(t_img));
    g->img->back = mlx_xpm_file_to_image(g->mlx, "xpm/a.xpm", &x, &y);
    g->img->e1 = mlx_xpm_file_to_image(g->mlx, "xpm/en1.xpm", &x, &y);
    g->img->e2 = mlx_xpm_file_to_image(g->mlx, "xpm/en2.xpm", &x, &y);
    g->img->e3 = mlx_xpm_file_to_image(g->mlx, "xpm/en3.xpm", &x, &y);
    g->img->e4 = mlx_xpm_file_to_image(g->mlx, "xpm/en4.xpm", &x, &y);
    g->img->door_1 = mlx_xpm_file_to_image(g->mlx, "xpm/d1.xpm", &x, &y);
    g->img->door_2 = mlx_xpm_file_to_image(g->mlx, "xpm/d2.xpm", &x, &y);
    g->img->door_3 = mlx_xpm_file_to_image(g->mlx, "xpm/d3.xpm", &x, &y);
    g->img->door_4 = mlx_xpm_file_to_image(g->mlx, "xpm/d4.xpm", &x, &y);
    g->img->loot_1 = mlx_xpm_file_to_image(g->mlx, "xpm/k1.xpm", &x, &y);
    g->img->loot_2 = mlx_xpm_file_to_image(g->mlx, "xpm/k2.xpm", &x, &y);
    g->img->loot_3 = mlx_xpm_file_to_image(g->mlx, "xpm/k3.xpm", &x, &y);
    g->img->loot_4 = mlx_xpm_file_to_image(g->mlx, "xpm/k4.xpm", &x, &y);
    g->img->wall_1 = mlx_xpm_file_to_image(g->mlx, "xpm/R1.xpm", &x, &y);
    g->img->wall_2 = mlx_xpm_file_to_image(g->mlx, "xpm/R2.xpm", &x, &y);
    g->img->wall_3 = mlx_xpm_file_to_image(g->mlx, "xpm/R3.xpm", &x, &y);
    g->img->wall_4 = mlx_xpm_file_to_image(g->mlx, "xpm/R4.xpm", &x, &y);
    g->img->player_1 = mlx_xpm_file_to_image(g->mlx, "xpm/player_r_l.xpm", &x, &y);
    g->img->player_2 = mlx_xpm_file_to_image(g->mlx, "xpm/player_dow.xpm", &x, &y);
    g->img->player_3 = mlx_xpm_file_to_image(g->mlx, "xpm/player_r_l.xpm", &x, &y);
    g->img->player_4 = mlx_xpm_file_to_image(g->mlx, "xpm/player_up.xpm", &x, &y);
}

void draw_wall(t_game *g, int x, int y)
{
    if (g->counter == 1 || g->counter == 0)
        mlx_put_image_to_window(g->mlx, g->window, g->img->wall_1, x * 70, y * 73);
    if (g->counter == 2)
        mlx_put_image_to_window(g->mlx, g->window, g->img->wall_2, x * 70, y * 73);
    if (g->counter == 3)
        mlx_put_image_to_window(g->mlx, g->window, g->img->wall_3, x * 70, y * 73);
    if (g->counter == 4)
        mlx_put_image_to_window(g->mlx, g->window, g->img->wall_4, x * 70, y * 73);
}
void draw_player(t_game *g, int x, int y)
{
    if (g->counter == 1 || g->counter == 0)
        mlx_put_image_to_window(g->mlx, g->window, g->img->player_1, x * 70, y * 73);
    if (g->counter == 2)
        mlx_put_image_to_window(g->mlx, g->window, g->img->player_2, x * 70, y * 73);
    if (g->counter == 3)
        mlx_put_image_to_window(g->mlx, g->window, g->img->player_3, x * 70, y * 73);
    if (g->counter == 4)
        mlx_put_image_to_window(g->mlx, g->window, g->img->player_4, x * 70, y * 73);
}
void draw_coin(t_game *g, int x, int y)
{
    if (g->counter == 1 || g->counter == 0)
        mlx_put_image_to_window(g->mlx, g->window, g->img->loot_1, x * 70, y * 73);
    if (g->counter == 2)
        mlx_put_image_to_window(g->mlx, g->window, g->img->loot_2, x * 70, y * 73);
    if (g->counter == 3)
        mlx_put_image_to_window(g->mlx, g->window, g->img->loot_3, x * 70, y * 73);
    if (g->counter == 4)
        mlx_put_image_to_window(g->mlx, g->window, g->img->loot_4, x * 70, y * 73);
}

void draw_door(t_game *g, int x, int y)
{
    if (g->counter == 1 || g->counter == 0)
        mlx_put_image_to_window(g->mlx, g->window, g->img->door_1, x * 70, y * 73);
    if (g->counter == 2)
        mlx_put_image_to_window(g->mlx, g->window, g->img->door_2, x * 70, y * 73);
    if (g->counter == 3)
        mlx_put_image_to_window(g->mlx, g->window, g->img->door_3, x * 70, y * 73);
    if (g->counter == 4)
        mlx_put_image_to_window(g->mlx, g->window, g->img->door_4, x * 70, y * 73);
}
void draw_enemy(t_game *g, int x, int y)
{
    if (g->counter == 1 || g->counter == 0)
        mlx_put_image_to_window(g->mlx, g->window, g->img->e1, x * 70, y * 73);
    if (g->counter == 2)
        mlx_put_image_to_window(g->mlx, g->window, g->img->e2, x * 70, y * 73);
    if (g->counter == 3)
        mlx_put_image_to_window(g->mlx, g->window, g->img->e3, x * 70, y * 73);
    if (g->counter == 4)
        mlx_put_image_to_window(g->mlx, g->window, g->img->e4, x * 70, y * 73);
}

void draw_img_ul(t_game *g, int x, int y)
{
        if (g->counter == 5)
          g->counter = 1;
        if (g->map[y][x] == '0')
            mlx_put_image_to_window(g->mlx, g->window, g->img->back, x * 70, y * 73);
        if (g->map[y][x] == '1')
            draw_wall(g, x, y);
        if (g->map[y][x] == 'P')
            draw_player(g, x, y);
        if (g->map[y][x] == 'C')
            draw_coin(g, x, y);
        if (g->map[y][x] == 'E')
            draw_door(g, x, y);
        if (g->map[y][x] == 'N')
            draw_enemy(g, x, y);
        g->counter++;  
        
}
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdbool.h>
# include <fcntl.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_img
{
    void    *back;
    void    *loot_1;
    void    *loot_2;
    void    *loot_3;
    void    *loot_4;
    void    *player_1;
    void    *player_2;
    void    *player_3;
    void    *player_4;
    void    *door_1;
    void    *door_2;
    void    *door_3;
    void    *door_4;
    void    *wall_1;
    void    *wall_2;
    void    *wall_3;
    void    *wall_4;
    void    *e1;
    void    *e2;
    void    *e3;
    void    *e4;
}t_img;

typedef struct s_game
{
    void    *mlx;
    void    *window;
    int     max_x;
    int     max_y;
    int     player_x;
    int     player_y;
    int     coin;
    int     player;
    int     exit;
    int     enemy;
    int     ch_coin;
    int     ch_exit;
    int     move;
    int     counter;
    char    **map;
    t_img   *img;
}t_game;

void    check_map(t_game    *g);
void    check_format(char *str);
void    char_check(t_game *g);
void    env_check(t_game *g);
void    ft_err(char c);
void    valid_path(t_game *err);
int     key_func(int code, t_game *g);
int     redraw_map(t_game *g);
void    draw_img(t_game *g);
void    create_mlx(t_game *g);
void    draw_img_ul(t_game *g, int x, int y);
void    put_img(t_game *g);

#endif
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
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
    void    *loot;
    void    *player;
    void    *door;
    void    *wall;
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
    int     ch_coin;
    int     ch_exit;
    int     move;
    char    **map;
    t_img   *img;
}t_game;

int     redraw_map(t_game *g);
void    draw_img(t_game *g);
int     key_func(int code, t_game *g);
void    check_map(t_game    *g);
void    check_format(char *str);
void    char_check(t_game *g);
void    env_check(t_game *g);
void    ft_err(char c);
void    valid_path(t_game *err);
void    create_mlx(t_game *g);
void    draw_img_ul(t_game *g, int x, int y);

#endif
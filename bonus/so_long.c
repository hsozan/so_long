#include "../includes/so_long_bonus.h"

int fnd_max_y(char *a)
{
    char     *s;
    int     i;
    int     fd;

    i = 0;
    fd = open(a, O_RDONLY);
    if (fd < 0)
        ft_err('c');
    s = get_next_line_str(fd);
    while (s)
    {
        i++;
        free(s);
        s = get_next_line_str(fd);
    }
    return (i);
}

void    map_init(t_game *g, char *av)
{
    char    *s;
    int     i;
    int     fd;

    i = 0;
    g->max_y = fnd_max_y(av);
    fd = open(av, O_RDONLY);
    g->map = malloc(sizeof(char *) * g->max_y);
    if (fd == -1 || !g->map || g->max_y < 3)
        ft_err('d');
    s = get_next_line_str(fd);
    while(i < g->max_y)
    {
       
        g->map[i] = s;
        i++;
        s = get_next_line_str(fd);
    }
    close(fd);
}



void draw_img(t_game *g)
{
    int x;
    int y;
    

    y = 0;
    while( y < g->max_y)
    {
        x = 0;
        while(x < g->max_x)
        {
            draw_img_ul(g, x, y);
            x++;
        }
        y++;
    }
}
void create_mlx(t_game *g)
{
    g->mlx = mlx_init();
    g->window = mlx_new_window(g->mlx,g->max_x * 70, g->max_y * 73,"so_long");
    g->counter = 0;
    put_img(g);
    draw_img(g);
    g->move = 0;
    mlx_hook(g->window, 02, 0, key_func, g);
    mlx_loop_hook(g->mlx, redraw_map, g);
    mlx_loop(g->mlx);
}

int main(int ac, char **av)
{
    t_game  *game;

    if (ac !=2)
        ft_err('a');
    check_format(av[1]);
    game = malloc(sizeof(t_game));
    map_init(game, av[1]);
    check_map(game);
    create_mlx(game);
}
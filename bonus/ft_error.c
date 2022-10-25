#include "../includes/so_long_bonus.h"

void ft_err(char c)
{   
    ft_printf("\n!!!==========Error==========!!!\n");

    if (c == 'a')
        ft_printf("\n---> You entered missing or too many arguments <---\n");
    else if(c == 'b')
        ft_printf("\n---> Your file extension is not .ber <---\n");
    else if(c == 'c')
        ft_printf("\n---> File description eroor <---\n");
    else if(c == 'd')
        ft_printf("\n---> fd=-1 || !map || y < 3 <---\n");
    else if(c == 'e')
        ft_printf("\n---> Not rectangular or x <---\n");
    else if(c == 'f')
        ft_printf("\n---> The perimeter is not walled <---\n");
    else if(c == 'g')
        ft_printf("\n---> Undefined character <---\n");
    else if(c == 'h')
        ft_printf("\n---> İnventory error <---\n");
    else if(c == 'i')
        ft_printf("\n---> No valid path <---\n");

    ft_printf("\n!!!==========Error==========!!!\n");
    exit (1);

}
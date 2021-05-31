/*
** EPITECH PROJECT, 2020
** main
** File description:
** main of navy
*/

#include "include/navy.h"

int do_connection(int ac, char **av)
{
    if (ac == 2) {
        return (waiting_signal());
    } else if (ac == 3) {
        get_connected(av);
        return (my_getnbr(av[1]));
    }
}

int main(int ac , char **av)
{
    int pid_other = 0;
    int score;

    if (handle_error(ac, av) == -1)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        display_h();
        return (0);
    }
    pid_other = do_connection(ac, av);
    if (ac == 2)
        score = navy(ac, av[1], pid_other);
    else if (ac == 3)
        score = navy(ac, av[2], pid_other);
    if (score == 0)
        my_putstr("\nI won\n");
    else if (score == 1)
        my_putstr("Enemy won\n");
    return (0);
}

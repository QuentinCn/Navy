/*
** EPITECH PROJECT, 2020
** NAVY
** File description:
** display_h
*/

#include "../../include/navy.h"

void display_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("     navy_positions: file representing ");
    my_putstr("the positions of the ships.\n");
}

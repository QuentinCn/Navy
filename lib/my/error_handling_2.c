/*
** EPITECH PROJECT, 2020
** error handling 2
** File description:
** more error handling
*/

#include "../../include/navy.h"

int check_overlay(char *position)
{
    char *board = malloc(sizeof(char) * 500);
    int nb[4] = {0, 0, 0, 0};

    board = create_board(position, board);
    for (int i = 0; board[i] != '\0'; i += 1) {
        if (board[i] == '2')
            nb[0] += 1;
        if (board[i] == '3')
            nb[1] += 1;
        if (board[i] == '4')
            nb[2] += 1;
        if (board[i] == '5')
            nb[3] += 1;
    }
    free(board);
    if (nb[0] != 4 || nb[1] != 5 || nb[2] != 6 || nb[3] != 7)
        return (-1);
    return (0);
}

/*
** EPITECH PROJECT, 2020
** attack
** File description:
** allow players to attack
*/

#include "../../include/navy.h"

char *place_attack_on_board(char *board, char *attack_pos, int touch)
{
    if (touch == 0) {
        board[(attack_pos[0] - 'A') * 2 + 254 + 18 * (attack_pos[1] - '1')] =
            'o';
        my_putstr(attack_pos);
        my_putstr(": missed\n");
    } else if (touch == 1) {
        board[(attack_pos[0] - 'A') * 2 + 254 + 18 * (attack_pos[1] - '1')] =
            'x';
        my_putstr(attack_pos);
        my_putstr(": hit\n");
    }
    for (int i = 405; attack_pos[i - 405] != '\0'; i += 1) {
        board[i] = attack_pos[i - 405];
    }
    return (board);
}

int place_attack_on_enemy(int ac, char *board_enemy, char *attack_pos)
{
    int touch = 0;

    if (board_enemy[(attack_pos[0] - 'A')* 2 + 52 + 18 * (attack_pos[1] - '1')]
        == '.') {
        board_enemy[(attack_pos[0] - 'A') * 2 + 52 + 18 * (attack_pos[1] - '1')]
            = 'o';
        touch = 0;
    } else {
        board_enemy[(attack_pos[0] - 'A') * 2 + 52 + 18 * (attack_pos[1] - '1')]
            = 'x';
        touch = 1;
    }
    if (modify_enemy_board(ac, board_enemy) == 84)
        return (84);
    return (touch);
}

char *attack(int ac, char *board, char *attack_pos)
{
    int fd = -1;
    int size = 0;
    char board_enemy[500];
    int touch = 0;

    if (ac == 2)
        fd = open("game_board_2", O_RDONLY);
    else if (ac == 3)
        fd = open("game_board_1", O_RDONLY);
    size = read(fd, board_enemy, 499);
    if (size == -1)
        return (board);
    board_enemy[size] = '\0';
    touch = place_attack_on_enemy(ac, board_enemy, attack_pos);
    if (touch == 84)
        return ("error open");
    board = place_attack_on_board(board, attack_pos, touch);
    return (board);
}

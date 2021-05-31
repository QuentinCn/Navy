/*
** EPITECH PROJECT, 2020
** verification
** File description:
** multiple kind of verification
*/

#include "../../include/navy.h"

int verif_attack(char *attack_pos, char *board)
{
    if (attack_pos[0] < 'A' || attack_pos[0] > 'H') {
        my_putstr("wrong position");
        return (-1);
    }
    if (attack_pos[1] < '1' || attack_pos[1] > '8') {
        my_putstr("wrong position");
        return (-1);
    }
    if (board[(attack_pos[0] - 'A') * 2 + 254 + 18 * (attack_pos[1] - '1')] !=
        '.') {
        my_putstr("wrong position");
        return (-1);
    }
    return (0);
}

int check_for_win(int ac, char *board)
{
    int x = 0;
    int y = 0;
    int fd = (ac == 2) ? open("game_board_2", O_RDONLY):
    open("game_board_1", O_RDONLY);
    int size;
    char enemy_board[500];

    size = read(fd, enemy_board, 499);
    enemy_board[size] = '\0';
    for (int i = 52; i <= 192; i += 2) {
        x = (board[i] == 'x') ? x + 1: x;
        y = (enemy_board[i] == 'x') ? y + 1: y;
    }
    if (x == 14)
        return (1);
    else if (y == 14)
        return (0);
    return (2);
}

void check_enemy_last_attack(int ac)
{
    char enemy_board[500];
    int size;
    int fd = (ac == 2) ? open("game_board_2", O_RDONLY):
    open("game_board_1", O_RDONLY);
    char *attack_pos = malloc(sizeof(char) * 4);

    if (fd == -1)
        my_put_error("open error");
    size = read(fd, enemy_board, 499);
    enemy_board[size] = '\0';
    attack_pos = &enemy_board[405];
    if (attack_pos[0] == '_') {
        my_putstr("\n");
        return;
    }
    write(1, attack_pos, my_strlen(attack_pos) - 1);
    if (enemy_board[(attack_pos[0] - 'A') * 2 + 254 + 18 * (attack_pos[1] - '1')] ==  'x')
        my_putstr(": hit\n\n");
    else
        my_putstr(": missed\n\n");
}
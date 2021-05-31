/*
** EPITECH PROJECT, 2020
** display_game
** File description:
** display
*/

#include "../../include/navy.h"

char *complete_board(char *board, char *position)
{
    char k = 0;

    for (int i = 0; position[i + 3] != '\0'; i += 1) {
        if (position[i] >= 'A' && position[i] <= 'H') {
            board[52 + (position[i] - 'A') * 2 + (position[i + 1] - '1') * 18] =
                (i % 2 == 0) ? position[i - 2]: position[i - 5];
            k = (i % 2 == 0) ? position[i - 2]: position[i - 5];
            for (int j = 0; j < k - '0' && position[i] == position[i + 3]
            ; j += 1) {
                board[52 + (position[i] - 'A') * 2 + (position[i + 1] - '1') *
                18 + j * 18] = k;
            }
            for (int j = 0; j < k - '0' && position[i] != position[i + 3] &&
                    position[i + 3] >= 'A'; j += 1) {
                board[52 + (position[i] - 'A') * 2 + (position[i + 1] - '1') *
                    18 + j * 2] = k;
            }
        }
    }
    return (board);
}

char *create_board(char *position, char *board)
{
    int fd = open("game_board", O_RDWR);
    int fd2 = open(position, O_RDONLY);
    int size = 0;
    char buffer_pos[33];

    size = read(fd, board, 499);
    board[size] = '\0';
    close(fd);
    size = read(fd2, buffer_pos, 32);
    if (size == -1)
        return ("failed read");
    buffer_pos[size] = '\0';
    board = complete_board(board, buffer_pos);
    return (board);
}

int modify_board(int ac, char *new_board)
{
    int fd = -1;
    int size = 0;

    if (ac == 2)
        fd = open("game_board_1", O_RDWR | O_CREAT, 0775);
    else if (ac == 3)
        fd = open("game_board_2", O_RDWR | O_CREAT, 0775);

    write(fd, new_board, my_strlen(new_board));
    close(fd);
    return (0);
}

int modify_enemy_board(int ac, char *new_board)
{
    int fd = -1;
    int size = 0;

    if (ac == 3)
        fd = open("game_board_1", O_RDWR | O_CREAT, 0775);
    else if (ac == 2)
        fd = open("game_board_2", O_RDWR | O_CREAT, 0775);
    if (fd == -1)
        return (84);
    write(fd, new_board, my_strlen(new_board));
    close(fd);
    return (0);
}

char *update_board(int ac, char *board)
{
    int fd;
    int size;

    if (ac == 2)
        fd = open("game_board_1", O_RDONLY);
    else if (ac == 3)
        fd = open("game_board_2", O_RDONLY);
    size = read(fd, board, my_strlen(board));
    board[size] = '\0';
    close(fd);
    return (board);
}


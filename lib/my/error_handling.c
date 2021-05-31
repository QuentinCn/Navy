/*
** EPITECH PROJECT, 2020
** error_handling
** File description:
** handle_error
*/

#include "../../include/navy.h"

#define MAX_FILE_SIZE 32

static int check_file_position(char *position)
{
    int i = 2;
    int line = 2;

    for (int f = 0; f < 4; f += 1, i += 8, line += 1) {
        if (position[i + 3] == position[i] &&
            position[i + 4] - position[i + 1] != line - 1)
            return (-1);
        if (position[i + 3] != position[i] &&
            position[i + 3] - position[i] != line - 1 &&
            position[i + 4] == position[i + 1])
            return (-1);
    }
    return (0);
}

static int check_file_second(char *position)
{
    int list[6] = {0, 1, 2, 3, 4, 2};

    for (int f = 0; f < 4; f += 1, list[0] += 8, list[1] += 8, list[2] += 8) {
        if (position[list[1]] != ':' || position[list[4]] != ':' ||
            (position[list[2]] < 'A' || position[list[2]] > 'H') ||
            position[list[0]] != list[5] + '0' || (position[list[3]] < '1' ||
            position[list[3]] > '8') || (position[list[2] + 3] < 'A' ||
            position[list[2] + 3] > 'H') || (position[list[3] + 3] < '1' ||
            position[list[3] + 3] > '8'))
            return (-1);
        list[3] += 8;
        list[4] += 8;
        list[5] += 1;
    }
    return (0);
}

static int check_file(int fd, char *filepath)
{
    char position[MAX_FILE_SIZE + 1];
    int size;

    size = read(fd, position, MAX_FILE_SIZE + 1);
    position[size] = '\0';
    if (size > MAX_FILE_SIZE)
        return (-1);
    if (check_file_second(position) == -1)
        return (-1);
    if (check_file_position(position))
        return (-1);
    if (check_overlay(filepath) == -1)
        return (-1);
    return (0);
}

int check_pid(char *pid)
{
    for (int i = 0; pid[i] != '\0'; i += 1) {
        if (pid[i] < '0' || pid[i] > '9')
            return (-1);
    }
    return (0);
}

int handle_error(int ac, char **av)
{
    int fd;

    if (ac != 2 && ac != 3)
        return (-1);
    fd = open(av[ac - 1], O_RDONLY);
    if (fd == -1)
        return (-1);
    if (ac == 2 && check_file(fd, av[ac - 1]) == -1)
        return (-1);
    if (ac == 3 && (check_file(fd, av[ac - 1]) == -1 || check_pid(av[1]) == -1))
        return (-1);
    return (0);
}

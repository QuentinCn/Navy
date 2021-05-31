/*
** EPITECH PROJECT, 2020
** navy
** File description:
** launch the navy game
*/

#include "include/navy.h"

char *do_attack_part(int ac, char *board)
{
    char attack_pos[4];

    do {
        my_putstr("\nattack: ");
        if (read(1, attack_pos, 3) != -1)
            attack_pos[2] = '\0';
    } while (verif_attack(attack_pos, board) != 0);
    board = attack(ac, board, attack_pos);
    return (board);
}

void handle_sig(int signal, siginfo_t *info, void *old_info)
{
    return;
}

char *wait_for_enemy(int ac, char *board)
{
    struct sigaction action;
    struct timespec t = {120, 0};

    action.sa_flags = 0;
    sigemptyset(&action.sa_mask);
    action.sa_sigaction = &handle_sig;
    sigaction(SIGUSR1, &action, NULL);
    nanosleep(&t, 0);
    check_enemy_last_attack(ac);
    board = update_board(ac, board);
    return (board);
}

char *do_in_loop(int ac, char *board, int pid_other)
{
    write(1, board, my_strlen(board) - 12);
    board = do_attack_part(ac, board);
    if (modify_board(ac, board) == 84)
        return ("error");
    if (check_for_win(ac, board) != 2)
        return (board);
    kill(pid_other, SIGUSR1);
    my_putstr("\nwaiting for enemy's attack...\n");
    board = wait_for_enemy(ac, board);
    return (board);
}

int navy(int ac, char *position, int pid_other)
{
    char *board = malloc(sizeof(char) * 500);
    struct sigaction action;
    int winner = 0;

    board = create_board(position, board);
    if (modify_board(ac, board) == 84)
        return (84);
    if (ac == 3) {
        action.sa_sigaction = &handle_sig;
        action.sa_flags = 0;
        sigemptyset(&action.sa_mask);
        sigaction(SIGUSR1, &action, NULL);
        pause();
    }
    do {
        board = do_in_loop(ac, board, pid_other);
        if (board == "error")
            return (84);
    } while (check_for_win(ac, board) == 2);
    kill(pid_other, SIGUSR1);
    winner = check_for_win(ac, board);
    free(board);
    return (winner);
}

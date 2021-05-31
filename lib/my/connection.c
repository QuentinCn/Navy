/*
** EPITECH PROJECT, 2020
** connection
** File description:
** manage connection between the terminals
*/

#include "../../include/navy.h"

int globalpid = 0;

void get_pid(int sig, siginfo_t *info, void *context)
{
    globalpid = info->si_pid;
}

void sig_handler(int signal)
{
    my_putstr("\nsuccesfully connected\n\n");
}

void get_connected(char **av)
{
    struct sigaction action;

    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\n");
    action.sa_flags = 0;
    sigemptyset(&action.sa_mask);
    action.sa_handler = &sig_handler;
    kill(my_getnbr(av[1]), SIGUSR2);
    sigaction(SIGUSR1, &action, NULL);
}

int waiting_signal(void)
{
    struct sigaction action;

    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\n");
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    action.sa_sigaction = &get_pid;
    sigaction(SIGUSR2, &action, NULL);
    pause();
    my_putstr("\n\nenemy connected\n\n");
    kill(globalpid, SIGUSR1);
    return (globalpid);
}

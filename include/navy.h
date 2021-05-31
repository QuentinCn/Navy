/*
** EPITECH PROJECT, 2020
** navy.h
** File description:
** .h of navy
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <ucontext.h>

char *my_strcat(char *str1, char *str2);
int my_strlen(char *str);
void display_h(void);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char *str);
int my_put_error(char *str);
int my_getnbr(char const *str);
void kill_it(int pid);
int handle_error(int ac, char **av);
char *create_board(char *position, char *board);
int modify_board(int ac, char *new_board);
int navy(int ac, char *position, int pid_other);
char *attack(int ac, char *board, char *attack_pos);
int modify_enemy_board(int ac, char *new_board);
int verif_attack(char *attack_pos, char *board);
int check_for_win(int ac, char *board);
void check_enemy_last_attack(int ac);
char *update_board(int ac, char *board);
int waiting_signal(void);
void get_connected(char **av);
int check_overlay(char *position);
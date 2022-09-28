#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "machine.h"

char* random_string_of_integers(int size);
int get_prize_for_combination(char* combination);

machine* init_machine(int balance, int bet_size, int columns_count){
    machine* machine = malloc(sizeof *machine);

    machine->balance = balance;
    machine->bet_size = bet_size;
    machine->columns_count = columns_count;

    return machine;
}

void play(machine* machine){
    if (machine->balance < machine->bet_size)
    {
        printf("\nYou lost.");
        exit(0);
    }
    char* combination = random_string_of_integers(machine->columns_count);
    
    int prize = get_prize_for_combination(combination);
    printf("\nRolled combination %s with prize %d", combination, prize);

    machine->balance += prize - machine->bet_size;
}

char* random_string_of_integers(int size){
    char* string = malloc(size+1);
    for (size_t i = 0; i < size; i++)
    {
        string[i] = rand()%10 + '0';
    }
    string[size] = '\0';
    return string;
}

int get_prize_for_combination(char* combination){
    if (strcmp(combination, "777") == 0)
    {
        printf("\nWon a jackpot");
        exit(0);
    }
    if (strcmp(combination, "111") == 0)
    {
        return 10;
    }
    if (strcmp(combination, "222") == 0)
    {
        return 20;
    }
    if (strcmp(combination, "333") == 0)
    {
        return 30;
    }
    if (strcmp(combination, "444") == 0)
    {
        return 40;
    }
    if (combination[0] == '5' && combination[1] == '5' && combination[2] == '5')
    {
        return 100;
    }
    if (combination[0] == '5' && combination[1] == '5')
    {
        return 70;
    }
    if (combination[0] == '5')
    {
        return 50;
    }
    if (combination[0] == '7' && combination[1] == '7')
    {
        return 250;
    }
    if (combination[0] == 7)
    {
        return 150;
    }
    if (strcmp(combination, "666") == 0)
    {
        return -500;
    }
    return 0;
}

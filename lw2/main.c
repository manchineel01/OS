#include <stdio.h>
#include "machine.h"


int main(){
    machine* machine = init_machine(5000, 50, 3);
    while (1)
    {
        play(machine);
        printf("\nCurrent balance: %d", machine->balance);
    }
    return -1;
}

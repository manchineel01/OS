typedef struct 
{
    int balance;
    int bet_size;
    int columns_count;
} machine;

machine* init_machine(int balance, int bet_size, int columns_count);

void play(machine* machine);

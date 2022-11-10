#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    char* text = getenv(argv[1]);
    if (text == NULL)
    {   
        return system("/proc/self/statm");
    }
    
    printf("%s", text);
}


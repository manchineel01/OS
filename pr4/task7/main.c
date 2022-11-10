#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char** environ;

int main(int argc, char *argv[]){
    char env_var_name[100];

    printf("Enter env_var name to delete: ");
    scanf("%s", env_var_name);

    if (strlen(env_var_name) == 0)
    {
        return clearenv();
    }
    
    unsetenv(env_var_name);

    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}
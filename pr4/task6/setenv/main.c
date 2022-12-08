#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char env_var_name[100], env_var_value[100];

    printf("Enter env_var name: ");
    scanf("%s", env_var_name);

    printf("Enter env_var value: ");
    scanf("%s", env_var_value);

    if (setenv(env_var_name, env_var_value, 1) == -1)
    {
        return printf("Error occured");
    }
    
    printf("%s=%s", env_var_name, getenv(env_var_name));
}
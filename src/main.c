#include "../include/shell.h"

int main() 
{
    shell_loop();
    return 0;
}

void shell_loop() 
{
    char *line = NULL;
    size_t bufsize = 0;
    char **args;
    int status = 1;

    while (status) 
    {
        printf("uabshell > ");
        
        // READ: Get input from user
        if (getline(&line, &bufsize, stdin) == -1) 
        {
            break;
        }

        // EVALUATE: Parse the string into tokens
        args = parse_line(line);

        // EXECUTE: Run any command
        if (args[0] != NULL) 
        {
            status = execute_command(args);
        }

        free(args);
    }
    free(line);
}
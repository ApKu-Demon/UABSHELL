#include "../include/shell.h"

int execute_command(char** args) 
{
    // Process built-in commands (exit, cd) . . .
    if (strcmp(args[0], "exit") == 0) 
    {
        return 0;
    }

    if (strcmp(args[0], "cd") == 0) 
    {
        if (args[1] == NULL) 
        {
            fprintf(stderr, "uabshell: expected argument to \"cd\"\n");
        }
        else if (chdir(args[1]) != 0){
            perror("uabshell");
        }
        return 1;
    }

    // Fork and Execute external commands . . .
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) 
    {
        // CHILD PROCESS: Try to execute the command
        if (execvp(args[0], args) == -1) {
            perror("uabshell error");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0) {
        // Error forking
        perror("uabshell");
    }
    else {
        // PARENT PROCESS: Wait for the child to finish before continuing the loop (shell_loop)
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}
#include "../include/shell.h"

#define TOK_BUFSIZE 32
#define TOK_DELIM " \t\r\n\a"

char** parse_line(char* line) 
{
    int bufsize = TOK_BUFSIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    // Validation of memory allocation with malloc
    if (!tokens) 
    {
        fprintf(stderr, "uabshell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Use strtok to split the string
    token = strtok(line, TOK_DELIM);
    while (token != NULL) 
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize) 
        {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, TOK_DELIM);    // NULL to continue were we left off in the string
    }
    
    tokens[position] = NULL; // NULL to terminate the array for execvp
    return tokens;
}
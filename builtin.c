#include <stdio.h>
#include <unistd.h>

#include "builtin.h"
#include "shell.h"

char *builtin_str[] = 
{
    "cd",
    "pwd",
    "echo"
};


void (*builtin_func[]) (char**) = 
{
    &builtin_cd,
    &builtin_pwd,
    &builtin_echo
};

int num_builtins()
{
    return (sizeof(builtin_str) / sizeof(char*));
}

void builtin_cd(char** arguments)
{
    if(arguments[1] == NULL)
    {
        if(chdir(home_dir) == -1)
            printError();
    }
    else if(chdir(arguments[1]) == -1)
        printError();
}

void builtin_pwd(char** arguments)
{
    char* cur_dir = NULL;
    cur_dir = getcwd(NULL, 0);
    
    if(cur_dir == NULL)
        printError();
    
    printf("%s\n", cur_dir);
}

void builtin_echo(char** arguments)
{
    int i;
    for(i=1; arguments[i]; ++i)
    {
        if(i!=1)
            printf(" ");
        printf("%s", arguments[i]);
    }
    printf("\n");
}

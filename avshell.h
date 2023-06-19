#ifndefHELL_H
#defineHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>


#define BUFFER_SIZE 1024
#define Max_Command 20






void command_prompt(char **av, char **env);


#endif


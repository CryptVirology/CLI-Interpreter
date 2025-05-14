#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_LINE 1024

void parse_input(char* input, char** args) {
    int i = 0;
    args[i] = strtok(input, " \n");
    while (args[i] != NULL && i < MAX_ARGS - 1) {
        args[++i] = strtok(NULL, " \n");
    }
    args[i] = NULL;
}

int main() {
    char input[MAX_LINE];
    char* args[MAX_ARGS];

    while (1) {
        printf("mini-shell> ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        parse_input(input, args);

        if (args[0] == NULL) continue;

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == 0) {
            // Child process: check for output redirection
            for (int i = 0; args[i] != NULL; ++i) {
                if (strcmp(args[i], ">") == 0) {
                    int fd = open(args[i+1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
                    if (fd < 0) {
                        perror("open failed");
                        exit(1);
                    }
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                    args[i] = NULL;
                    break;
                }
            }

            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        } else if (pid > 0) {
            waitpid(pid, NULL, 0);
        } else {
            perror("fork failed");
        }
    }

    return 0;
}


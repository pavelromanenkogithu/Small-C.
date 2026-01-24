# Small-C.
Parent child zombies
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();

    switch (pid) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        case 0:
            printf("Child exiting\n");
            exit(EXIT_SUCCESS);

        default:
            printf("Child is PID %" PRIdMAX "\n", (intmax_t)pid);
            waitpid(pid, NULL, 0); // wait for child
            printf("Parent exiting\n");
            exit(EXIT_SUCCESS);
    }

    return 0;
}

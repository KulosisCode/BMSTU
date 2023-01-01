#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TIME_SLEEP 2
#define N 2

int main()
{
    pid_t children[N];

    printf("Parent process start. PID: %d, GROUP: %d\n",getpid(), getpgrp());

    for (int i = 0; i < N; i++)
    {
        if ((children[i] = fork()) == -1)
        {
            perror("Can't fork!\n");
            exit(1);
        }
        else if (children[i] == 0)
        {
            printf("\nBefore sleep: Child %d | PID = %d, PPID: %d, GROUP: %d\n", i + 1,getpid(), getppid(), getpgrp());
            sleep(TIME_SLEEP);
            printf("\nAfter sleep: Child %d| PID = %d, PPID: %d, GROUP: %d\n", i + 1,getpid(), getppid(), getpgrp());
            
            return EXIT_SUCCESS;
        }
        else
        {
            printf("Parent: pid = %d, GROUP: %d, Child = %d\n", getpid(), getpgrp(), children[i]);
        }
    }

    return EXIT_SUCCESS;
}

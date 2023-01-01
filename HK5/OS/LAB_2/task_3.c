#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 2

int main()
{
    char *exe[N] = { "./task_3_1.exe", "./task_3_2.exe" };

    pid_t children[N];
    int status;

    for (int i = 0; i < N; i++)
    {
        if ((children[i] = fork()) == -1)
        {
            perror("Can't fork\n");

            exit(EXIT_FAILURE);
        }
        else if (children[i] == 0)
        {
            printf("Child PID%d, GROUP %d, PPID %d\n", getpid(), getpgrp(), getppid());

	    	if (execl(exe[i], exe[i], NULL) == -1)
            {
	    	    perror("Error exec");

                exit(EXIT_FAILURE);
            }
        }
        else
        {
            printf("Parent: PID = %d, GROUP = %d, child = %d\n", getpid(), getpgrp(), children[i]);
        }
    }
    for (int i = 0; i < N; i++)
    {

        children[i] = waitpid(children[i], &status, 0);

        if (children[i] == -1)
        {
            perror("Can't wait\n");

            exit(EXIT_FAILURE);
        }

        printf("Child %d finished, status: %d\n", children[i], status);

        if (WIFEXITED(status))
            printf("Child finished, code: %d\n", WEXITSTATUS(status));
        else if (WIFSIGNALED(status))
            printf("Child finished, signal %d\n", WTERMSIG(status));
        else if (WIFSTOPPED(status))
            printf("Child stopped, signal %d\n", WSTOPSIG(status));
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define TIME_SLEEP 2
#define N 2

int flag = 0;

void sig_handler(int sig_n)
{
    flag = 1;
	printf("\n СATCH %d\n", sig_n);
}

int main(void)
{
    if(signal(SIGINT, sig_handler) == SIG_ERR)
    {
        perror("Can't signal!");
        exit(EXIT_FAILURE);
    }
    sleep(TIME_SLEEP);
    
 	int fd[2];

	if (pipe(fd) == -1)
	{
	    perror("Pipe error\n");

	    exit(EXIT_FAILURE);
	}

	char message[2][100] = { "theskyisbluezzzzzz\n", "superman\n" };
    
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
            printf("Child %d, group %d, parent %d\n", getpid(), getpgrp(), getppid());

            if (flag)
            {
                close(fd[0]);
                write(fd[1], message[i], strlen(message[i]));
                printf("%d sent message %s\n", getpid(), message[i]);
            }
            else
            {
                printf("No signal.\n");
                return EXIT_SUCCESS;
            }
           
	        return EXIT_SUCCESS;
	    }
        else
        {
            children[i] = waitpid(children[i], &status, WCONTINUED);

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
	}
    if (flag)
    {
        printf("Message receive \n");
        close(fd[1]);
    
        if (read(fd[0], message[0], sizeof(message[0])) == -1)
            return EXIT_FAILURE;
        
        printf("%s", message[0]);
    }    
   

    return EXIT_SUCCESS;
}
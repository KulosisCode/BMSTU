#include "header.h"

void menu(void)
{
    printf("%s",
           "\nARRAY:\n"
           "1) Add element\n"
           "2) Delete element\n"
           "3) Print queue\n"
           "4) Show processing of 1000 request \n");
    printf("%s",
           "\nLIST:\n"
           "5) Add element\n"
           "6) Delete element\n"
           "7) Print queue\n"
           "8) Show processing of 1000 request\n"
           "9) Show time effect\n"
           "0) EXIT\n\n"
           "Input command: ");
}

void message(int rc)
{
    switch (rc)
	{
        case -1: printf("ERROR_COMMAND\n"); break;
        case -2: printf("ERROR_OVER_FLOW\n"); break;
        case -3: printf("ERROR_EMPTY_STACK\n"); break;
        case -4: printf("ERROR_INPUT\n"); break;
        default:
            break;
	}
}

void clear()
{
    int ch;
    while ((ch = fgetc(stdin)) != '\n' && ch != EOF);
}

int input_number(int *elem)
{
    if (fscanf(stdin, "%d", elem) != 1)
    {
        return ERR_INPUT;
    }
    return OK;
}

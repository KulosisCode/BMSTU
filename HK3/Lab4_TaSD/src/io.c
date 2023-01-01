#include "header.h"

void menu(void)
{
    printf("%s",
           "\nARRAY STACK:\n"
           "1) Input stacks\n"
           "2) Add stack\n"
           "3) Delete stack\n"
           "4) Palindrome?\n"
           "5) Print stacks\n");
    printf("%s",
           "\nLIST STACK:\n"
           "6) Input stack\n"
           "7) Add stack\n"
           "8) Delete stack\n"
           "9) Palindrome?\n"
           "10) Print stacks\n"
           "11) Show effect\n"
           "0) Exit\n\n"
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
        // case 5: printf("FILE_OPEN_ERROR"); break;
        // case 6: printf("NOT_SQUARE_MATRIX"); break;
        // case 7: printf("NO_ELEMENT_FOUND"); break;
        default:
            break;
	}
}

void clear()
{
    int ch;
    while ((ch = fgetc(stdin)) != '\n' && ch != EOF);
}

int input_symbol(char *sym)
{
    if (fscanf(stdin, "%c", sym) != 1)
    {
        return ERR_INPUT;
    }
    return OK;
}

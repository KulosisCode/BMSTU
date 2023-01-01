#include "international_strtok.h"

int main(void)
{
    int successful_tests = 0;

    char str1[20] = "Come here";
    char delim1[2]= " ";
    char *result1 = strtok(str1, delim1);
    if (result1 == str1)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 1 failed\n");
    }

    char str2[20] = "I... am iron man";
    char delim2[3] = ". ";
    char *result2 = strtok(str2, delim2);
    result2 = strtok(NULL, delim2);
    if (result2 == str2 + 5)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 2 failed\n");
    }

    char str3[20] = "Hey,come,here";
    char delim3[2] = ",";
    char *result3 = strtok(str3, delim3);
    result3 = strtok(NULL, delim3);
    if (result3 == str3 + 4)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 3 failed\n");
    }

    char str4[20] = "maybe";
    char delim4[2] = " ";
    char *result4 = strtok(str4, delim4);
    result4 = strtok(NULL, delim4);
    if (result4 == NULL)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 4 failed\n");
    }

    char str5[20] = "Electric is power";
    char delim5[2] = "";
    char *result5 = strtok(str5, delim5);
    while (result5 != NULL)
    {
        result5 = strtok(NULL ,delim5);
    }
    if (result5 == NULL)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 5 failed\n");
    }

    char str6[20] = "    ";
    char delim6[2] = " ";
    char *result6 = strtok(str6, delim6);
    while (result6 != NULL)
    {
        result6 = strtok(NULL ,delim6);
    }
    if (result6 == NULL)
    {
        successful_tests++;
    }   
    else
    {
        printf("Test 6 failed\n");
    }
    printf("%d / 6 TESTS SUCCESSFUL\n", successful_tests);
    return 0;
}
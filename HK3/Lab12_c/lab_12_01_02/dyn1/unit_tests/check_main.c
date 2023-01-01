#include "../inc/check_main.h"

int main(void)
{
    int no_failed = 0;
    Suite *s_1, *s_2;
    SRunner *runner_1, *runner_2;
    
    s_1 = check_sort();
    runner_1 = srunner_create(s_1);
    srunner_run_all(runner_1, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner_1);

    s_2 = check_filter();
    runner_2 = srunner_create(s_2);
    srunner_run_all(runner_2, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner_2);

    srunner_free(runner_1);
    srunner_free(runner_2);

    return (no_failed  == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}   
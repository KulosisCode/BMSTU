#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    Suite *s_1, *s_2, *s_3;
    SRunner *runner_1, *runner_2, *runner_3;
    
    s_1 = add_matrix_suite();
    runner_1 = srunner_create(s_1);
    srunner_run_all(runner_1, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner_1);

    srunner_free(runner_1);

    s_2 = mult_matrix_suite();
    runner_2 = srunner_create(s_2);
    srunner_run_all(runner_2, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner_2);

    srunner_free(runner_2);

    s_3 = get_gaus_det_suite();
    runner_3 = srunner_create(s_3);
    srunner_run_all(runner_3, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner_3);

    srunner_free(runner_3);

    return (no_failed  == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
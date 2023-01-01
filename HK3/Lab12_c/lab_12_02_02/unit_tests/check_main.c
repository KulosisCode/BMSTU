#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *run;

    s = fibonacci_fill_suite();
    run = srunner_create(s);
    srunner_run_all(run, CK_VERBOSE);
    no_failed = srunner_ntests_failed(run);

    s = get_first_meet_suite();
    run = srunner_create(s);
    srunner_run_all(run, CK_VERBOSE);
    no_failed = srunner_ntests_failed(run);

    srunner_free(run);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
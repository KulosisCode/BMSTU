#include "io_table.h"

void buble_sort(student *person, const int size)
{
    student *temp = (student*) malloc (sizeof(student));
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (person[j].age > person[j + 1].age)
            {
                *temp = person[j];
                person[j] = person[j + 1];
                person[j + 1] = *temp;
            }
        }
    free(temp);
}

void insert_binary_sort(student *person, const int size)
{
    student *temp = (student*) malloc (sizeof(student));
    for (int i = 1; i < size; i++)
    {
        int bg = 0;
        int ed = i;
        int mid;
        if (bg == ed)
            bg++;
        else
        {
            while (bg < ed)
            {
                mid = (bg + ed) / 2;
                if (person[i].age < person[mid].age)
                    ed = mid;
                else 
                    bg = mid + 1;
            }
        }    
        int j = i;
        while (j > bg && j > 0)
        {
            *temp = person[j];
            person[j] = person[j - 1];
            person[j - 1] = *temp;
            j--;
        }
    }
    free(temp);
}

void buble_sort_key(keys *key, const int size)
{
    keys *temp = (keys*) malloc (sizeof(keys));
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (key[j].age > key[j + 1].age)
            {
                *temp = key[j];
                key[j] = key[j + 1];
                key[j + 1] = *temp;
            }
        }
    free(temp);
}

void insert_binary_sort_key(keys *key, const int size)
{
    keys *temp = (keys*) malloc (sizeof(keys));
    for (int i = 1; i < size; i++)
    {
        int bg = 0;
        int ed = i;
        int mid;
        if (bg == ed)
            bg++;
        else
        {
            while (bg < ed)
            {
                mid = (bg + ed) / 2;
                if (key[i].age < key[mid].age)
                    ed = mid;
                else 
                    bg = mid + 1;
            }
        }    
        int j = i;
        while (j > bg && j > 0)
        {
            *temp = key[j];
            key[j] = key[j - 1];
            key[j - 1] = *temp;
            j--;
        }
    }
    free(temp);
}

void random_table_data(student *person, keys *key, const int size)
{
    srand(time(NULL));
    int i = 0;
    while(i < size)
    {
        person[i].type_home = 1;
        strcpy(person[i].family, "family");
        strcpy(person[i].name, "name");
        strcpy(person[i].group, "iu");
        person[i].sex = rand() % 2;
        person[i].age = rand() % 82 + 18;
        person[i].mark = rand() % 101;
        strcpy(person[i].date, "01.01.2001");
        person[i].home.dorm.num_dorm = rand() % MAX_HOME;
        person[i].home.dorm.num_room = rand() % MAX_ROOM;
        i++;
    }
}

void test_sort_table()
{
	struct timeval tv_start, tv_stop;
	int64_t s_1 = 0, s_2 = 0, k_1 = 0, k_2 = 0, temp1, temp2, temp3;
	student *person;
	keys *key;
	srand(time(NULL));
	printf("|---------------------------|------------|------------|\n");
	printf("| Table size(students)      | %10i | %10i |\n", NUM_1, NUM_2);
	printf("|---------------------------|------------|------------|\n");

	person = (student*) malloc (sizeof(student) * NUM_1);
	key = (keys*) malloc (sizeof(keys) * NUM_1);

	random_table_data(person, key, NUM_1);

	gettimeofday(&tv_start, NULL);
	buble_sort(person, NUM_1);
	gettimeofday(&tv_stop, NULL);
	s_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);


	gettimeofday(&tv_start, NULL);
	buble_sort_key(key, NUM_1);
	gettimeofday(&tv_stop, NULL);
	k_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);

	free(person);
	free(key);

	person = (student*) malloc (sizeof(student) * NUM_2);
	key = (keys*) malloc (sizeof(keys) * NUM_2);

	random_table_data(person, key, NUM_2);

	gettimeofday(&tv_start, NULL);
	buble_sort(person, NUM_2);
	gettimeofday(&tv_stop, NULL);
	s_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);

	gettimeofday(&tv_start, NULL);
	buble_sort_key(key, NUM_2);
	gettimeofday(&tv_stop, NULL);
	k_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);

	free(person);
	free(key);


	printf("| Bubble sort (mcsec)       | %10lld | %10lld |\n", s_1, s_2);
	printf("|---------------------------|------------|------------|\n");
	printf("| Bubble key sort (mcsec)   | %10lld | %10lld |\n", k_1, k_2);
	printf("|---------------------------|------------|------------|\n");

    temp1 = s_1; temp2 = k_1;
	s_1 = 0; s_2 = 0;
	k_1 = 0; k_2 = 0;

	person = (student*) malloc (sizeof(student) * NUM_1);
	key = (keys*) malloc (sizeof(keys) * NUM_1);

	random_table_data(person, key, NUM_1);

	gettimeofday(&tv_start, NULL);
	insert_binary_sort(person, NUM_1);
	gettimeofday(&tv_stop, NULL);
	s_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);


	gettimeofday(&tv_start, NULL);
	insert_binary_sort_key(key, NUM_1);
	gettimeofday(&tv_stop, NULL);
	k_1 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);

	free(person);
	free(key);

	person = (student*) malloc (sizeof(student) * NUM_2);
	key = (keys*) malloc (sizeof(keys) * NUM_2);

	random_table_data(person, key, NUM_2);

	gettimeofday(&tv_start, NULL);
	insert_binary_sort(person, NUM_2);
	gettimeofday(&tv_stop, NULL);
	s_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);


	gettimeofday(&tv_start, NULL);
	insert_binary_sort_key(key, NUM_2);
	gettimeofday(&tv_stop, NULL);
	k_2 += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);

	free(person);
	free(key);

	printf("| Quick sort (mcsec)        | %10lld | %10lld |\n", s_1, s_2);
	printf("|---------------------------|------------|------------|\n");
	printf("| Quick key sort (mcsec)    | %10lld | %10lld |\n", k_1, k_2);
	printf("|---------------------------|------------|------------|\n");

    temp3 = s_1;

	s_1 = sizeof(student) * NUM_1;
	s_2 = sizeof(student) * NUM_2;

	printf("| Main table memory (bytes) | %10llu | %10llu |\n", s_1, s_2);
	printf("|---------------------------|------------|------------|\n");

	k_1 = sizeof(keys) * NUM_1;
	k_2 = sizeof(keys) * NUM_2;

	printf("| Key table memory (bytes)  | %10llu | %10llu |\n", k_1, k_2);
	printf("|---------------------------|------------|------------|\n");

    printf("Quick sort is faster %llu%% than Bubble sort.(for Main Table)\n", (100 * temp1 / temp3) - 100);
    printf("Key Table sort is faster %llu%% than Main Table sort.(for method Bubble sort)\n", (100 * temp1 / temp2) - 100);
    printf("Main Table with key use %llu%% more bytes than Main Table with out key table.\n", (100 * (k_1 + s_1) / s_1) - 100);
	printf("\n");
}
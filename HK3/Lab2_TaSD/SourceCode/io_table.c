#include "io_table.h"

void message()
{
    printf("\nMenu :\n");
    printf("1 - Add record to table\n");
    printf("2 - Delete record from table\n");
    printf("3 - Print Table\n");
    printf("4 - Print Key Table\n");
    printf("5 - Print Table by Key\n");
    printf("6 - Sort Table\n");
    printf("7 - Sort Key Table\n");
    printf("8 - Find student\n");
    printf("9 - Show comparations of sort(time)\n");
    printf("0 - Exit\n");
}

int check_file(FILE *file)
{
    if (file == NULL)
    {
        printf("ERROR NO FILE!\n");
        return ERR_EMPTY;
    }

    if (fgetc(file) == EOF)
    {
        printf("ERROR EMPTY FILE!\n");
        fclose(file);
        return ERR_EMPTY;
    }
    rewind(file);
    return OK;
}

int read_number(FILE *file, int *num, const int min, const int max, const int *index)
{
    int ch;
    char *temp;
    short run = 1;
    int i = 0;
    temp = (char*) malloc (MAX_CHAR_SIZE * sizeof(*temp));
    ch = fgetc(file);
    if (ch == '\n' || ch == EOF)
    {   
        printf("ERROR: EMPTY - RECORD %d\n", *index); 
        return ERR_EMPTY;
    }

    while (run)
    {
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
        temp[i++] = ch;
        ch = fgetc(file);
    }
    ch = atoi(temp);
    free(temp);
    if (ch > max || ch < min)
    {
        printf("ERROR: WRONG DATA - RECORD %d\n", *index);
        return WRONG_DATA;
    }
    *num =  ch;
    return OK;
    
}
int read_char(FILE *file, char *str, int size, const int *index)
{
    int num = 0;
    short run = 1;
    int rc = fgetc(file);
    if (rc == '\n' || rc == EOF)
    {
        printf("ERROR: EMPTY - RECORD %d\n", *index);
        return ERR_EMPTY;
    }
    while(run)
    {
        if (num > size)
        {
            printf("ERROR: OVER SIZE CHAR - RECORD %d\n", *index);
            return ERR_OVER_SIZE;
        }
        if (rc == '\n' || rc == EOF)
        {
            str[num] = '\0';
            break;
        }
        str[num++] = rc;
        rc = fgetc(file);
    }
    return OK;
}


void read_from_file(FILE *file, student *person, keys *key, int *index)
{
    int num = 0, code = 0;
    char *str;
    str = (char*)malloc(MAX_CHAR_SIZE * sizeof(char));
    while (!feof(file))
    {
        if (*index >= MAX_SIZE)
        {
            printf("TABLE NOW IS FULL!\n");
            break;
        }

        //home
        code = read_number(file, &num, 0, 1, index);
        if (code == OK)
            person[*index].type_home = num;
        else break;

        //family
        code = read_char(file, str, MAX_CHAR_SIZE, index);
        if (code == OK)
            strcpy(person[*index].family, str);
        else break;

        //name
        code = read_char(file, str, MAX_CHAR_SIZE, index);
        if (code == OK)
            strcpy(person[*index].name, str);
        else break;

        //group
        code = read_char(file, str, MAX_CHAR_SIZE, index);
        if (code == OK)
            strcpy(person[*index].group, str);
        else break;

        //sex
        code = read_number(file, &num, 0, 1, index);
        if (code == OK)
            person[*index].sex = num;
        else break;

        //age
        code = read_number(file, &num, MIN_AGE, MAX_AGE, index);
        if (code == OK)
        {
            person[*index].age = num;
            key[*index].age = num;
        }
        else break;

        //mark
        code = read_number(file, &num, MIN_MARK, MAX_MARK, index);
        if (code == OK)
            person[*index].mark = num;
        else break;

        //data born
        code = read_char(file, str, MAX_DATE, index);
        if (code == OK)
            strcpy(person[*index].date, str);
        else break;

        //live in house
        if (person[*index].type_home == 0)
        {
            //street
            code = read_char(file, str, MAX_CHAR_SIZE, index);
            if (code == OK)
                strcpy(person[*index].home.house.street, str);
            else break;

            //number of house
            code = read_number(file, &num, 1, MAX_HOME, index);
            if (code == OK)
                person[*index].home.house.num_house = num;
            else break;

            //number of apartment
            code = read_number(file, &num, 1, MAX_ROOM, index);
            if (code == OK)
                person[*index].home.house.num_apartment = num;
            else break;
        }
        //live in dorm
        else
        {
            //number of dorm
            code = read_number(file, &num, 1, MAX_HOME, index);
            if (code == OK)
                person[*index].home.dorm.num_dorm = num;
            else break;

            //number of room
            code = read_number(file, &num, 1, MAX_ROOM, index);
            if (code == OK)
                person[*index].home.dorm.num_room = num;
            else break;
        }
        person[*index].index = *index;
        key[*index].index = *index;
        (*index)++;
        fscanf(file, "\n");
    }
    printf("%d records added\n", *index);
    free(str);
}

void print_table(student *person, keys *key, const int *size, const int by_key)
{
    if (*size <= 0)
    {
        printf("TABLE EMPTY!\n");
        return;
    }
    char sex1[] = "male";
    char sex2[] = "femal";
    char home1[] = "house";
    char home2[] = "dorm";
    printf("\n");
	printf("|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	printf("| No |  family         |  name           |  group          | type of home  | sex     | age  | mark  | date          |      street      | number of house | number of apart | number of hostel | number of room|\n");
	printf("|----|-----------------|-----------------|-----------------|---------------|---------|------|-------|---------------|------------------|-----------------|-----------------|------------------|---------------|\n");

    int index;
	for (int i = 0; i < *size; i++)
	{
		index = i;
		if (by_key == 1)
			index = key[i].index;
		printf("| %2d | %15s | %15s | %15s | %13s | %7s | %4d | %5d | %13s |", i, person[index].family, person[index].name, 
            person[index].group, (person[index].type_home == 0 ? home1 : home2), 
			(person[index].sex == 1 ? sex1 : sex2), person[index].age, person[index].mark, person[index].date);
		if (person[index].type_home == 0)
		{
			printf("%17s | %14d  | %15d |         -        |       -       |", person[index].home.house.street, person[index].home.house.num_house,
				person[index].home.house.num_apartment);
		}
		else
		{
			printf("        -         |        -        |        -        | %16d | %13d |", person[index].home.dorm.num_dorm, person[index].home.dorm.num_room);
		}
		printf("\n");
	}
	printf("|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void add_record_to_table(student *person, keys *key, int *index)
{
    printf("\n");
    int num = 0, code = 0, x, flag = 0;
    char *str;
    str = (char*)malloc(MAX_CHAR_SIZE * sizeof(*str));
    while (1)
    {
        if (*index >= MAX_SIZE)
        {
            printf("TABLE NOW IS FULL!");
            break;
        }
        //if (flag)
        fgetc(stdin); // for a new turn

        //home
        printf("Home (0 - house, 1 - dorm): ");
        code = read_number(stdin, &num, 0, 1, index);
        if (code == OK)
            person[*index].type_home = num;
        else break;

        //family
        printf("Family: ");
        code = read_char(stdin, str, MAX_CHAR_SIZE, index);
        if (code == OK)
            strcpy(person[*index].family, str);
        else break;

        //name
        printf("Name: ");
        code = read_char(stdin, str, MAX_CHAR_SIZE, index);
        if (code == OK)
            strcpy(person[*index].name, str);
        else break;

        //group
        printf("Group: ");
        code = read_char(stdin, str, MAX_CHAR_SIZE, index);
        if (code == OK)
            strcpy(person[*index].group, str);
        else break;

        //sex
        printf("Input sex (0 - female, 1 - male): ");
        code = read_number(stdin, &num, 0, 1, index);
        if (code == OK)
            person[*index].sex = num;
        else break;

        //age
        printf("Input age [18..100]: ");
        code = read_number(stdin, &num, MIN_AGE, MAX_AGE, index);
        if (code == OK)
        {
            person[*index].age = num;
            key[*index].age = num;
        }
        else break;

        //mark
        printf("Mark [0...100]: ");
        code = read_number(stdin, &num, MIN_MARK, MAX_MARK, index);
        if (code == OK)
            person[*index].mark = num;
        else break;

        //data born
        printf("Date (dd.mm.yyyy): ");
        code = read_char(stdin, str, MAX_DATE, index);
        if (code == OK)
            strcpy(person[*index].date, str);
        else break;

        //live in house
        if (person[*index].type_home == 0)
        {
            //street
            printf("Street: ");
            code = read_char(stdin, str, MAX_CHAR_SIZE, index);
            if (code == OK)
                strcpy(person[*index].home.house.street, str);
            else break;

            //number of house
            printf("Number of house: ");
            code = read_number(stdin, &num, 1, MAX_HOME, index);
            if (code == OK)
                person[*index].home.house.num_house = num;
            else break;

            //number of apartment
            printf("Number of apartment: ");
            code = read_number(stdin, &num, 1, MAX_ROOM, index);
            if (code == OK)
                person[*index].home.house.num_apartment = num;
            else break;
        }
        //live in dorm
        else
        {
            //number of dorm
            printf("Number of dorm: ");
            code = read_number(stdin, &num, 1, MAX_HOME, index);
            if (code == OK)
                person[*index].home.dorm.num_dorm = num;
            else break;

            //number of room
            printf("Number of room: ");
            code = read_number(stdin, &num, 1, MAX_ROOM, index);
            if (code == OK)
                person[*index].home.dorm.num_room = num;
            else break;
        }

        person[*index].index = *index;
        key[*index].index = *index;
        (*index)++;
        flag++;

        printf("Add one more record? (1: yes; 0: no): ");
		if ((scanf("%i", &x) == 0) || (x > 1) || (x < 0))
		{
			printf("ERROR!\n");
			break;
		}

		if (x == 0)
			break;
    }
    printf("%d records added!\n", flag);
    free(str);
}

void find_student(student *person,const int *size)
{
    if (*size <= 0)
    {
        printf("\nTABLE EMPTY!\n");
		return;
    }

    int year;
    printf("Input year need find: ");
    if (scanf("%d", &year) != 1)
    {
        printf("ERROR!\n");
        return;
    }
    if (year > 2021 - MIN_AGE|| year < 2021 - MAX_AGE)
    {
        printf("ERROR - WRONG YEAR!\n");
        return;
    }

    char sex1[] = "male";
    char sex2[] = "femal";
    char home2[] = "dorm";

    for (int i = 0; i < *size; i++)
    {
        int temp = 0;
        for (int j = 6; j <= 9; j++)
        {
            temp = temp * 10 + person[i].date[j] - '0';
        }

        if (person[i].type_home == 1 && temp == year)
        {
            printf("\n");
            printf("|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
            printf("| No |  family         |  name           |  group          | type of home  | sex     | age  | date  | year          |      street      | number of house | number of apart | number of hostel | number of room|\n");
            printf("|----|-----------------|-----------------|-----------------|---------------|---------|------|-------|---------------|------------------|-----------------|-----------------|------------------|---------------|\n");
            printf("| %2d | %15s | %15s | %15s | %13s | %7s | %4d | %5d | %13s |", i, person[i].family, person[i].name, person[i].group,
                    home2, (person[i].sex == 1 ? sex1 : sex2), person[i].age, person[i].mark, person[i].date);
            printf("         -        |        -        |        -        | %16d | %13d |", person[i].home.dorm.num_dorm, person[i].home.dorm.num_room);
        }
    }
    printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
void print_key_table(keys *key, const int *size)
{
    if (*size <= 0)
    {
        printf("\nTABLE EMPTY!\n");
		return;
    }
    printf("\n");
	printf("|-----------|-------------|-----------|\n");
	printf("| Key index | Table index |    Age    |\n");
	printf("|-----------|-------------|-----------|\n");

	for (int i = 0; i < *size; i++)
	{
		printf("| %9i | %11i | %9i |\n", i, key[i].index, key[i].age);
		printf("|-----------|-------------|-----------|\n");
	}
}


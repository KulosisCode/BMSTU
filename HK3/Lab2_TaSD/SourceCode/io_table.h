#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>
#include <sys/time.h>


#define MAX_CHAR_SIZE 15
#define MAX_SIZE 50
#define MIN_AGE 18
#define MAX_AGE 100
#define MIN_MARK 0
#define MAX_MARK 100
#define MAX_DATE 11
#define MAX_HOME 100
#define MAX_ROOM 1000
#define NUM_1 1000
#define NUM_2 3000

#define OK 0
#define ERR_DATA -1
#define ERR_EMPTY -2
#define ERR_OPEN -3
#define ERR_OVER_SIZE -4
#define WRONG_DATA -5

typedef struct
{
    char street[MAX_CHAR_SIZE];
    int num_house;
    int num_apartment;
} houses;

typedef struct
{
    int num_dorm;
    int num_room;
} dorms;

typedef union
{
    houses house;
    dorms dorm;
} type_lives;

typedef struct
{
    int type_home;
    char family[MAX_CHAR_SIZE];
    char name[MAX_CHAR_SIZE];
    char group[MAX_CHAR_SIZE];
    int sex;
    int age;
    int mark;
    char date[MAX_CHAR_SIZE];
    int index;
    type_lives home;
} student;

typedef struct
{
    int age;
    int index;
} keys;

void message();

//table
int check_file(FILE *file);
int read_number(FILE *file, int *num, const int min, const int max, const int *index);
int read_char(FILE *file, char *str, int size, const int *index);
void read_from_file(FILE *file, student *person, keys *key, int *index);
void print_table(student *person, keys *key, const int *size, const int by_key);
void add_record_to_table(student *person, keys *key, int *index);
void find_student(student *person,const int *size);
void print_key_table(keys *key, const int *size);

//sort
void buble_sort(student *person, const int size);
void insert_binary_sort(student *person, const int size);
void buble_sort_key(keys *key, const int size);
void insert_binary_sort_key(keys *key, const int size);
void random_table_data(student *person, keys *key, const int size);
void test_sort_table();
#endif
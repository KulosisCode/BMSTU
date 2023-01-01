#ifndef CONST_H
#define CONST_H

#define NAME 30
#define PROD 15
#define N 100
#define OK 0
#define KEY_ERR 53
#define OPEN_FILE_ERR -1
#define EMPTY_FILE -2
#define READ_ERR -3
#define NO -4

struct product
{
	char name[NAME + 3];
	char producer[PROD + 3];
	unsigned int price;
	unsigned int number;
};

#endif
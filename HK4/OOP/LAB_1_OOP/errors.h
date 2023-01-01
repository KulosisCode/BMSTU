#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>

#define OK 0
#define ERR_FILE -1
#define ERR_INPUT -2
#define ERR_MEMORY -3
#define ERR_AMOUNT_POINTS -4
#define ERR_AMOUNT_EDGES -5
#define ERR_ACTION -6
#define ERR_NO_POINT -7
#define ERR_NO_EDGE -8

int print_error(const int &error);

#endif // ERRORS_H


#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>

#define OK 0

#define ERR_FILE -1
#define ERR_INPUT -2
#define ERR_MEMORY -3
#define ERR_PARAM -4
#define ERR_ACTION -5
#define ERR_NO_DATA -6

int print_error(const int &error);
#endif // ERRORS_H

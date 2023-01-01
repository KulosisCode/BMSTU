#include "errors.h"

int print_error(const int& error)
{
    switch (error)
    {
    case ERR_FILE:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при открытии файла.");
        break;
    case ERR_MEMORY:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при выделении памяти.");
        break;
    case ERR_INPUT:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при чтении чисел из файла.");
        break;
    case ERR_PARAM:
        QMessageBox::critical(NULL, "Ошибка", "Неверный параметр.");
        break;
    case ERR_ACTION:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда.");
        break;
    case ERR_NO_DATA:
        QMessageBox::critical(NULL, "Ошибка", "Пустые данные.");
        break;
    }

    return OK;
}

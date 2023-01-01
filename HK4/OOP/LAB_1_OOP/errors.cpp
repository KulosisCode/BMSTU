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
    case ERR_AMOUNT_POINTS:
        QMessageBox::critical(NULL, "Ошибка", "Неверное количество точек в файле."
                                             "Ожидалось не менее 2 точек.");
        break;
    case ERR_AMOUNT_EDGES:
        QMessageBox::critical(NULL, "Ошибка", "Неверное количество линий в файле."
                                              "Ожидалось не менее 1 линии.");
        break;
    case ERR_NO_POINT:
        QMessageBox::critical(NULL, "Ошибка", "Фигура еще не была загружена_(точки).");
        break;
    case ERR_NO_EDGE:
        QMessageBox::critical(NULL, "Ошибка", "Фигура еще не была загружена_(ребро).");
        break;
    case ERR_ACTION:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная команда.");
        break;
    }

    return OK;
}
